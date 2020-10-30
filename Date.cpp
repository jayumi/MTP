#include <iostream>
#include <iomanip>
#include "Date.h"
using namespace std;

Date::Date(int m, int d, int y)
{
	setDate(m, d, y);
}

Date& Date::setDate(int m, int d, int y)
{
	setMonth(m);
	setDay(d);
	setYear(y);

	return *this;
}

int Date::checkDate(int check) const
{
	static const int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (check > 0 && check <= daysPerMonth[month])
	{
		return check;
	}

	if ((month == 2 && day == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
		&& (day <= 0 || day > daysPerMonth[month]))
	{
		return check;
	}

	cout << "Invalid Day " << check << " was set to 1" << endl;
	return 1;
}

Date& Date::setMonth(int m)
{
	month = (m <= 1 || m <= 12) ? m : 0;
	return *this;
}

Date& Date::setDay(int d)
{
	day = d;
	return *this;
}

Date& Date::setYear(int y)
{
	year = (y > 0) ? y : 0;
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
	if (year < right.year)
	{
		return true;
	}
	else if ((year == right.year) && (month < right.month)) 
	{
		return true;
	}
	else if ((year == right.year) && (month < right.month) && (day < right.day))
	{
		return false;
	}
	else
	{
		return false;
	}
	return false;
}

bool Date::operator>(const Date& right)
{
	if (year > right.year)
	{
		return true;
	}
	else if ((year == right.year) && (month > right.month))
	{
		return true;
	}
	else if ((year == right.year) && (month > right.month) && (day > right.day))
	{
		return false;
	}
	else
	{
		return false;
	}
	return false;
}

bool Date::operator<=(const Date& right)
{
	if (year <= right.year)
	{
		return true;
	}
	else if ((year == right.year) && (month <= right.month))
	{
		return true;
	}
	else if ((year == right.year) && (month <= right.month) && (day <= right.day))
	{
		return false;
	}
	else
	{
		return false;
	}
	return false;
}

bool Date::operator>=(const Date& right)
{
	if (year >= right.year)
	{
		return true;
	}
	else if ((year == right.year) && (month >= right.month))
	{
		return true;
	}
	else if ((year == right.year) && (month >= right.month) && (day >= right.day))
	{
		return false;
	}
	else
	{
		return false;
	}
	return false;
}

bool Date::operator==(const Date& right)
{
	return (month == right.month && day == right.day && year == right.year);
}

bool Date::operator!=(const Date& right)
{
	if (year != right.year && month != right.month && day != right.day)
		return true;
	else 
	{
		return false;
	}
	return false;
}

ostream& operator<<(ostream& output, const Date& obj)
{
	output << setfill('0') << setw(2) << obj.month << '/' << setfill('0') 
		<< setw(2) << obj.day << '/' << obj.year;
	return output;
}

istream& operator>>(istream& input, Date& obj)
{
	input >> obj.month;
	input.ignore();
	input >> obj.day;
	input.ignore();
	input >> obj.year;
	return input;
}
