
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class complex {
    //Data Members
    double real;
    double imaginary;

    public:
    //Constructor
    complex(double real = 0.0, double imaginary = 0.0);

    //Member functions
    double getReal() const;
    double getImaginary() const;

    //Operator Overloads
    complex operator+(const complex &rhs) const;
    complex operator-(const complex &rhs) const;
    complex operator*(const complex &rhs) const;
    complex operator/(const complex &rhs) const;

    //Conjugate
    complex conjugate() const;

    //Assignment Operators
    complex& operator+=(const complex &rhs);
    complex& operator-=(const complex &rhs);
    complex& operator*=(const complex &rhs);
    complex& operator/=(const complex &rhs);

    //Comparison Operators
    bool operator==(const complex &rhs) const;
    bool operator!=(const complex &rhs) const;

    //Stream I/O
    friend std::ostream& operator<<(std::ostream &os, const complex &rhs);
    friend std::istream& operator>>(std::istream &is, complex &rhs);
};

#endif //COMPLEX_H