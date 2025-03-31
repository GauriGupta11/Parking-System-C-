#include "parking.h"
#include <fstream>

std::vector<Vehicle> parkedVehicles;
const int MAX_SLOTS = 50;
int occupiedSlots = 0;

void addVehicle() {
    if (occupiedSlots >= MAX_SLOTS) {
        std::cout << "\nParking Full! No available slots.\n";
        return;
    }
    
    Vehicle v;
    std::cout << "\nEnter Vehicle Number Plate: ";
    std::cin >> v.numberPlate;
    v.entryTime = time(0);
    parkedVehicles.push_back(v);
    occupiedSlots++;

    std::ofstream file("database.txt", std::ios::app);
    file << v.numberPlate << " " << v.entryTime << "\n";
    file.close();
    
    std::cout << "\nVehicle Added Successfully!\n";
}

void showRecords() {
    if (parkedVehicles.empty()) {
        std::cout << "\nNo Vehicles in Parking.\n";
        return;
    }
    std::cout << "\nCurrently Parked Vehicles:\n";
    for (auto &v : parkedVehicles) {
        std::cout << "Number Plate: " << v.numberPlate << " | Entry Time: " << ctime(&v.entryTime);
    }
}

void exitVehicle() {
    std::string plate;
    std::cout << "\nEnter Vehicle Number Plate: ";
    std::cin >> plate;
    
    for (auto it = parkedVehicles.begin(); it != parkedVehicles.end(); ++it) {
        if (it->numberPlate == plate) {
            time_t exitTime = time(0);
            double hours = difftime(exitTime, it->entryTime) / 3600;
            int fee = (hours <= 3) ? hours * 50 : 150 + (hours - 3) * 60;
            
            std::cout << "\nVehicle " << plate << " has exited. Total Fee: Rs." << fee << "\n";
            parkedVehicles.erase(it);
            occupiedSlots--;
            return;
        }
    }
    std::cout << "\nVehicle Not Found!\n";
}



/*#include <iostream>
#include "parking.h"

using namespace std;

void addVehicle(int &count, const char* type) {
    count++;
    cout << "\n" << type << " successfully added.\n";
}

void showRecords(int car, int bike, int three, int bus) {
    cout << "\nCar Count: " << car;
    cout << "\nBike Count: " << bike;
    cout << "\nThree Wheeler Count: " << three;
    cout << "\nBus Count: " << bus << endl;
}

void deleteRecords(int &car, int &bike, int &three, int &bus) {
    car = bike = three = bus = 0;
    cout << "\nAll records deleted successfully.\n";
}

int calculateTax(int vehicleType, int hours) {
    int amount = 0;
    switch (vehicleType) {
        case 1: // Car
            amount = (hours <= 3) ? hours * 50 : (hours <= 5) ? 150 + (hours - 3) * 60 : 150 + 120 + (hours - 5) * 70;
            break;
        case 2: // Bike
            amount = (hours <= 3) ? hours * 40 : (hours <= 5) ? 120 + (hours - 3) * 50 : 120 + 100 + (hours - 5) * 60;
            break;
        case 3: // Three Wheeler
            amount = (hours <= 3) ? hours * 50 : (hours <= 5) ? 150 + (hours - 3) * 60 : 150 + 120 + (hours - 5) * 65;
            break;
        case 4: // Bus
            amount = (hours <= 3) ? hours * 70 : (hours <= 5) ? 210 + (hours - 3) * 80 : 210 + 160 + (hours - 5) * 100;
            break;
        default:
            return -1; // Invalid vehicle type
    }
    return amount;
}
*/

