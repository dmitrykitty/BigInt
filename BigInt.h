#ifndef BIGINT_H
#define BIGINT_H
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <iostream>


class BigInt {
    static constexpr int BASE = 1'000'000'000;
    static constexpr int MAX_DIGITS = 9;
    std::vector<int> digits_{0};
    bool isNegative{false};

public:
    //Constructors
    BigInt() = default;
    BigInt(long long other);
    BigInt(const std::string& other);

    [[nodiscard]] std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const BigInt& other);
    friend std::istream& operator>>(std::istream& is, BigInt& other);
};


#endif //BIGINT_H
