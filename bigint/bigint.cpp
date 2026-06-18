#include "bigint.hpp"
#include <algorithm>

// --------------------------------------------------
// remove leading zeros
// --------------------------------------------------

void bigint::remove_leading_zeros()
{
    size_t pos = value.find_first_not_of('0');

    if (pos == std::string::npos)
        value = "0";
    else
        value.erase(0, pos);
}

// --------------------------------------------------
// constructors
// --------------------------------------------------

bigint::bigint()
    : value("0")
{
}

bigint::bigint(unsigned long long num)
    : value(std::to_string(num))
{
}

bigint::bigint(const bigint& other)
    : value(other.value)
{
}

bigint::bigint(const std::string& str)
    : value(str)
{
    remove_leading_zeros();
}

// --------------------------------------------------
// assignment
// --------------------------------------------------

bigint& bigint::operator=(const bigint& other)
{
    if (this != &other)
        value = other.value;

    return *this;
}

// --------------------------------------------------
// addition
// --------------------------------------------------

bigint bigint::operator+(const bigint& other) const
{
    std::string result;

    int i = (int)value.size() - 1;
    int j = (int)other.value.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if (i >= 0)
            sum += value[i--] - '0';
        if (j >= 0)
            sum += other.value[j--] - '0';

        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    std::reverse(result.begin(), result.end());
    return bigint(result);
}

// --------------------------------------------------
// +=
// --------------------------------------------------

bigint& bigint::operator+=(const bigint& other)
{
    *this = *this + other;
    return *this;
}

// --------------------------------------------------
// left shift (×10^n)
// --------------------------------------------------

bigint bigint::operator<<(size_t shift) const
{
    if (value == "0")
        return bigint(0);

    std::string result = value;
    result.append(shift, '0');

    return bigint(result);
}

bigint& bigint::operator<<=(size_t shift)
{
    *this = *this << shift;
    return *this;
}

// --------------------------------------------------
// right shift (÷10^n)
// --------------------------------------------------

bigint bigint::operator>>(size_t shift) const
{
    if (shift >= value.size())
        return bigint(0);

    std::string result = value.substr(0, value.size() - shift);

    return bigint(result);
}

bigint& bigint::operator>>=(size_t shift)
{
    *this = *this >> shift;
    return *this;
}

// --------------------------------------------------
// comparison
// --------------------------------------------------

bool bigint::operator<(const bigint& other) const
{
    if (value.size() != other.value.size())
        return value.size() < other.value.size();

    return value < other.value;
}

bool bigint::operator>(const bigint& other) const
{
    return other < *this;
}

bool bigint::operator<=(const bigint& other) const
{
    return !(*this > other);
}

bool bigint::operator>=(const bigint& other) const
{
    return !(*this < other);
}

bool bigint::operator==(const bigint& other) const
{
    return value == other.value;
}

bool bigint::operator!=(const bigint& other) const
{
    return !(*this == other);
}

// --------------------------------------------------
// increment
// --------------------------------------------------

bigint& bigint::operator++()
{
    *this += bigint(1);
    return *this;
}

bigint bigint::operator++(int)
{
    bigint tmp(*this);
    ++(*this);
    return tmp;
}

// --------------------------------------------------
// output
// --------------------------------------------------

std::ostream& operator<<(std::ostream& os, const bigint& num)
{
    os << num.value;
    return os;
}