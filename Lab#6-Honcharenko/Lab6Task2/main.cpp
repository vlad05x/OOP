#include <iostream>
#include "Student.h"
#include "StudentList.h"

using namespace std;

int main() {
    StudentList<Student> studentList;

    studentList.addStudent(Student("\nВлад", "Гончаренко", 92.0));
    studentList.addStudent(Student("\nПаша", "Шавленков", 90.5));
    studentList.addStudent(Student("\nМарк", "Цукерберг", 98.8));

    cout << "Список всіх студентів: ";
    studentList.printAllStudents();

    cout << "\nСтуденти с середнім балом 92.0: ";
    studentList.findStudentsByGrade(92.0);

    cout << "\nВидалення студентів с прізвищем 'Цукерберг' ";
    studentList.deleteStudentByLastName("Цукерберг");

    cout << "\nОновлений список студентів: ";
    studentList.printAllStudents();

    return 0;
}
