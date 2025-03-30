#include <concepts>
#include <iostream>
#include "complex.hpp"

using namespace std;

int main(void){
    using complex = complex<float>;

    complex z1; // default constructor
    cout << "z1 = " << z1 << endl;

    complex z2(4); // user constructor 1
    cout << "z2 = " << z2 << endl;

    complex z3(4,2); // user constructor 2
    cout << "z3 = " << z3 << endl;

    complex z4(6,-1);
    cout << "z4 = " << z4 << endl;

    // Test methods
    cout << "The real part of z3 is " << z3.real_part() << endl;
    cout << "The imaginary part of z3 is " << z3.imaginary_part() << endl;
    cout << "The conjugate of z3 is " << z3.conjugate() << endl;

    // Test overload of operators
    cout << "z3 + z4 = " << z3 + z4 << endl;
    cout << "z3 * z4 = " << z3 * z4 << endl;
    
    return 0;
}