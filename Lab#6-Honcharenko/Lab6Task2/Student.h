#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class Student {
private:
    string firstName;
    string lastName;
    double averageGrade;
public:
    Student(const string firstName, string lastName, double averageGrade) :
        firstName(firstName), lastName(lastName), averageGrade(averageGrade) {}

    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    double getAverageGrade() const { return averageGrade; }

    void print() const {
        cout << firstName << " " << lastName << ", Середній бал: " << averageGrade;
    }
};


#endif // STUDENT_H
