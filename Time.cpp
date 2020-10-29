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

//Convert Time to Universal
void Time::convertUniversal(int hr, int min, string mer)
{
	if (hr == 12)
	{
		hr = 0;
	}
	if (mer == "AM")
	{
		setTime(hr, min);
	}
	else
	{
		setTime(hr + 12, min);
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
	timeDiff = abs((double(getHour()) + double(getMinute()) / 60) - (double(t1.hour)
		+ double(t1.minute) / 60));
	
	return timeDiff;
}

// << overload operator
ostream& operator <<(ostream& output, const Time& t1)
{
	int hr = t1.hour;
	int min = t1.minute;
	output << ((hr == 0 || hr == 12) ? 12 : hr % 12) << ":"
	<< setfill('0') << setw(2) << min << " " << (hr < 12 ? "AM" : "PM") << endl;

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
	transform(meridiem.begin(), meridiem.end(), meridiem.begin(), ::toupper);
	t1.convertUniversal(hr, min, meridiem);
	
	return input;
}
