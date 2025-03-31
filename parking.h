#ifndef PARKING_H
#define PARKING_H

#include <iostream>
#include <vector>
#include <ctime>

struct Vehicle {
    std::string numberPlate;
    time_t entryTime;
};

void addVehicle();
void showRecords();
void exitVehicle();

/*void addVehicle(int &count, const char* type);
void showRecords(int car, int bike, int three, int bus);
void deleteRecords(int &car, int &bike, int &three, int &bus);
int calculateTax(int vehicleType, int hours);*/

#endif
