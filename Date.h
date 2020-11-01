
#ifndef DATE_H
#define DATE_H
using namespace std;

class Date
{
    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);
    
    private:
        int month; //1-12
        int day; //1-31 depending on month
        int year; //any year over 1 and not neg
        void checkDate(); // validate date - sets dates out of range to month - 1, day - 1, year 2000

        
    public:
        Date(int = 1, int = 1, int = 2000);
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

#endif
