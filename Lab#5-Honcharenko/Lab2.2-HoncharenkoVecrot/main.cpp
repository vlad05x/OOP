#include "Vector.h"
#include <iostream>

int main() {
    Vector v1({1.0, 2.0, 3.0});
    Vector v2({2.0, 4.0, 6.0});

    std::cout << "Вектор v1: ";
    v1.display();
    std::cout << "Вектор v2: ";
    v2.display();

    std::cout << "Модуль вектора v1: " << v1.magnitude() << "\n";

    std::cout << "Скалярний добуток v1 і v2: " << v1.dotProduct(v2) << "\n";

    Vector v3 = v1 + v2;
    std::cout << "v1 + v2 = ";
    v3.display();

    Vector v4 = v1.subtract(v2);
    std::cout << "v1 - v2 = ";
    v4.display();

    Vector v5 = v1.multiplyByConstant(3.0);
    std::cout << "v1 * 3 = ";
    v5.display();

    if (v1.isCollinear(v2)) {
        std::cout << "Вектори v1 і v2 є колінеарними\n";
    } else {
        std::cout << "Вектори v1 і v2 не є колінеарними\n";
    }

    if (v1.isOrthogonal(v2)) {
        std::cout << "Вектори v1 і v2 є ортогональними\n";
    } else {
        std::cout << "Вектори v1 і v2 не є ортогональними\n";
    }

    if (v1 == v2) {
        std::cout << "Вектори v1 і v2 рівні\n";
    } else {
        std::cout << "Вектори v1 і v2 не рівні\n";
    }

    return 0;
}
