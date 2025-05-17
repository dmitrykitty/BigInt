//
// Created by Lenovo on 17/05/2025.
//

#include "BigInt.h"

std::string BigInt::toString() const {
    std::string res;
    if (isNegative)
        res = "-";

    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        res += std::to_string(*it);
    }
    return res;
}
