#ifndef DATE_H
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
	void checkDate();

public:
	Date(int = 1, int = 1, int = 1990);
	~Date();
	Date& setDate(int, int, int);
	Date& setMonth(int);
	Date& setDay(int);
	Date& setYear(int);


	int getMonth() const;
	int getDay() const;
	int getYear() const;

	bool operator< (const Date&);
	bool operator> (const Date&);
	bool operator<= (const Date&);
	bool operator>= (const Date&);
	bool operator== (const Date&);
	bool operator!= (const Date&);
};

#endif // !DATE_H
