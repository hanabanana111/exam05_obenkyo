#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint
{
private:
    std::string value;

    void remove_leading_zeros();

public:
    // Constructors
    bigint();
    bigint(unsigned long long num);
    bigint(const bigint& other);
    bigint(const std::string& str);

    // Assignment
    bigint& operator=(const bigint& other);

    // Arithmetic
    bigint operator+(const bigint& other) const;
    bigint& operator+=(const bigint& other);

    // Digit shift
    bigint operator<<(size_t shift) const;
    bigint& operator<<=(size_t shift);

    bigint operator>>(size_t shift) const;
    bigint& operator>>=(size_t shift);

    // Comparison
    bool operator<(const bigint& other) const;
    bool operator>(const bigint& other) const;
    bool operator<=(const bigint& other) const;
    bool operator>=(const bigint& other) const;
    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;

    // Increment
    bigint& operator++();
    bigint operator++(int);

    // Output
    friend std::ostream& operator<<(std::ostream& os, const bigint& num);
};

#endif