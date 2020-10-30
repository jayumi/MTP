#include <iostream>
#include <iomanip>
#include <string>
#include "Semester.h"
using namespace std;

Semester::Semester(const string& name, const Date& startD, const Date& endD)
	: semesterName(name), startDate(startD), endDate(endD)
{

}

//GET FUNCTIONS
string Semester::getSemesterName() const
{
	return semesterName;
}

Date Semester::getStartDate() const
{
	return startDate;
}

Date Semester::getEndDate() const
{
	return endDate;
}

//SET FUNCTIONS
Semester& Semester::setSemesterName(string name)
{
	semesterName = name;
	return *this;
}

Semester& Semester::setStartDate(int month, int day, int year)
{
	startDate.setMonth(month);
	startDate.setDay(day);
	startDate.setYear(year);
	return *this;
}

Semester& Semester::setEndDate(int month, int day, int year)
{
	endDate.setMonth(month);
	endDate.setDay(day);
	endDate.setYear(year);
	return *this;
}

//OVERLOAD OUTPUT
ostream& operator<<(ostream& output, const Semester& obj)
{
	output << "Semester: " << obj.semesterName
		<< " (" << obj.startDate << "-" << obj.endDate << ")" << endl;
	return output;
}

//OVERLOAD INPUT
istream& operator>>(istream& input, Semester& obj)
{
	input >> obj.semesterName;
	input.ignore(2); //ignores "("
	input >> obj.startDate;
	input.ignore();
	input >> obj.endDate;
	return input;
}
