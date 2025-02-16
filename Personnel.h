#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <string>
//#include <vector>
//#include <memory>
#include <iostream>

class Personnel {
public:
    Personnel(const std::string& name, const std::string& rank)
        : name(name), rank(rank) {
    }

    void displayInfo() const {
        std::cout << "Name: " << name << ", Rank: " << rank << std::endl;
    }

private:
    std::string name;
    std::string rank;
    //std::string type;
    //int quantity;
};

#endif // PERSONNEL_H

//class Weapon {
//public:
//    Weapon(const std::string& name, int ammoCount)
//        : name(name), ammoCount(ammoCount) {}
//
//    void displayInfo() const {
//        std::cout << "Weapon: " << name << ", Ammo Count: " << ammoCount << std::endl;
//    }
//
//private:
//    std::string name;
//    int ammoCount;
//};
//
//class Ammunition {
//public:
//    Ammunition(const std::string& type, int quantity)
//        : type(type), quantity(quantity) {}
//
//    void displayInfo() const {
//        std::cout << "Ammunition Type: " << type << ", Quantity: " << quantity << std::endl;
//    }

//private:
//    std::string type;
//    int quantity;
//};