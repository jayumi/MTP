#include <iostream>
#include <iomanip>
#include <string>
#include "Semester.h"
using namespace std;

Semester::Semester()
{
	semesterName = " ";
	startDate = Date();
	endDate = Date();
}

Semester::Semester(string name, Date startD, Date endD)
{
	this->semesterName = name;
	this->startDate.setDate(startD.getMonth(), startD.getDay(), startDate.getYear());
	this->endDate.setDate(endD.getMonth(), endD.getDay(), endD.getYear());
}

//GET FUNCTIONS
string Semester::geSemesterName() const
{
	return semesterName;
}

int Semester::getSemStartMonth() const
{
	return startDate.getMonth();
}

int Semester::getSemStartDay() const
{
	return startDate.getDay();
}

int Semester::getSemStartYear() const
{
	return startDate.getYear();
}

int Semester::getSemEndMonth() const
{
	return endDate.getMonth();
}

int Semester::getSemEndDay() const
{
	return endDate.getDay();
}

int Semester::getSemEndYear() const
{
	return endDate.getYear();
}

//SET FUNCTIONS
void Semester::setSemesterName(string& name)
{
	semesterName = name;
}

void Semester::setSemStartMonth(int month)
{
	startDate.setMonth(month);
}

void Semester::setSemStartDay(int day)
{
	startDate.setDay(day);
}

void Semester::setSemStartYear(int year)
{
	startDate.setYear(year);
}

void Semester::setSemEndMonth(int month)
{
	endDate.setMonth(month);
}

void Semester::setSemEndDay(int day)
{
	endDate.setDay(day);
}

void Semester::setSemEndYear(int year)
{
	endDate.setYear(year);
}

//OVERLOAD OUTPUT
ostream& operator<<(ostream& output, const Semester& obj)
{
	output << "Semester: " << obj.semesterName
		<< " (" << obj.startDate << " - " << obj.endDate << ")" << endl;
	return output;
}

//OVERLOAD INPUT
istream& operator>>(istream& input, Semester& obj)
{
	getline(input, obj.semesterName);
	input >> obj.startDate;
	input >> obj.endDate;
	return input;
}
