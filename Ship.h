#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "Personnel.h"
#include "Weapon.h"
#include "Ammunition.h"

class Ship {
public:
    // 为 mobility 提供默认值
    Ship(const std::string& name, int yearBuilt, double displacement, const std::string& size, const std::string& propulsion, int serviceTime, int mobility = 0);
    ~Ship();

    void status() const;
    void displayInfo() const;
    void addPersonnel(const std::shared_ptr<Personnel>& personnel);
    void addWeapon(const std::shared_ptr<Weapon>& weapon);
    void addAmmunition(const std::shared_ptr<Ammunition>& ammunition);

    int getTotalPersonnel() const;
    std::string getName() const;

private:
    std::string name;
    int yearBuilt;
    double displacement;
    std::string size;
    std::string propulsion;
    int serviceTime;
    int mobility;

    std::vector<std::shared_ptr<Personnel>> crew;
    std::vector<std::shared_ptr<Weapon>> weapons;
    std::vector<std::shared_ptr<Ammunition>> ammunitions;
};

#endif // SHIP_H
