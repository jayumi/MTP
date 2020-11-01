#include <iostream>
#include <string>
#include <iomanip>
#include "CourseSchedule.h"
using namespace std;

CourseSchedule::CourseSchedule(const string& name, const Semester& sem, int max)
	:coursePtr(nullptr), studentName(name), semester(sem), maxSize(max), numOfCourses(0)
{
	coursePtr = new Course[maxSize];
}

CourseSchedule::CourseSchedule(const CourseSchedule&)
	: coursePtr(nullptr), studentName(" "), maxSize(0), numOfCourses(0)
{

}

CourseSchedule::~CourseSchedule()
{
	delete[] coursePtr;
	coursePtr = nullptr;
}

//GET
string CourseSchedule::getStudentName() const
{
	return studentName;
}

Semester CourseSchedule::getSemester() const
{
	return semester;
}

int CourseSchedule::getNumOfCourses() const
{
	return numOfCourses;
}

//SET StudentName Function
void CourseSchedule::setStudentName(string name)
{
	this->studentName = name;
}

//Check Valid Dates - Utility Function
bool CourseSchedule::checkDates(const Semester& sem, const Date& startDate, const Date& endDate) const
{
	if (sem.getStartDate() > startDate)
	{
		return false;
	}
	else if (sem.getEndDate() < endDate)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool CourseSchedule::addCourse(const Course& addCourse)
{
	if ((numOfCourses < maxSize) && (checkDates(semester, addCourse.getStartDate(), addCourse.getEndDate())))
		{
			for (int count = 0; count < numOfCourses; count++)
			{
				if (coursePtr[count].getCourseNum() == addCourse.getCourseNum()
					&& coursePtr[count].getCourseName() == addCourse.getCourseName())
				{
					return false;
				}
			}
			coursePtr[numOfCourses] = addCourse;
			numOfCourses++;
			return true;
		}
		else
		{
			return false;
		}
}

bool CourseSchedule::removeCourse(const Course& remCourse)
{
	if (numOfCourses > 0)
	{
		int num = -1;
		for (int count = 0; count < numOfCourses; count++)
		{
			if (coursePtr[count].getCourseNum() == remCourse.getCourseNum())
			{
				num = count;
			}
		}
		if (num != -1)
		{
			coursePtr[num] = coursePtr[numOfCourses - 1];
			numOfCourses--;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void CourseSchedule::operator=(const CourseSchedule&) const
{

}

// OUTPUT OVERLOAD
ostream& operator<<(ostream& output, const CourseSchedule& obj)
{
	output << "CLASS SCHEDULE\n"
		<< "------------------------------------------\n"
		<< "Name: " << obj.getStudentName() << endl
		<< "Number of Classes: " << obj.numOfCourses << endl
		<< "------------------------------------------\n";
	
	for (int count = 0; count < obj.numOfCourses; count++)
	{
		cout << obj.coursePtr[count] << "\n\n";
	}
	return output;
}
