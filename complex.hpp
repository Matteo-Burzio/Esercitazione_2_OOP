#pragma once

using namespace std;

template<typename I> requires floating_point<I> // Restriction on what types are allowed
class complex
{
    // Real and Imaginary part are private members
    I real, imaginary; 

    public:
    // Default constructor
    /*The members are initialized before the constructor body executes,
    and the body is empty */
    complex()
        : real(0), imaginary(0)
    {}

    // User-defined constructor 1
    /*This constructor activates if the user gives a single value
    assuming that it is referring to a real number (no imaginary part)*/
    explicit complex(I re)
    : real(re), imaginary(0)
    {
        cout << "Converting constructor called" << endl;
    }

    // User-defined constructor 2
    /*This constructor activates if the user gives both parameters*/
    complex(I re, I im)
        : real(re), imaginary(im)
    {}

    // Method to get the real part
    I real_part(void) const
    {
        return real;
    }

    // Method to get the imaginary part
    I imaginary_part(void) const
    {
        return imaginary;
    }

    // Method to get the complex conjugate
    complex<I> conjugate(void) const
    {
        return complex(real, -imaginary);
    }

    // Overload of +=
    /*It takes only one parameter since it modifies the value in place.
    It returns a reference to the modified value */ 
    complex& operator+=(const complex& other) 
    {
        // Get real and imaginary part of left number
        I re1 = real;
        I im1 = imaginary;
        // Get real and imaginary part of right number
        I re2 = other.real_part();
        I im2 = other.imaginary_part();
        // Sum the values and assign the result to the number on the left
        real = re1 + re2;
        imaginary = im1 + im2;

        /* "this" is a pointer to the current object,
        it has to be returned dereferenced*/ 
        return *this;
    }

    // Overload of +
    /* It takes the right number in input and returns a new complex
    which is the sum of right and left numbers*/
    complex operator+(const complex& other) const
    {
        complex res = *this; // initializes a new complex
        res += other; // modifies it in place by using +=

        return res; // returns the sum
    }

    // Overload of *=
    complex& operator *=(const complex& other)
    {
        // Get real and imaginary part
        I a = real;
        I b = imaginary;
        I c = other.real_part();
        I d = other.imaginary_part();

        // (a+ib) * (c+id) = (ac-bd)+i(ad+bc)
        real = a*c - b*d;
        imaginary = a*d + b*c;

        return *this;
    }

    // Overload of * (same construction as "+")
    complex operator*(const complex& other) const
    {
        complex res = *this;
        res *= other;

        return res;
    }

};


// Overload of + (outside of the class)
/* This needs to be done in order to compute the sum of an object
of type I on the left and a complex<I> on the right.
It works since addition (and multiplication) are commutative*/
template<typename I>
complex<I>
operator+(const I& lf, const complex<I>& rg)
{
    return rg + lf; // uses "+" defined in the class
}

// Overload of * (outside of the class)
template<typename I>
complex<I>
operator*(const I& lf, const complex<I>& rg)
{
    return rg * lf; // uses "*" defined in the class
}


// Overload of << to print complex numbers in the desired format
template<typename I>
ostream&
operator<<(ostream& os, const complex<I>& z)
{
    if (z.imaginary_part() > 0) 
        os << z.real_part() << "+" << z.imaginary_part() << "i";
    else if (z.imaginary_part() < 0)
        os << z.real_part() << z.imaginary_part() << "i"; // minus sign is automatically printed
    else
        os << z.real_part();
    
    return os;
}

