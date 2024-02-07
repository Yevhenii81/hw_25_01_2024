#include "Group.h"

Group::Group()
{
    SetGroupName("P26");
    SetNumberOfCourse(2);
    SetSpecialization("Software Delelopmer");
}

Group::Group(const Group& original)
{
    this->countStudent = original.countStudent;
    this->classmates = new Student * [original.countStudent];

    for (int i = 0; i < countStudent; i++)
    {
        this->classmates[i] = new Student(*(original.classmates[i]));
    }
    this->groupName = original.groupName;
    this->specialization = original.specialization;
    this->numberOfCoure = original.numberOfCoure;
}

Group::~Group()
{
    for (int i = 0; i < countStudent; i++)
    {
        delete classmates[i];
    }
    delete[] classmates;
}

void Group::PrintGroup() const
{
    cout << "Group name: " << groupName << "\n";
    cout << "Number of course: " << numberOfCoure << "\n";
    cout << "Specialization: " << specialization << "\n\n";
    for (int i = 0; i < countStudent; i++)
    {
        classmates[i]->PrintStudent();
        classmates[i]->PrintHW();
        classmates[i]->PrintExam();
        classmates[i]->PrintPractic();
        cout << "\naver grade: ";
        classmates[i]->AverageGrade();
        cout << "\n";
    }
}

void Group::AddStudent(const Student& newStudent)
{
    Student** temp = new Student * [countStudent + 1];
    for (int i = 0; i < countStudent; i++)
    {
        temp[i] = classmates[i];
    }
    temp[countStudent] = new Student(newStudent);
    countStudent++;
    delete[] classmates;
    classmates = temp;
}

void Group::WeanStudent(unsigned short index)
{
    Student** temp = new Student * [countStudent - 1];
    for (int i = 0, y = 0; i < countStudent; i++)
    {
        if (i != index)
        {
            temp[y++] = classmates[i];
        }
    }
    delete classmates[index];
    delete[] classmates;
    countStudent--;
    classmates = temp;
}

void Group::Expel()
{
    if (countStudent == 0)
    {
        cout << "Group is empty\n\n";
        return;
    }
    int minGradeIndex = 0;
    for (int i = 1; i < countStudent; i++)
    {
        if (classmates[i]->GetAverageGrade() < classmates[minGradeIndex]->GetAverageGrade())
        {
            minGradeIndex = i;
        }
    }

    Student** temp = new Student * [countStudent - 1];
    for (int i = 0, y = 0; i < countStudent; i++)
    {
        if (i != minGradeIndex)
        {
            temp[y++] = classmates[i];
        }
    }
    delete classmates[minGradeIndex];
    delete[] classmates;
    countStudent--;
    classmates = temp;
    cout << "The student with the lowest grade point average is dropped from the group\n\n";
}

void Group::SetCountOfStudent(int countStudent)
{
    this->countStudent = countStudent;
}

void Group::SetGroupName(string groupName)
{
    this->groupName = groupName;
}

void Group::SetSpecialization(string specialization)
{
    this->specialization = specialization;
}

void Group::SetNumberOfCourse(int numberOfCoure)
{
    this->numberOfCoure = numberOfCoure;
}

int Group::GetCountOfStudent() const
{
    return countStudent;
}

string Group::GetGroupName() const
{
    return groupName;
}

string Group::GetSpecialization() const
{
    return specialization;
}

int Group::GetNumberOfCourse() const
{
    return numberOfCoure;
}