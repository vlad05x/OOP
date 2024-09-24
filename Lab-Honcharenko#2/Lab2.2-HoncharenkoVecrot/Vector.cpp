#include "Vector.h"
// Конструктор приймаэ розмір вектора n
Vector::Vector(int n) : size(n) {
//Налаштування вектора компонентів
    components.resize(n, 0.0);
}
// Конструктор за вектором компонентів
Vector::Vector(const std::vector<double>& components) : components(components), size(components.size()) {}

Vector::Vector(const Vector& other) : components(other.components), size(other.size) {}

// Метод обчислення довжини вектора
double Vector::magnitude() const {
    double sum = 0;
    for (double comp : components) {
        sum += comp * comp;
    }
    return sqrt(sum);
}
// Скалярный добуток
double Vector::dotProduct(const Vector& other) const {
    double result = 0;
    for (int i = 0; i < size; ++i) {
        result += components[i] * other.components[i];
    }
    return result;
}

Vector Vector::add(const Vector& other) const {
    std::vector<double> result(size);
    for (int i = 0; i < size; ++i) {
        result[i] = components[i] + other.components[i];
    }
    return Vector(result);
}

Vector Vector::subtract(const Vector& other) const {
    std::vector<double> result(size);
    for (int i = 0; i < size; ++i) {
        result[i] = components[i] - other.components[i];
    }
    return Vector(result);
}

Vector Vector::multiplyByConstant(double scalar) const {
    std::vector<double> result(size);
    for (int i = 0; i < size; ++i) {
        result[i] = components[i] * scalar;
    }
    return Vector(result);
}

// Перевірка на колінеарність (якщо вектори пропорційні)
bool Vector::isCollinear(const Vector& other) const {
    double ratio = components[0] / other.components[0];
    for (int i = 1; i < size; ++i) {
        // Обчислення їх відношення
        if (components[i] / other.components[i] != ratio) {
            return false;
        }
    }
    return true;
}

// Перевірка на ортогональність
bool Vector::isOrthogonal(const Vector& other) const {
    return dotProduct(other) == 0;
}

void Vector::display() const {
    std::cout << "(";
    for (int i = 0; i < size; ++i) {
        std::cout << components[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << ")\n";
}


// Метод перевантажує оператор присвоєння
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        components = other.components;
        size = other.size;
    }
    return *this;
}
