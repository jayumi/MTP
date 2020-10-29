#ifndef SEMESTER_H	
#define SEMESTER_H
#include <iostream>
#include "Date.h"
using namespace std;

class Semester : public Date
{
	friend ostream& operator<<(ostream&, const Semester&);
	friend istream& operator>>(istream&, Semester&);

private:
	string semesterName;
	Date startDate;
	Date endDate;

public:
	Semester();
	Semester(string, Date, Date);

	//GET
	string geSemesterName() const;
	int getSemStartMonth() const;
	int getSemStartDay() const;
	int getSemStartYear() const;
	int getSemEndMonth() const;
	int getSemEndDay() const;
	int getSemEndYear() const;

	//SET
	void setSemesterName(string&);
	void setSemStartMonth(int);
	void setSemStartDay(int);
	void setSemStartYear(int);
	void setSemEndMonth(int);
	void setSemEndDay(int);
	void setSemEndYear(int);
};
#endif // !SEMESTER_H
