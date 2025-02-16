#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class Weapon {
public:
    Weapon(const std::string& name, int ammoCount)
        : name(name), ammoCount(ammoCount) {
    }

    void displayInfo() const {
        std::cout << "Weapon: " << name << ", Ammo Count: " << ammoCount << std::endl;
    }

private:
    std::string name;
    int ammoCount;
};

#endif // WEAPON_H