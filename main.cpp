#include <iostream>

#include "BigInt.h"

int main() {

    long long num = -12'345'678'990'123'434;
    BigInt bn1(num);
    std::cout << bn1.toString() << std::endl;

    return 0;
}