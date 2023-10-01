#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// ������� ��� ���������� �������� � ���� ������
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "������� ��� ��������: ";
    std::cin >> student.name;
    std::cout << "������� ������� ��������: ";
    std::cin >> student.age;
    std::cout << "������� ������������� ��������: ";
    std::cin >> student.major;
    std::cout << "������� ������� ���� ��������: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "������� �������� � ���� ������.\n";
}

// ������� ��� ������ ���� ��������� �� ���� ������
void displayStudents(const std::vector<Student>& database) {
    std::cout << "������ ���������:\n";
    for (const Student& student : database) {
        std::cout << "���: " << student.name << "\n";
        std::cout << "�������: " << student.age << "\n";
        std::cout << "�������������: " << student.major << "\n";
        std::cout << "������� ����: " << student.gpa << "\n\n";
    }
}

// ������� ��� ������ �������� �� ����� ��� �� �������������

Student* findStudentByName(std::vector<Student*>& database, std::string name) {
    for (Student* student : database) {
        if (student->name == name) {
            return student;
        }
    }
    return nullptr;
}

Student* findStudentByMajor(std::vector<Student*>& database, std::string major) {
    for (Student* student : database) {
        if (student->major == major) {
            return student;
        }
    }
    return nullptr;
}

