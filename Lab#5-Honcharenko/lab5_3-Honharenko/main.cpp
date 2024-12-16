#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex (r, i);
    }

    Complex operator/(const Complex& other) {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            throw std::invalid_argument("Ділення на нуль заборонено !");
        }
        double r = (real * other.real + imag * other.imag) / denominator;
        double i = (imag * other.real - real * other.imag) / denominator;
        return Complex(r, i);
    }

    bool operator==(const Complex& other) {
        return real == other.real && imag == other.imag;
    }

    bool operator!=(const Complex& other) {
        return !(*this == other);
    }

    double getReal() const {
        return real;
    }

    double getImag() const {
        return imag;
    }

    ~Complex() {}
};

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.getReal() << " + " << c.getImag() << "i";
    return os;
}

int main() {
    Complex z1(3, 4), z2(2, 5);

    Complex sum = z1 + z2;
    cout << "\nДодавання: " << sum;

    Complex minus = z1 - z2;
    cout << "\nВіднімання: " << minus;

    Complex product = z1 * z2;
    cout << "\nМноження: " << product;

    Complex division = z1 / z2;
    cout << "\nДілення: " << division;

    cout << "\nЧи рівні? " << (z1 == z2 ? "Так" : "Ні") << endl;

    cout << "Чи не рівні? " << (z1 != z2 ? "Так" : "Ні") << endl;

    return 0;
}
