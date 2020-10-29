#ifndef COURSE_H
#define COURSE_H
#include <string>
#include "Date.h"
#include "Time.h"
using namespace std;

class Course
{

	friend ostream& operator<<(ostream&, const Course&);

private:
	string courseNum;
	string courseName;
	string courseDays;
	double courseUnits;

	Date startDate;
	Date endDate;
	Time startTime;
	Time endTime;

public:
	Course(const string& = " ", const string& = " ", const string& = " ", const double = 0, 
		const Date& = Date(), const Date& = Date(), const Time& = Time(), const Time& = Time());
	~Course();

	//GET
	string getCourseNum() const;
	string getCourseName() const;
	string getCourseDays() const;
	double getCourseUnit() const;

	Date getStartDate() const;
	Date getEndDate() const;
	Time getStartTime() const;
	Time getEndTime() const;


	//SET
	Course& setCourseNum(const string&);
	Course& setCourseName(const string&);
	Course& setCourseDays(const string&);
	Course& setCourseUnit(double);

	double calcDailyDuration() const;
};
#endif // !COURSE_H
