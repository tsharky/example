#include "Example.hpp"

#include <iostream>

bool isTrue(const std::string &msg) {
    std::cout << msg << std::endl;
    return true;
}

int Square(int x) {
    return x * x;
}

int MAC(int x, int y, int &sum) {
    sum += x * y;
    return sum;
}