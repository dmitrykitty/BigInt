//
// Created by Lenovo on 17/05/2025.
//

#include "BigInt.h"

//Constructors

BigInt::BigInt(long long other) {
    digits_.clear();
    unsigned long long tmp;
    if (other < 0) {
        isNegative = true;
        tmp = std::abs(other);
    } else {
        tmp = other;
    }

    do {
        digits_.push_back(static_cast<int>(tmp % BASE));
        tmp = tmp / BASE;
    } while (tmp);
}

BigInt::BigInt(const std::string& other) {
    digits_.clear();
    std::string tmp = other;

    if (other[0] == '-') {
        isNegative = true;
        tmp.erase(tmp.begin());
    }

    int digitCount = tmp.size() / MAX_DIGITS;
    int firstNChars = tmp.size() % MAX_DIGITS;

    if (firstNChars)
        digits_.reserve(digitCount + 1);
    else
        digits_.reserve(digitCount);


    for (int i = 1; i <= digitCount; ++i) {
        int left = tmp.size() - i * MAX_DIGITS;
        std::string digitSubstr;
        digitSubstr = tmp.substr(left, MAX_DIGITS);
        digits_.push_back(std::stoi(digitSubstr));
    }

    if (firstNChars)
        digits_.push_back(std::stoi(tmp.substr(0, firstNChars)));
}


std::string BigInt::toString() const {
    std::string res;
    if (isNegative)
        res = "-";

    for (auto it = digits_.rbegin(); it != digits_.rend(); ++it) {
        res += std::to_string(*it);
    }
    return res;
}


std::ostream& operator<<(std::ostream& os, const BigInt& other) {
    os << other.toString();
    return os;
}

std::istream& operator>>(std::istream& is, BigInt& other) {
    std::string tmp;
    if (!(is >> tmp))
        return is;
    other = BigInt(tmp);
    return is;
}