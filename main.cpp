#include <iostream>

#include "BigInt.h"

int main() {

    long long num = -12'345'678'990'123'434;
    BigInt bn1(num);
    std::cout << bn1.toString() << std::endl;


    BigInt bn2("-987654123456789123456789123456789");
    std::cout << bn2.toString() << std::endl;

    BigInt bn3;
    std::cin >> bn3;

    std::cout << bn3 << std::endl;

    return 0;
}