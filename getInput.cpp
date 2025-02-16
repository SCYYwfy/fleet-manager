#include<iostream>

template <typename T>
T getInput(const std::string& prompt) {
    T value;
    std::cout << prompt;
    std::cin >> value;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ������뻺����
    return value;
}