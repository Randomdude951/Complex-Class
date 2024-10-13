
#include "complex.h"
// constructor
complex::complex(double r, double i) : real(r), imaginary(i) {}

double complex::getReal() const {
    return real;
}

double complex::getImaginary() const {
    return imaginary;
}

complex& complex::operator+=(const complex &rhs)
{
    real += rhs.real;
    imaginary += rhs.imaginary;
    return *this;
}

complex& complex::operator-=(const complex &rhs)
{
    real -= rhs.real;
    imaginary -= rhs.imaginary;
    return *this;
}

complex& complex::operator*=(const complex &rhs)
{
    double tempReal = real * rhs.real - imaginary * rhs.imaginary;
    double tempImaginary = real * rhs.imaginary + imaginary * rhs.real;
    real = tempReal;
    imaginary = tempImaginary;
    return *this;
}

complex& complex::operator/=(const complex &rhs)
{   //Checking for division by 0
    if (rhs.real == 0 && rhs.imaginary == 0) {
        std::cout << "division by 0" << std::endl;
        return *this; //Returning original left-hand-side object
    }
    //Conjugate of denominator
    complex conj = rhs.conjugate();
    //Multiply the numerator by the conjugate
    complex numerator = *this * conj;
    //Calculating denominator (denominator = real ^2 + imaginary ^2)
    double denominator = rhs.real * rhs.real + rhs.imaginary * rhs.imaginary;
    real = numerator.real / denominator;
    imaginary = numerator.imaginary / denominator;
    return *this;
}


complex complex::operator+(const complex& rhs) const {
    complex sum = *this;
    sum += rhs;
    return sum;
}

complex complex::operator-(const complex &rhs) const {
    complex difference = *this;
    difference -= rhs;
    return difference;
}

complex complex::operator*(const complex& rhs) const {
    complex product = *this;
    product *= rhs;
    return product;
}

complex complex::operator/(const complex& rhs) const {
    complex quotient = *this;
    quotient/= rhs;
    return quotient;
}

complex complex::conjugate() const {
    return complex(real, -imaginary);
}

bool complex::operator==(const complex &rhs) const
{
    return (real == rhs.getReal()) && (imaginary == rhs.getImaginary());
}

bool complex::operator!=(const complex &rhs) const {
    return (real != rhs.getReal()) || (imaginary != rhs.getImaginary());
}

std::ostream& operator<<(std::ostream& os, const complex& rhs) {
    double real = rhs.getReal();
    double imaginary = rhs.getImaginary();

    if(real == 0 && imaginary == 0) {
        os << "0";
    } else if(imaginary == 0){
        os << real;
    }else if(real == 0) {
        if(imaginary != 1) {
            os << imaginary << "i";
        } else {
            os << "i";
        }
    } else {
        os << real;
        if(imaginary > 0) {
            if(imaginary != 1) {
                os << "+" << imaginary << "i";
            } else {
                os << "+" << "i";
            }
        } else {
            os << imaginary << "i";
        }
    }
    return os;
}

std::istream& operator>>(std::istream& is, complex& rhs) {
    double real, imaginary;
    is >> real >> imaginary;
    rhs = complex(real, imaginary);
    return is;
}
