#include <iostream>
#include <ctime>
#include "bus_station_infocenter.h"

using namespace std;

int main()
{
    FILE* bus_schedule_file = NULL;

    sBusSchedule bus_schedule[eDestinations_Last];
    int destination;
    tm arrival_time;
    char* arrival_time_pointer;
    char arrival_time_buffer[6];

    bus_schedule[0].destination = eMachulishi;
    bus_schedule[1].destination = ePapernya;
    bus_schedule[2].destination = ePruzhani;

    Generate_Random_Bus_Schedule(&bus_schedule[0], 10);
    Generate_Random_Bus_Schedule(&bus_schedule[1], 10);
    Generate_Random_Bus_Schedule(&bus_schedule[2], 10);

    Create_Bus_Schedule_File(bus_schedule_file);

    Save_Bus_Schedule_To_File(bus_schedule_file, bus_schedule[0], 10);
    Save_Bus_Schedule_To_File(bus_schedule_file, bus_schedule[1], 10);
    Save_Bus_Schedule_To_File(bus_schedule_file, bus_schedule[2], 10);

    Print_Bus_Schedule(bus_schedule[0]);
    Print_Bus_Schedule(bus_schedule[1]);
    Print_Bus_Schedule(bus_schedule[2]);

    Print_Destinations(bus_schedule, eDestinations_Last);
    
    cout << endl << "Choose your Destination: ";
    cin >> destination;

    cout << endl << "Enter arrival time in hh:mm format: ";
    cin >> arrival_time_buffer;

    arrival_time.tm_hour = strtol(arrival_time_buffer, &arrival_time_pointer, 0);
    arrival_time.tm_min = strtol(arrival_time_pointer + 1, &arrival_time_pointer, 0);

    List_Suitable_Buses(bus_schedule[destination], arrival_time);

    return 0;
}