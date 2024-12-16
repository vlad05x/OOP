#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include <vector>
#include <iostream>
#include <Student.h>
using namespace std;

template <typename T>
class StudentList {
private:
    vector<T> students;
public:
    void addStudent(const T& student) {
        students.push_back(student);
    }

    void deleteStudentByLastName(const string& lastName) {
        for(size_t i = 0; i < students.size(); ) {
            if(students[i].getLastName() == lastName) {
                students.erase(students.begin() +i);
            } else {
                ++i;
            }
        }
    }

    void findStudentsByGrade(double grade) const {
        for (const auto& student : students) {
            if (student.getAverageGrade() == grade) {
                student.print();
            }
        }
    }

    void printAllStudents() const {
        for (const auto& student : students) {
            student.print();
        }
    }
};

#endif // STUDENTLIST_H
