//
// Created by Lenovo on 17/05/2025.
//

#include "BigInt.h"

//Constructors

BigInt::BigInt(long long other) {
    digits_.clear();
    unsigned long long tmp;
    if (other < 0) {
        isNegative_ = true;
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
        isNegative_ = true;
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

BigInt::BigInt(const BigInt& other) {
    digits_.reserve(other.digits_.size());
    for (int i = 0; i < digits_.size(); ++i)
        digits_[i] = other.digits_[i];

    isNegative_ = other.isNegative_;
}


std::string BigInt::toString() const {
    std::string res;
    if (isNegative_)
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

BigInt& BigInt::operator=(BigInt other) {
    swap(other);
    return *this;
}

void BigInt::swap(BigInt& other) noexcept {
    std::swap(isNegative_, other.isNegative_);
    std::swap(digits_, other.digits_);
}

int BigInt::absCompare(const BigInt& other) const {
    if (digits_.size() != other.digits_.size())
        return digits_.size() > other.digits_.size() ? 1 : -1;

    for (int i = digits_.size() - 1; i >= 0; --i) {
        if (digits_[i] != other.digits_[i])
            return digits_[i] > other.digits_[i] ? 1 : -1;
    }
    return 0;
}

std::strong_ordering BigInt::operator<=>(const BigInt& other) const {
    if (isNegative_ != other.isNegative_) {
        return isNegative_
                   ? std::strong_ordering::less
                   : std::strong_ordering::greater;
    }

    int res = absCompare(other);
    if (res == 0)
        return std::strong_ordering::equal;

    if (!isNegative_)
        return res < 0
                   ? std::strong_ordering::less
                   : std::strong_ordering::greater;

    return res < 0
               ? std::strong_ordering::greater
               : std::strong_ordering::less;
}

bool BigInt::operator==(const BigInt& other) const {
    return *this <=> other == std::strong_ordering::equal;
}

void BigInt::absSum(const BigInt& other) {
    long long carry = 0;
    size_t len1 = digits_.size();
    size_t len2 = other.digits_.size();
    size_t max_length = std::max(len1, len2);
    std::vector<int> result(max_length);

    for (int i = 0; i < max_length; ++i) {
        long long sum = carry
                        + (i < len1 ? digits_[i] : 0)
                        + (i < len2 ? other.digits_[i] : 0);

        if (sum >= BASE) {
            result[i] = static_cast<int>(sum % BASE);
            carry = sum / BASE;
        } else {
            result[i] = sum;
            carry = 0;
        }
    }
    if (carry) {
        result.push_back(carry);
    }
    digits_ = std::move(result);
}

void BigInt::absSubtract(const BigInt& other) {
    long long borrow = 0;
    size_t len1 = digits_.size();
    size_t len2 = other.digits_.size();
    size_t max_length = std::max(len1, len2);
    std::vector<int> result(max_length);

    for (int i = 0; i < max_length - 1; ++i) {
        long long difference = (i < len1 ? digits_[i] : 0) - (i < len2 ? other.digits_[i] : 0);

            result[i] = difference
            carry = sum / BASE;
        } else {
            result[i] = sum;
            carry = 0;
        }
    }

    if (*this > other) {}
}


BigInt& BigInt::operator+=(const BigInt& other) {
    if (isNegative_ == other.isNegative_) {
        absSum(other);
        return *this;
    }
}

BigInt BigInt::operator+(const BigInt& other) {}
