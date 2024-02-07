#include <iostream>
using namespace std;

#include "Student.h"

Student::Student(const Student& original)
{
	this->surname = original.surname;
	this->name = original.name;
	this->patronymic = original.patronymic;
	this->adress = original.adress;
	this->phoneNumber = original.phoneNumber;
	this->countPractic = original.countPractic;
	this->countHW = original.countHW;
	this->countExam = original.countExam;
	this->averGradeExam = original.averGradeExam;

	this->gradeOfPractic = new int[original.countPractic];
	for (int i = 0; i < countPractic; i++)
	{
		this->gradeOfPractic[i] = original.gradeOfPractic[i];
	}

	this->gradeOfHW = new int[original.countHW];
	for (int i = 0; i < countHW; i++)
	{
		this->gradeOfHW[i] = original.gradeOfHW[i];
	}

	this->gradeOfExam = new int[original.countExam];
	for (int i = 0; i < countExam; i++)
	{
		this->gradeOfExam[i] = original.gradeOfExam[i];
	}
}

Student::Student() :Student("Shostak", "Yevhenii", "Stanislavovich", "Mir cel Batrin 32", "0661124661") {}

Student::Student(string surname, string name, string patronymic, string adress, string phoneNumber)
{
	SetSurname(surname);
	SetName(name);
	SetPatronymic(patronymic);
	SetAdress(adress);
	SetPhoneNumber(phoneNumber);
}

Student::Student(string surname, string name, string patronymic, string adress) :Student(surname, name, patronymic, adress, "0661124661") {}

Student::~Student()
{
	if (gradeOfPractic != nullptr)
		delete[] gradeOfPractic;
	if (gradeOfHW != nullptr)
		delete[] gradeOfHW;
	if (gradeOfExam != nullptr)
		delete[] gradeOfExam;
}

void Student::PrintStudent() const
{
	cout << "Surname: " << surname << "\n";
	cout << "Name: " << name << "\n";
	cout << "Patronymic: " << patronymic << "\n";
	cout << "Adress: " << adress << "\n";
	cout << "Phone number: " << phoneNumber << "\n";
}

void Student::SetSurname(string surname)
{
	this->surname = surname;
}

void Student::SetName(string name)
{
	this->name = name;
}

void Student::SetPatronymic(string patronymic)
{
	this->patronymic = patronymic;
}

void Student::SetAdress(string adress)
{
	this->adress = adress;
}

void Student::SetPhoneNumber(string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

string Student::GetSurname() const
{
	return surname;
}

string Student::GetName() const
{
	return name;
}

string Student::GetPatronymic() const
{
	return patronymic;
}

string Student::GetAdress() const
{
	return adress;
}

string Student::GetPhoneNumber() const
{
	return phoneNumber;
}

///Practic
void Student::AddPractic(int grade)
{
	int* temp = new int[countPractic + 1];
	for (int i = 0; i < countPractic; i++)
	{
		temp[i] = gradeOfPractic[i];
	}
	temp[countPractic] = grade;
	countPractic++;
	delete[] gradeOfPractic;
	gradeOfPractic = temp;
}

void Student::PrintPractic() const
{
	for (int i = 0; i < countPractic; i++)
	{
		cout << gradeOfPractic[i] << ", ";
	}
}

int Student::GetPracticRates(unsigned int index) const
{
	if (index < countPractic)
	{
		return gradeOfPractic[index];
	}
	else
	{
		cout << "Index is out of bounds\n";
	}
}

///HW
void Student::AddHW(int grade)
{
	int* temp = new int[countHW + 1];
	for (int i = 0; i < countHW; i++)
	{
		temp[i] = gradeOfHW[i];
	}
	temp[countHW] = grade;
	countHW++;
	delete[] gradeOfHW;
	gradeOfHW = temp;
}

void Student::PrintHW() const
{
	for (int i = 0; i < countHW; i++)
	{
		cout << gradeOfHW[i] << ", ";
	}
}

int Student::GetHWRates(unsigned int index) const
{
	if (index < countHW)
	{
		return gradeOfHW[index];
	}
	else
	{
		cout << "Index is out of bounds\n";
	}
}

///Exam
void Student::AddExam(int grade)
{
	int* temp = new int[countExam + 1];
	for (int i = 0; i < countExam; i++)
	{
		temp[i] = gradeOfExam[i];
	}
	temp[countExam] = grade;
	countExam++;
	delete[] gradeOfExam;
	gradeOfExam = temp;
}

void Student::AverageGrade()
{
	averGradeExam = 0;
	for (int i = 0; i < countExam; i++)
	{
		averGradeExam += gradeOfExam[i];
	}
	averGradeExam /= countExam;
	cout << averGradeExam << "\n";
}

void Student::PrintExam() const
{
	for (int i = 0; i < countExam; i++)
	{
		cout << gradeOfExam[i] << ", ";
	}
}

int Student::GetExamRates(unsigned int index) const
{
	if (index < countExam)
	{
		return gradeOfExam[index];
	}
	else
	{
		cout << "Index is out of bounds\n";
	}
}


void Student::SetAverageGrade(int averGradeExam)
{
	this->averGradeExam = averGradeExam;
}
int Student::GetAverageGrade() const
{
	return averGradeExam;
}