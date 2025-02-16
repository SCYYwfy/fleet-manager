#ifndef AMMUNITION_H
#define AMMUNITION_H

#include <string>
#include <iostream>

class Ammunition {
public:
    Ammunition(const std::string& type, int quantity)
        : type(type), quantity(quantity) {
    }

    void displayInfo() const {
        std::cout << "Ammunition Type: " << type << ", Quantity: " << quantity << std::endl;
    }

private:
    std::string type;
    int quantity;
};

#endif // AMMUNITION_H
