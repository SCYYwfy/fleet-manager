#ifndef FLEETMANAGER_H
#define FLEETMANAGER_H

#include "Ship.h"
#include <vector>
#include <memory>
#include <map>
#include <string>

class FleetManager {
public:
    void addShip();
    void addShip(const std::shared_ptr<Ship>& ship, const std::string& location);
    void removeShip();
    void queryShip() const;
    void showFleet() const;
    void moveShip();

private:
    std::vector<std::shared_ptr<Ship>> fleet;
    std::map<std::string, std::string> shipLocations;

    // Helper function for clearing input buffer
    void clearInputBuffer() const;
    // Helper function for getting input
    template <typename T>
    T getInput(const std::string& prompt) const;
};

#endif // FLEETMANAGER_H
