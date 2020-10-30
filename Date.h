#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator << (ostream&, const Date&);
	friend istream& operator >> (istream&, Date&);

private: 
	int month;
	int day;
	int year;
	int checkDate(int) const;

public:
	Date(int = 1, int = 1, int = 1990);

	//SET
	Date& setDate(int, int, int);
	Date& setMonth(int);
	Date& setDay(int);
	Date& setYear(int);
	
	//GET
	int getMonth() const;
	int getDay() const;
	int getYear() const;

	//OVERLOAD OPERATORS
	bool operator< (const Date&);
	bool operator> (const Date&);
	bool operator<= (const Date&);
	bool operator>= (const Date&);
	bool operator== (const Date&);
	bool operator!= (const Date&);
};

#endif // !DATE_H
