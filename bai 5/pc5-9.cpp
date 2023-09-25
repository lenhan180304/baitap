#include <iostream>
#include <iomanip>

int main() {
    int numFloors;
    int totalRooms = 0;
    int totalOccupied = 0;

    std::cout << "Enter the number of floors in the hotel: ";
    std::cin >> numFloors;

    if (numFloors < 1) {
        std::cout << "Invalid input. Please enter a number of floors greater than or equal to 1." << std::endl;
        return 1;
    }

    for (int floor = 1; floor <= numFloors; ++floor) {
        if (floor == 13) {
            // Skip the 13th floor as per the tradition
            continue;
        }

        int numRoomsOnFloor, numOccupied;
        std::cout << "Enter the number of rooms on floor " << floor << ": ";
        std::cin >> numRoomsOnFloor;

        if (numRoomsOnFloor < 10) {
            std::cout << "Invalid input. Each floor must have at least 10 rooms." << std::endl;
            return 1;
        }

        std::cout << "Enter the number of occupied rooms on floor " << floor << ": ";
        std::cin >> numOccupied;

        totalRooms += numRoomsOnFloor;
        totalOccupied += numOccupied;
    }

    double occupancyRate = (static_cast<double>(totalOccupied) / totalRooms) * 100;

    std::cout << "Total number of rooms in the hotel: " << totalRooms << std::endl;
    std::cout << "Total number of occupied rooms: " << totalOccupied << std::endl;
    std::cout << "Total number of unoccupied rooms: " << (totalRooms - totalOccupied) << std::endl;
    std::cout << "Occupancy rate: " << std::fixed << std::setprecision(2) << occupancyRate << "%" << std::endl;

    return 0;
}
