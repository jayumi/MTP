#include <iostream>
#include <iomanip>
#include <string>
#include "Course.h"
using namespace std;

Course::Course(const string& num, const string& name, const string& days, const double units,
	const Date& startD, const Date& endD, const Time& startT, const Time& endT)
	: courseNum(num), courseName(name), courseDays(days), courseUnits(units),
	startDate(startD), endDate(endD), startTime(startT), endTime(endT)
{
	//cout << "This is the constructor" << endl; (TESTING PURPOSES)
}

Course::~Course()
{
	cout << "The Course has been deleted." << endl;
}

//GET FUNCTIONS
string Course::getCourseNum() const
{
	return courseNum;
}

string Course::getCourseName() const
{
	return courseName;
}

string Course::getCourseDays() const
{
	return courseDays;
}

double Course::getCourseUnit() const
{
	return courseUnits;
}

//Date GET Functions
Date Course::getStartDate() const
{
	return startDate;
}
 
Date Course::getEndDate() const
{
	return endDate;
}

//Time GET Functions
Time Course::getStartTime() const
{
	return startTime;
}

Time Course::getEndTime() const
{
	return endTime;
}

//SET

Course& Course::setCourseNum(const string& num)
{
	courseNum = num;
	return *this;
}

Course& Course::setCourseName(const string& name)
{
	courseName = name;
	return *this;
}

Course& Course::setCourseDays(const string& days)
{
	courseDays = days;
	return *this;
}

Course& Course::setCourseUnit(const double units)
{
	courseUnits = units;
	return *this;
}

double Course::calcDailyDuration() const
{
	double duration;
	duration = getStartTime() - getEndTime();
	return duration;
}

ostream& operator<<(ostream& output, const Course& obj)
{
	output << "Course Info:\t" << obj.courseNum << " -- " << obj.courseName << endl
		<< "# of Units: \t" << obj.courseUnits << endl
		<< "Course Dates:\t" << obj.startDate << " - " << obj.endDate << "\n"
		<< "Meeting Days:\t" << obj.courseDays << "\n"
		<< "Meeting Time:\t" << obj.startTime << " - " << obj.endTime << "\n"
		<< "Daily Duration:\t" << obj.calcDailyDuration() << " hours\n";

	return output;
}
