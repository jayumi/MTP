#pragma once
#include <string>
using namespace std;
#ifndef TIME_H
#define TIME_H

class Time
{
	friend ostream& operator<<(ostream&, const Time&);
	friend istream& operator>>(istream&, Time&);

private:
	int hour;
	int minute;
	void convertUniversal(int, int, string);

public:
	Time(int = 0, int = 0);

	Time& setTime(int, int);
	Time& setHour(int);
	Time& setMinute(int);

	int getHour() const;
	int getMinute() const;

	double operator-(const Time&); //overload - operator

	void printUniversal() const;
	void printStandard() const;

};
#endif // !TIME_H
