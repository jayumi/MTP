#ifndef SEMESTER_H	
#define SEMESTER_H
#include <iostream>
#include "Time.h"
#include "Date.h"
#include "Course.h"
using namespace std;

class Semester
{
	friend ostream& operator<<(ostream&, const Semester&);
	friend istream& operator>>(istream&, Semester&);

private:
	string semesterName;
	Date startDate;
	Date endDate;

public:
	Semester(const string & = "NULL", const Date & = Date(), const Date & = Date());

	//GET
	string getSemesterName() const;
	Date getStartDate() const;
	Date getEndDate() const;

	//SET
	Semester& setSemesterName(string);
	Semester& setStartDate(int, int, int);
	Semester& setEndDate(int, int, int);
};
#endif // !SEMESTER_H
