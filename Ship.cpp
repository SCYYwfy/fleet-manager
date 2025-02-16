#include "Ship.h"
#include <iostream>

Ship::Ship(const std::string& name, int yearBuilt, double displacement, const std::string& size, const std::string& propulsion, int serviceTime, int mobility)
    : name(name), yearBuilt(yearBuilt), displacement(displacement), size(size), propulsion(propulsion), serviceTime(serviceTime), mobility(mobility) {
}

Ship::~Ship() {}

void Ship::status() const {
    std::cout << "Ship " << name << " is ready!" << std::endl;
}

void Ship::displayInfo() const {
    std::cout << "Ship: " << name << ", Year: " << yearBuilt << std::endl;
    std::cout << "Displacement: " << displacement << " tons" << std::endl;
    std::cout << "Size: " << size << std::endl;
    std::cout << "Propulsion: " << propulsion << std::endl;
    std::cout << "Service Time: " << serviceTime << " years" << std::endl;
    std::cout << "Mobility: " << mobility << std::endl;

    std::cout << "Crew:" << std::endl;
    for (const auto& person : crew) {
        person->displayInfo();
    }

    std::cout << "Weapons:" << std::endl;
    for (const auto& weapon : weapons) {
        weapon->displayInfo();
    }

    std::cout << "Ammunitions:" << std::endl;
    for (const auto& ammo : ammunitions) {
        ammo->displayInfo();
    }
}

void Ship::addPersonnel(const std::shared_ptr<Personnel>& personnel) {
    crew.push_back(personnel);
}

void Ship::addWeapon(const std::shared_ptr<Weapon>& weapon) {
    weapons.push_back(weapon);
}

void Ship::addAmmunition(const std::shared_ptr<Ammunition>& ammunition) {
    ammunitions.push_back(ammunition);
}

int Ship::getTotalPersonnel() const {
    return static_cast<int>(crew.size());
}

std::string Ship::getName() const {
    return name;
}
