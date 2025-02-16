// fleet_test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "Personnel.h"   // 包含Personnel人员类的头文件
#include "Ammunition.h"  // 包含Ammunition弹药类的头文件
#include "Weapon.h"      // 包含Weapon武器类的头文件
#include "Ship.h"        // 包含Ship舰船类的头文件
#include "FleetManager.h"// 包含FleetManager舰队管理类的头文件
#include <vector>        // 包含标准库中的 vector 容器，vector类的头文件
#include <memory>        // 包含标准库中的智能指针，shared_ptr类的头文件
#include <iostream>      // 包含标准库中的输入输出流
#include <algorithm>     // 包含标准库中的算法
#include <map>           // 包含标准库中的 map 容器
#include <limits>        // 包含标准库中的 numeric_limits 类

std::vector<std::shared_ptr<Ship>> fleet;           // 创建一个舰队，使用 vector 存储指向 Ship 对象的智能指针
std::map<std::string, std::string> shipLocations;   // 存储舰船位置的映射

void Menu(FleetManager& manager)
{
    int choice;
    do {
        std::cout << "1. Add Ship\n2. Remove Ship\n3. Query Ship\n4. Display All Ships\n5. Move Ship\n6. Exit\nEnter your choice: ";
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清空输入缓冲区

        enum MenuChoice {
            AddShip = 1,
            RemoveShip = 2,
            QueryShip = 3,
            DisplayAllShips = 4,
            MoveShip = 5,
            Exit = 6
        };

        switch (choice) {
        case AddShip:
            manager.addShip();
            break;
        case RemoveShip:
            manager.removeShip();
            break;
        case QueryShip:
            manager.queryShip();
            break;
        case DisplayAllShips:
            manager.showFleet();
            for (const auto& ship : fleet) {
                ship->displayInfo();
                ship->status();
                std::cout << "Location: " << shipLocations.at(ship->getName()) << "\n";
                std::cout << "-----------------------------------------------\n";
            }
            break;
        case MoveShip:
            manager.moveShip();
            break;
        case Exit:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

int main() {
    FleetManager manager;

    // 添加示例舰船
    auto ship1 = std::make_shared<Ship>("USS Enterprise", 1961, 93000, "342m x 78m", "Nuclear", 50);
    ship1->addPersonnel(std::make_shared<Personnel>("John Doe", "Captain"));
    ship1->addWeapon(std::make_shared<Weapon>("Cannon", 100));
    ship1->addAmmunition(std::make_shared<Ammunition>("Cannonball", 500));
    manager.addShip(ship1, "Port A");

    auto ship2 = std::make_shared<Ship>("辽宁舰", 1988, 67000, "304m x 70m", "Conventional", 30);
    ship2->addPersonnel(std::make_shared<Personnel>("张三", "舰长"));
    ship2->addWeapon(std::make_shared<Weapon>("海红旗", 10));
    ship2->addAmmunition(std::make_shared<Ammunition>("导弹", 30));
    manager.addShip(ship2, "Port B");

    auto ship3 = std::make_shared<Ship>("Bismarck", 1939, 50000, "251m x 36m", "Diesel", 8);
    ship3->addPersonnel(std::make_shared<Personnel>("Max Mustermann", "Gunner"));
    ship3->addWeapon(std::make_shared<Weapon>("Torpedo", 10));
    ship3->addAmmunition(std::make_shared<Ammunition>("Torpedo", 20));
    manager.addShip(ship3, "Port C");

    // 启动菜单
    manager.showFleet();
    Menu(manager);

    return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
