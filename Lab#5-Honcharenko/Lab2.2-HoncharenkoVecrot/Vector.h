#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>
#include <vector>

class Vector {
private:
    std::vector<double> components;
    int size;
public:
    Vector(int n);
    Vector(const std::vector<double>& components);
    Vector(const Vector& other);

    double magnitude() const;
    double dotProduct(const Vector& other) const;
    Vector add(const Vector& other) const;
    Vector subtract(const Vector& other) const;
    Vector multiplyByConstant(double scalar) const;

    bool isCollinear(const Vector& other) const;
    bool isOrthogonal(const Vector& other) const;

    void display() const;

    Vector& operator=(const Vector& other);
    Vector operator+(const Vector& other) const;
    bool operator==(const Vector& other) const;
};

#endif // VECTOR_H
