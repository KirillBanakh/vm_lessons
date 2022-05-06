#include "bus_station_infocenter.h"

#include <iostream>

using namespace std;

const struct {
	eBusTypes_t bus_type;
	char bus_type_name[64];
} bus_types[]{
	{eEcolines,  "Ecolines"},
	{eEurolines, "Eurolines"}
};

const struct {
	eDestinations_t destination;
	char destination_name[64];
} destinations[]{
	{eMachulishi, "Machulishi"},
	{ePapernya,   "Papernya"  },
	{ePruzhani,   "Pruzhani"  },
};

sBus Get_Random_Bus() {
	sBus bus;
	
	bus.bus_type = bus_types[rand() % eBusTypes_Last].bus_type;
	
	bus.departure_time.tm_hour = rand() % 23;
	bus.departure_time.tm_min = rand() % 59;

	do {
		bus.arrival_time.tm_hour = rand() % 23;
		bus.arrival_time.tm_min = rand() % 59;
	}
	while (bus.departure_time.tm_hour >= bus.arrival_time.tm_hour || 
		  (bus.departure_time.tm_hour == bus.arrival_time.tm_hour &&
		   bus.departure_time.tm_min > bus.arrival_time.tm_min));

	return bus;
}

void Print_Bus_Info(sBus bus) {
	cout << "Bus Type:      " << bus_types[bus.bus_type].bus_type_name << endl;
	cout << "Depature Time: " << bus.departure_time.tm_hour << ":" << bus.departure_time.tm_min << endl;
	cout << "Arrival Time:  " << bus.arrival_time.tm_hour << ":" << bus.arrival_time.tm_min << endl;
}

void Generate_Random_Bus_Schedule(sBusSchedule *bus_schedule, int size) {
	bus_schedule->size = size;

	for (int i = 0; i < bus_schedule->size; i++) {
		bus_schedule->buses[i] = Get_Random_Bus();
	}

	sBus temp;

	for (int i = 0; i < bus_schedule->size; i++) {
		for (int j = i + 1; j < bus_schedule->size; j++) {
			if ((bus_schedule->buses[j].arrival_time.tm_hour == bus_schedule->buses[i].arrival_time.tm_hour &&
				 bus_schedule->buses[j].arrival_time.tm_min  <  bus_schedule->buses[i].arrival_time.tm_min) ||
				 bus_schedule->buses[j].arrival_time.tm_hour <  bus_schedule->buses[i].arrival_time.tm_hour) {

				temp = bus_schedule->buses[i];
				bus_schedule->buses[i] = bus_schedule->buses[j];
				bus_schedule->buses[j] = temp;
			}
		}
	}

	for (int i = 0; i < bus_schedule->size; i++) {
		bus_schedule->buses[i].trip_number = i + 1;
	}
}

void Print_Bus_Schedule(sBusSchedule bus_schedule) {
	char time_buffer[6];

	cout << endl << "##################################" << endl;
	cout <<         "Destination: " << destinations[bus_schedule.destination].destination_name << endl;
	cout <<         "##################################" << endl;
	for (int i = 0; i < bus_schedule.size; i++) {
		cout << "\nTrip Number:   " << bus_schedule.buses[i].trip_number << endl;

		cout << "Bus Type:      " << bus_types[bus_schedule.buses[i].bus_type].bus_type_name << endl;

		strftime(time_buffer, sizeof(time_buffer), "%R", &bus_schedule.buses[i].departure_time);
		cout << "Depature Time: " << time_buffer << endl;

		strftime(time_buffer, sizeof(time_buffer), "%R", &bus_schedule.buses[i].arrival_time);
		cout << "Arrival Time:  " << time_buffer << endl;
	}
	cout << "-----------------" << endl;
}

void Print_Destinations(sBusSchedule bus_schedule[], int size) {
	cout << endl << "##################################" << endl;
	cout <<         "Available Destinations: " << endl;
	cout <<         "##################################" << endl;

	for (int i = 0; i < size; i++) {
		cout << "[" << i << "]: " << destinations[bus_schedule[i].destination].destination_name << endl;
	}
}

void List_Suitable_Buses(sBusSchedule bus_schedule, tm time) {
	char time_buffer[6];

	cout << endl << "##################################" << endl;
	cout <<         "Suitable Buses: " << endl;
	cout <<         "##################################" << endl;
	for (int i = 0; i < bus_schedule.size; i++) {
		if ((bus_schedule.buses[i].arrival_time.tm_hour == time.tm_hour &&
			 bus_schedule.buses[i].arrival_time.tm_min > time.tm_min)   ||
			bus_schedule.buses[i].arrival_time.tm_hour > time.tm_hour) {
			cout << "\nTrip Number:   " << bus_schedule.buses[i].trip_number << endl;

			cout << "Bus Type:      " << bus_types[bus_schedule.buses[i].bus_type].bus_type_name << endl;

			strftime(time_buffer, sizeof(time_buffer), "%R", &bus_schedule.buses[i].departure_time);
			cout << "Depature Time: " << time_buffer << endl;

			strftime(time_buffer, sizeof(time_buffer), "%R", &bus_schedule.buses[i].arrival_time);
			cout << "Arrival Time:  " << time_buffer << endl;
		}
	}
}