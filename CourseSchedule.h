#ifndef COURSESCHEDULE_H
#define COURSESCHEDULE_H
#include <iostream>
#include "Date.h"
#include "Time.h"
#include "Semester.h"
#include "Course.h"
using namespace std;

class CourseSchedule
{
	friend ostream& operator<<(ostream&, const CourseSchedule&);

private:
	string studentName;
	Semester semester;
	Course* coursePtr;
	int maxSize; //max number of courses
	int numOfCourses;
	bool checkDates(const Semester&, const Date&, const Date&) const; //utility function

public:
	CourseSchedule(const string & = "Student Name", const Semester & = Semester(), int = 0);
	CourseSchedule(const CourseSchedule&);
	~CourseSchedule();

	//GET
	string getStudentName() const;
	Semester getSemester() const;
	int getNumOfCourses() const;

	//SET
	void setStudentName(string);

	bool addCourse(const Course&);
	bool removeCourse(const Course&);

	void operator=(const CourseSchedule&) const;

};
#endif // !CourseSchedule_H
