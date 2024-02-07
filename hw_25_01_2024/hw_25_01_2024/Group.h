#pragma once
#include "Student.h"

class Group
{
public:
    Student** classmates = nullptr;
private:
    unsigned short countStudent = 0;
    unsigned short numberOfCoure;
    string groupName;
    string specialization;
public:
    Group();
    Group(const Group& original);
    ~Group();

    void PrintGroup() const;

    void AddStudent(const Student& newStudent);

    void WeanStudent(unsigned short index);

    void Expel();

    void SetCountOfStudent(int countStudent);
    void SetGroupName(string groupName);
    void SetSpecialization(string specialization);
    void SetNumberOfCourse(int numberOfCoure);

    int GetCountOfStudent() const;
    string GetGroupName() const;
    string GetSpecialization() const;
    int GetNumberOfCourse() const;
};

