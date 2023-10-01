#include <gtest/gtest.h> 
#include <gmock/gmock.h> 
#include "StudentDatabase.h"

TEST(TestGroupName, Test_1) {
    // Arrange
    std::vector<Student*> database;
    Student student1;

    student1.name = "����";
    student1.age = 21;
    student1.major = "IT";
    student1.gpa = 5;
    database.push_back(&student1);

    Student student2;
    student2.name = "����";
    student2.age = 18;
    student2.major = "��������";
    student2.gpa = 3;
    database.push_back(&student2);

    Student student3;
    student3.name = "������";
    student3.age = 20;
    student3.major = "�������";
    student3.gpa = 4;
    database.push_back(&student3);

    // Act
    Student* student_name = findStudentByName(database, "����");

    // Assert
    ASSERT_TRUE(student_name->name == "����");
}

TEST(TestGroupName, Test_2) {
    // Arrange
    std::vector<Student*> database;
    Student student1;

    student1.name = "����";
    student1.age = 21;
    student1.major = "IT";
    student1.gpa = 5;
    database.push_back(&student1);

    Student student2;
    student2.name = "����";
    student2.age = 18;
    student2.major = "��������";
    student2.gpa = 3;
    database.push_back(&student2);

    Student student3;
    student3.name = "������";
    student3.age = 20;
    student3.major = "�������";
    student3.gpa = 4;
    database.push_back(&student3);

    // Act
    Student* student_major = findStudentByMajor(database, "��������");

    // Assert
    ASSERT_TRUE(student_major->major == "��������");
}

TEST(TestGroupName, Test_3) {
    // Arrange
    std::vector<Student*> database;
    Student student1;

    student1.name = "����";
    student1.age = 21;
    student1.major = "IT";
    student1.gpa = 5;
    database.push_back(&student1);

    Student student2;
    student2.name = "����";
    student2.age = 18;
    student2.major = "��������";
    student2.gpa = 3;
    database.push_back(&student2);

    Student student3;
    student3.name = "������";
    student3.age = 20;
    student3.major = "�������";
    student3.gpa = 4;
    database.push_back(&student3);

    // Act
    Student* student_name = findStudentByName(database, "�����");

    // Assert
    ASSERT_TRUE(student_name == nullptr);
}

TEST(TestGroupName, Test_4) {
    // Arrange
    std::vector<Student*> database;
    Student student1;

    student1.name = "����";
    student1.age = 21;
    student1.major = "IT";
    student1.gpa = 5;
    database.push_back(&student1);

    Student student2;
    student2.name = "����";
    student2.age = 18;
    student2.major = "��������";
    student2.gpa = 3;
    database.push_back(&student2);

    Student student3;
    student3.name = "������";
    student3.age = 20;
    student3.major = "�������";
    student3.gpa = 4;
    database.push_back(&student3);

    // Act
    Student* student_major = findStudentByMajor(database, "����");

    // Assert
    ASSERT_TRUE(student_major == nullptr);
}

TEST(TestGroupName, Test_5) {
    // Arrange
    std::vector<Student*> database;
    Student student1;

    student1.name = "����";
    student1.age = 21;
    student1.major = "IT";
    student1.gpa = 5;
    database.push_back(&student1);

    Student student2;
    student2.name = "����";
    student2.age = 18;
    student2.major = "��������";
    student2.gpa = 3;
    database.push_back(&student2);

    Student student3;
    student3.name = "������";
    student3.age = 20;
    student3.major = "�������";
    student3.gpa = 4;
    database.push_back(&student3);

    // Act
    Student* student_name = findStudentByName(database, "����");
    Student* student_major = findStudentByMajor(database, "��������");

    // Assert
    ASSERT_TRUE(student_major->major == "��������" && student_name->name == "����");
}

int main(int argc, char **argv) { 

	::testing::InitGoogleTest(&argc, argv); 

	return RUN_ALL_TESTS(); 
}
