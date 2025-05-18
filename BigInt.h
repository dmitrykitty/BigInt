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
    bool isNegative_{false};

public:
    //Constructors
    BigInt() = default;
    BigInt(long long other);
    BigInt(const std::string& other);
    BigInt(const BigInt& other);

    [[nodiscard]] std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const BigInt& other);
    friend std::istream& operator>>(std::istream& is, BigInt& other);

    BigInt& operator=(BigInt other);
    std::strong_ordering operator<=>(const BigInt& other) const;
    bool operator==(const BigInt& other) const;

    BigInt& operator+=(const BigInt& other);

    BigInt operator+(const BigInt& other);

private:
    void swap(BigInt& other);
    int absCompare(const BigInt& other) const;
    void absSum(const BigInt& other);
};


#endif //BIGINT_H
