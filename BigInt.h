//
// Created by Lenovo on 17/05/2025.
//

#ifndef BIGINT_H
#define BIGINT_H
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <iostream>


class BigInt {
    static constexpr int BASE = 1'000'000'000;
    std::vector<int> digits{0};
    bool isNegative{false};

public:
    BigInt() = default;

    BigInt(long long other) {
        digits.clear();
        unsigned long long tmp;
        if (other < 0) {
            isNegative = true;
            tmp = std::abs(other);
        } else {
            tmp = other;
        }


        do {
            digits.push_back(tmp % BASE);
            tmp = tmp / BASE;
        } while (tmp);
    }

    [[nodiscard]] std::string toString() const;
};


#endif //BIGINT_H
