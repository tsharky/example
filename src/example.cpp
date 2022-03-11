#include "example/example.hpp"
#include "utility/erroror.h"

#include <iostream>

ErrorOr<bool> isTrueOrError() {
    return {0, true};
}

bool isTrue(const std::string &msg) {
    std::cout << msg << std::endl;
    return isTrueOrError().isOk();
}

int Square(int x) {
    return x * x;
}

int MAC(int x, int y, int &sum) {
    sum += x * y;
    return sum;
}
