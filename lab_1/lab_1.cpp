﻿#include <iostream>
#include <vector>
#include <string>
#include "StudentDatabase.h"


class Test {
    void Test1() {
        // Arrange
        std::vector<Student*> database;
        Student student1;

        student1.name = "Даша";
        student1.age = 21;
        student1.major = "IT";
        student1.gpa = 5;
        database.push_back(&student1);

        Student student2;
        student2.name = "Саша";
        student2.age = 18;
        student2.major = "Менеджер";
        student2.gpa = 3;
        database.push_back(&student2);

        Student student3;
        student3.name = "Сергей";
        student3.age = 20;
        student3.major = "Сварщик";
        student3.gpa = 4;
        database.push_back(&student3);

        // Act
        Student *student_name = findStudentByName(database, "Даша");
       
        // Assert
        if (student_name->name == "Даша") 
            std::cout << "Тест 1 пройден\n";
        else std::cout << "Тест 1 не пройден\n";
    }

    void Test2() {
        // Arrange
        std::vector<Student*> database;
        Student student1;

        student1.name = "Даша";
        student1.age = 21;
        student1.major = "IT";
        student1.gpa = 5;
        database.push_back(&student1);

        Student student2;
        student2.name = "Саша";
        student2.age = 18;
        student2.major = "Менеджер";
        student2.gpa = 3;
        database.push_back(&student2);

        Student student3;
        student3.name = "Сергей";
        student3.age = 20;
        student3.major = "Сварщик";
        student3.gpa = 4;
        database.push_back(&student3);

        // Act
        Student* student_major = findStudentByMajor(database, "Менеджер");

        // Assert
        if (student_major->major == "Менеджер")
            std::cout << "Тест 2 пройден\n";
        else std::cout << "Тест 2 не пройден\n";
    }

    void Test3() {
        // Arrange
        std::vector<Student*> database;
        Student student1;

        student1.name = "Даша";
        student1.age = 21;
        student1.major = "IT";
        student1.gpa = 5;
        database.push_back(&student1);

        Student student2;
        student2.name = "Саша";
        student2.age = 18;
        student2.major = "Менеджер";
        student2.gpa = 3;
        database.push_back(&student2);

        Student student3;
        student3.name = "Сергей";
        student3.age = 20;
        student3.major = "Сварщик";
        student3.gpa = 4;
        database.push_back(&student3);

        // Act
        Student* student_name = findStudentByName(database, "Света");

        // Assert
        if (student_name == nullptr)
            std::cout << "Тест 3 пройден\n";
        else std::cout << "Тест 3 не пройден\n";
    }

    void Test4() {
        // Arrange
        std::vector<Student*> database;
        Student student1;

        student1.name = "Даша";
        student1.age = 21;
        student1.major = "IT";
        student1.gpa = 5;
        database.push_back(&student1);

        Student student2;
        student2.name = "Саша";
        student2.age = 18;
        student2.major = "Менеджер";
        student2.gpa = 3;
        database.push_back(&student2);

        Student student3;
        student3.name = "Сергей";
        student3.age = 20;
        student3.major = "Сварщик";
        student3.gpa = 4;
        database.push_back(&student3);

        // Act
        Student* student_major = findStudentByMajor(database, "Врач");

        // Assert
        if (student_major == nullptr)
            std::cout << "Тест 4 пройден\n";
        else std::cout << "Тест 4 не пройден\n";
    }

    void Test5() {
        // Arrange
        std::vector<Student*> database;
        Student student1;

        student1.name = "Саша";
        student1.age = 21;
        student1.major = "IT";
        student1.gpa = 5;
        database.push_back(&student1);

        Student student2;
        student2.name = "Саша";
        student2.age = 18;
        student2.major = "Менеджер";
        student2.gpa = 3;
        database.push_back(&student2);

        Student student3;
        student3.name = "Сергей";
        student3.age = 20;
        student3.major = "Сварщик";
        student3.gpa = 4;
        database.push_back(&student3);

        // Act
        Student* student_name = findStudentByName(database, "Саша");
        Student* student_major = findStudentByMajor(database, "Менеджер");

        // Assert
        if (student_major->major == "Менеджер" && student_name->name == "Саша")
            std::cout << "Тест 5 пройден\n";
        else std::cout << "Тест 5 не пройден\n";
    }

    public:
        void allTests() {
            Test1();
            Test2();
            Test3();
            Test4();
            Test5();
        }
};



int main() {
    setlocale(LC_ALL, "ru");
    std::vector<Student> database;
    Test* test = new Test();
    test->allTests();

    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Найти стдудента по имени или специальности\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addStudent(database);
            break;
        case 2:
            displayStudents(database);
            break;
        case 3:
            //searchStudents(database);
            break;
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}