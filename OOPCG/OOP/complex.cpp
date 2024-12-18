#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    // Default constructor to initialize complex number as 0 + 0i
    Complex() : real(0), imag(0) {}

    // Constructor to initialize complex number with given real and imaginary parts
    Complex(double r, double i) : real(r), imag(i) {}

    // Overload the + operator to add two complex numbers
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload the * operator to multiply two complex numbers
    Complex operator*(const Complex& other) {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    // Overload the << operator to print complex number
    friend ostream& operator<<(ostream& os, const Complex& c) {
        if (c.imag >= 0)
            os << c.real << " + " << c.imag << "i";
        else
            os << c.real << " - " << -c.imag << "i";
        return os;
    }

    // Overload the >> operator to read complex number
    friend istream& operator>>(istream& is, Complex& c) {
        cout << "Enter real part: ";
        is >> c.real;
        cout << "Enter imaginary part: ";
        is >> c.imag;
        return is;
    }
};

int main() {
    Complex c1, c2, sum, product;

    // Reading two complex numbers from the user
    cout << "Enter first complex number:" << endl;
    cin >> c1;
    cout << "Enter second complex number:" << endl;
    cin >> c2;

    // Adding the complex numbers
    sum = c1 + c2;
    cout << "Sum: " << sum << endl;

    // Multiplying the complex numbers
    product = c1 * c2;
    cout << "Product: " << product << endl;

    return 0;
}
