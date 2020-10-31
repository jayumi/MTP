#include <iostream>
#include <iomanip>
using namespace std;

#include "Date.h"

//constructor validates month and calls utility function to validate day
Date::Date(int mn, int dy, int yr)
{
    setDate(mn, dy, yr);
}

//DESTRUCTOR
Date::~Date()
{

}

Date& Date::setDate(int mn, int dy, int yr)
{
    setMonth(mn);
    setDay(dy);
    setYear(yr);
    
    return *this;
}

//utility functino to check dates
void Date::checkDate()
{
    static const int daysPerMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    if(month <= 0 || month > 12)
    {
        month = 1;
    }
    
    if (!(month == 2 && day == 29 && (year  % 400 == 0 || (year % 4  == 0 && year % 100 != 0))) && (day <= 0 || day > daysPerMonth[month]))
    {
        day = 1;
    }

    
    if (year <= 1989)
    {
        year = 1990;
    }

}



Date& Date::setMonth(int mn)
{
    month = mn;
    checkDate();
    return *this;
}

Date& Date::setDay(int dy)
{

    day = dy;
    checkDate();
    return *this;
}

Date& Date::setYear(int yr)
{
    year = yr;
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


bool Date::operator<(const Date &d1)
{
    bool flag;
    
    if (year < d1.year)
        flag = true;
    else if ((year == d1.year) && (month < d1.month))
        flag = true;
    else if ((year == d1.year) && (month < d1.month) && (day < d1.day))
        flag = true;
    else
        flag = false;
    
    return flag;
}

bool Date::operator>(const Date &d1)
{
    bool flag;
    if (year > d1.year)
        flag = true;
    else if ((year == d1.year) && (month > d1.month))
        flag = true;
    else if ((year == d1.year) && (month == d1.month) && (day > d1.day))
        flag = true;
    else
        flag = false;
    return flag;
}

bool Date::operator<=(const Date &d1)
{
    bool flag;
    
    if (year <= d1.year)
        flag = true;
    else if ((year == d1.year) && (month <= d1.month))
        flag = true;
    else if ((year == d1.year) && (month == d1.month) && (day <= d1.day))
        flag = true;
    else
        flag = false;
    
    return flag;
}

bool Date::operator>=(const Date &d1)
{
    bool flag;
    
    if (year >= d1.year)
        flag = true;
    else if ((year == d1.year) && (month >= d1.month))
        flag = true;
    else if ((year == d1.year) && (month == d1.month) && (day >= d1.day))
        flag = true;
    else
        flag = false;
    
    return flag;
}

bool Date::operator==(const Date &d1)
{
    bool flag;
    
    if((month == d1.month) && (day == d1.day) && (year == d1.year))
        flag = true;
    else
        flag = false;
    
    return flag;
}

bool Date::operator!=(const Date &d1)
{
    bool flag;
    
    if((month != d1.month) || (day != d1.day) || (year != d1.year))
        flag = true;
    else
        flag = false;
    
    return flag;
}

ostream& operator<<(ostream& output,const Date& obj)
{
    output << setfill ('0') << setw(2) << obj.month << '/' <<  setfill ('0') << setw(2) << obj.day << '/'  << obj.year;
    
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
