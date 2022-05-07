#pragma once

#include <stdio.h>
#include <ctime>

#define MAX_BUSES_PER_ROUTE 64

typedef enum eBusTypes_t {
	eEcolines,
	eEurolines,
	eBusTypes_Last
};

typedef enum eDestinations_t {
	eMachulishi,
	ePapernya,
	ePruzhani,
	eDestinations_Last
};

struct sBus {
	int trip_number = 0;
	eBusTypes_t bus_type;
	tm departure_time;
	tm arrival_time;
}; 

struct sBusSchedule {
	eDestinations_t destination;
	int size;
	sBus buses[MAX_BUSES_PER_ROUTE];
};

sBus Get_Random_Bus();
void Print_Bus_Info(sBus bus);

void Generate_Random_Bus_Schedule(sBusSchedule* bus_schedule, int size);

void Create_Bus_Schedule_File(FILE* file);
void Save_Bus_Schedule_To_File(FILE* file, sBusSchedule bus_schedule, int size);

void Print_Bus_Schedule(sBusSchedule bus_schedule);
void Print_Destinations(sBusSchedule bus_schedule[], int size);

void List_Suitable_Buses(sBusSchedule bus_schedule, tm time);