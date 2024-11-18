#include "Vector.h"

Vector::Vector(int n) : size(n) {
    components.resize(n, 0.0);
}

Vector::Vector(const std::vector<double>& components) : components(components), size(components.size()) {}

Vector::Vector(const Vector& other) : components(other.components), size(other.size) {}

double Vector::magnitude() const {
    double sum = 0;
    for (double comp : components) {
        sum += comp * comp;
    }
    return sqrt(sum);
}

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

bool Vector::isCollinear(const Vector& other) const {
    double ratio = components[0] / other.components[0];
    for (int i = 1; i < size; ++i) {
        if (components[i] / other.components[i] != ratio) {
            return false;
        }
    }
    return true;
}

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


Vector Vector::operator+(const Vector& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Вектори повинні мати однаковий розмір для додавання");
    }

    std::vector<double> result(size);

    for (int i = 0; i < size; ++i) {
        result[i] = components[i] + other.components[i];
    }

    return Vector(result);
}


bool Vector::operator==(const Vector& other) const {
    if (size != other.size) {
        return false;
    }

    for (int i = 0; i < size; ++i) {
        if (components[i] != other.components[i]) {
            return false;
        }
    }
    return true;
}


Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        components = other.components;
        size = other.size;
    }
    return *this;
}

