#include "FleetManager.h"
#include <iostream>
#include <algorithm>
#include <limits>

void FleetManager::clearInputBuffer() const {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // 清空输入缓冲区
}

template <typename T>
T FleetManager::getInput(const std::string& prompt) const {
    T value;
    std::cout << prompt;
    std::cin >> value;
    clearInputBuffer();  // 清空输入缓冲区
    return value;
}
//创建一个 getInput 辅助函数，专门处理用户输入，避免重复代码

void FleetManager::addShip() {
    std::string name, size, propulsion, location;
    int yearBuilt, serviceTime, mobility;
    double displacement;

    name = getInput<std::string>("Enter ship name: ");
    yearBuilt = getInput<int>("Enter year built: ");
    displacement = getInput<double>("Enter displacement (tons): ");
    size = getInput<std::string>("Enter size: ");
    propulsion = getInput<std::string>("Enter propulsion: ");
    serviceTime = getInput<int>("Enter service time (years): ");
    mobility = getInput<int>("Enter mobility (knots): ");
    location = getInput<std::string>("Enter initial location: ");

    auto ship = std::make_shared<Ship>(name, yearBuilt, displacement, size, propulsion, serviceTime, mobility);
    fleet.push_back(ship);
    shipLocations[name] = location;
    std::cout << "-------------------------------------------------\n";
}

void FleetManager::addShip(const std::shared_ptr<Ship>& ship, const std::string& location) {
    fleet.push_back(ship);
    shipLocations[ship->getName()] = location;
}

void FleetManager::removeShip() {
    std::string name = getInput<std::string>("Enter the name of the ship to remove: ");

    auto it = std::remove_if(fleet.begin(), fleet.end(), [&name](const std::shared_ptr<Ship>& ship) {
        return ship->getName() == name;
        });

    if (it != fleet.end()) {
        fleet.erase(it, fleet.end());
        shipLocations.erase(name);
        std::cout << "Ship removed successfully.\n";
    }
    else {
        std::cout << "Ship not found.\n";
    }
    std::cout << "-----------------------------------------------\n";
}

void FleetManager::queryShip() const {
    std::string name = getInput<std::string>("Enter the name of the ship to query: ");

    auto it = std::find_if(fleet.begin(), fleet.end(), [&name](const std::shared_ptr<Ship>& ship) {
        return ship->getName() == name;
        });

    if (it != fleet.end()) {
        (*it)->displayInfo();
        std::cout << "Location: " << shipLocations.at(name) << "\n";
    }
    else {
        std::cout << "Ship not found.\n";
    }
    std::cout << "-----------------------------------------------\n";
}

void FleetManager::showFleet() const {
    for (const auto& ship : fleet) {
        ship->displayInfo();
        ship->status();
        std::cout << "Location: " << shipLocations.at(ship->getName()) << "\n";
        std::cout << "-----------------------------------------------\n";
    }
}

void FleetManager::moveShip() {
    std::string name = getInput<std::string>("Enter the name of the ship to move: ");
    std::string newLocation = getInput<std::string>("Enter the new location: ");

    auto it = std::find_if(fleet.begin(), fleet.end(), [&name](const std::shared_ptr<Ship>& ship) {
        return ship->getName() == name;
        });

    if (it != fleet.end()) {
        shipLocations[name] = newLocation;
        std::cout << "Ship moved successfully.\n";
    }
    else {
        std::cout << "Ship not found.\n";
    }
    std::cout << "-----------------------------------------------\n";
}
