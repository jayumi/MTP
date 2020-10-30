#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Time.h"
using namespace std;

//Constructor
Time::Time(int hour, int minute)
{
	setTime(hour, minute);
}

//convert time to universal
void Time::convertUniversal(int hr, int min, bool mer)
{
	if (hr == 0)
	{
		hr = 12;
	}
	else if (hr == 12)
	{
		hr = 0;
	}
	
	if (hr <= 12 && hr >= 0)
	{
		if (mer)
		{
			setTime(hr, min);
		}
		else
		{
			setTime(hr + 12, min);
		}
	}
}

//SET FUNCTIONS
Time& Time::setTime(int hour, int minute)
{
	setHour(hour);
	setMinute(minute);
	return *this;
}

Time& Time::setHour(int h)
{
	hour = (h >= 0 && h < 24) ? h : 0;
	return *this;
}

Time& Time::setMinute(int m)
{
	minute = (m >= 0 && m < 24) ? m : 0;
	return *this;
}

//GET FUNCTIONS
int Time::getHour() const
{
	return hour;
}

int Time::getMinute() const
{
	return minute;
}

//PRINT FUNCTIONS
void Time::printUniversal() const
{
	cout << setfill('0') << setw(2) << hour << ":"
		<< setw(2) << minute << endl;
}

void Time::printStandard() const
{
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
		<< setfill('0') << setw(2) << minute << " " 
		<< (hour < 12 ? "AM" : "PM" ) << endl;
}

//Overload -operator
double Time::operator-(const Time& t1)
{
	double timeDiff;
	timeDiff = double(hour) + double(minute) / 60.0 - (double(t1.hour) - double(t1.minute) / 60.0);
	return abs(timeDiff);
}

// << overload operator
ostream& operator <<(ostream& output, const Time& t1)
{
	output << ((t1.hour == 0 || t1.hour == 12) ? 12 : t1.hour % 12)
		<< ":" << setfill('0') << t1.minute << (t1.hour < 12 ? "AM" : "PM");
	return output;
}

istream& operator >>(istream& input, Time& t1)
{
	int hr, min;
	string meridiem;
	input >> setw(2) >> hr;
	input.ignore();
	input >> setw(2) >> min;
	input.ignore();
	input >> setw(2) >> meridiem;
	
	if (meridiem == "AM" || meridiem == "am")
	{
		t1.convertUniversal(hr, min, false);
	}
	else if (meridiem == "PM" || meridiem == "pm")
	{
		t1.convertUniversal(hr, min, false);
	}
	return input;
}
