#include "parking.h"

int main() {
    int choice;
    while (true) {
        std::cout << "\nPARKING MANAGEMENT SYSTEM";
        std::cout << "\n1. Add Vehicle";
        std::cout << "\n2. Show Records";
        std::cout << "\n3. Exit Vehicle";
        std::cout << "\n4. Exit Program";
        std::cout << "\nEnter Choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1: addVehicle(); break;
            case 2: showRecords(); break;
            case 3: exitVehicle(); break;
            case 4: std::cout << "\nExiting Program...\n"; return 0;
            default: std::cout << "\nInvalid Choice!\n";
        }
    }
    return 0;
}


/*#include <iostream>
#include "parking.h"

using namespace std;

int main() {
    int car = 0, bike = 0, three = 0, bus = 0;
    
    while (true) {
        int enter;
        cout << "\n\nCAR PARKING SYSTEM";
        cout << "\nPress 1: for adding a Car";
        cout << "\nPress 2: for adding a Bike";
        cout << "\nPress 3: for adding a Three Wheeler";
        cout << "\nPress 4: for adding a Bus";
        cout << "\nPress 5: to show all records";
        cout << "\nPress 6: to delete all records";
        cout << "\nPress 7: to calculate the Tax";
        cout << "\nPress 8: Exit";
        cout << "\nEnter your choice: ";
        cin >> enter;

        switch (enter) {
            case 1: addVehicle(car, "Car"); break;
            case 2: addVehicle(bike, "Bike"); break;
            case 3: addVehicle(three, "Three Wheeler"); break;
            case 4: addVehicle(bus, "Bus"); break;
            case 5: showRecords(car, bike, three, bus); break;
            case 6: deleteRecords(car, bike, three, bus); break;
            case 7: {
                int vehicle, hours;
                cout << "\nEnter the vehicle type (1: Car, 2: Bike, 3: Three Wheeler, 4: Bus): ";
                cin >> vehicle;
                cout << "\nEnter the number of hours parked: ";
                cin >> hours;

                int tax = calculateTax(vehicle, hours);
                if (tax == -1)
                    cout << "\nInvalid vehicle type!";
                else
                    cout << "\nTotal Tax Amount: Rs. " << tax;
                break;
            }
            case 8:
                cout << "\nExiting program...\n";
                return 0;
            default:
                cout << "\nInvalid choice! Please enter a valid option.\n";
        }
    }
    return 0;
} */
