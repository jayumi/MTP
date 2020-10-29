#include <iostream>
#include <iomanip>
#include "Date.h"
using namespace std;

Date::Date(int m, int d, int y)
{
	setDate(m, d, y);
}

Date::~Date()
{

}

Date& Date::setDate(int m, int d, int y)
{
	setMonth(m);
	setDay(d);
	setYear(y);

	return *this;
}

void Date::checkDate()
{
	static const int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month <= 0 || month >= 12)
	{
		month = 1;
	}

	if (!(month == 2 && day == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
		&& (day <= 0 || day > daysPerMonth[month]))
	{
		day = 1;
	}

	if (year <= 1989)
	{
		year = 1990;
	}
}

Date& Date::setMonth(int m)
{
	month = m;
	checkDate();
	return *this;
}

Date& Date::setDay(int d)
{
	day = d;
	checkDate();
	return *this;
}

Date& Date::setYear(int y)
{
	year = y;
	checkDate();
	return *this;
}

int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

int Date::getYear() const
{
	return year;
}

bool Date::operator<(const Date& right)
{
	bool status;
	if (year < right.year)
		status = true;
	else if ((year == right.year) && (month < right.month))
		status = true;
	else if ((year == right.year) && (month < right.month) && (day < right.day))
		status = true;
	else
		status = false;

	return status;
}

bool Date::operator>(const Date& right)
{
	bool status;
	if (year > right.year)
		status = true;
	else if ((year == right.year) && (month > right.month))
		status = true;
	else if ((year == right.year) && (month > right.month) && (day > right.day))
		status = true;
	else
		status = false;

	return status;
}

bool Date::operator<=(const Date& right)
{
	bool status;
	if (year <= right.year)
		status = true;
	else if ((year == right.year) && (month <= right.month))
		status = true;
	else if ((year == right.year) && (month <= right.month) && (day <= right.day))
		status = true;
	else
		status = false;

	return status;
}

bool Date::operator>=(const Date& right)
{
	bool status;
	if (year < right.year)
		status = true;
	else if ((year == right.year) && (month < right.month))
		status = true;
	else if ((year == right.year) && (month < right.month) && (day < right.day))
		status = true;
	else
		status = false;

	return status;
}

bool Date::operator==(const Date& right)
{
	bool status;
	if (year == right.year && month == right.month && day == right.day)
		status = true;
	else
		status = false;
	return status;
}

bool Date::operator!=(const Date& right)
{
	bool status;
	if (year != right.year && month != right.month && day != right.day)
		status = true;
	else
		status = false;
	return status;
}

ostream& operator<<(ostream& output, const Date& obj)
{
	output << setfill('0') << setw(2) << obj.month << '/' << setfill('0') << setw(2) << obj.day << '/' << obj.year;

	return output;
}

istream& operator>>(istream& input, Date& obj)
{
	input >> obj.month;
	input.ignore();
	input >> obj.day;
	input.ignore();
	input >> obj.year;

	obj.checkDate();
	return input;
}
