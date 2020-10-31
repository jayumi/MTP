#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

#include "Time.h"

//Constructor
Time::Time(int hour, int minute)
{
    setTime(hour, minute);
}

//convert time to universal
void Time::convertUniversal(int hr, int min, string mer)
{
    if (hr == 12)
    {
        hr = 0;
    }
    if (mer == "AM")
    {
        setTime(hr, min);
    }
    else
    {
        setTime(hr + 12, min);
    }
    //for troubleshooting
    //cout << hour << ":" << minute << endl;
}

//SET FUNCTIONS

Time& Time::setTime(int hour, int minute)
{
    setHour(hour);
    setMinute(minute);
    return *this;
}


Time& Time::setHour(int h)
{
    hour = (h >= 0 && h < 24) ? h : 0;  //validates hour, if valid set to h, else set to 0
    return *this;
}


Time& Time::setMinute(int m)
{
    minute = (m >= 0 && m < 60) ? m : 0;  //validates minute, if valid set to m, else set to 0
    return *this;
}

//GET FUNCTIONS

//get Hour
int Time::getHour() const  //must be const since prototype is const
{
    return hour;
}

//get Minute
int Time::getMinute() const  //must be const since prototype is const
{
    return minute;
}


/*PRINT FUNCTIONS:  Normally do not modify private member data so should be const*/

void Time::printUniversal()const  //must be const since prototype is const
{
    cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << endl;
}

void Time::printStandard()const  //must be const since prototype is const
{
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
        << setfill('0') << setw(2) << minute << " "
        << (hour < 12 ? "AM" : "PM") << endl;
}

// - overloaded operator
double Time::operator-(const Time& t1)
{
    double timeDif;
    timeDif = abs((double(getHour()) + double(getMinute()) / 60) - (double(t1.hour) + double(t1.minute) / 60));
    return timeDif;
}




// << overloaded operator
ostream& operator<<(ostream& output, const Time& t1)
{
    int hr = t1.hour;
    int min = t1.minute;
    output << ((hr == 0 || hr == 12) ? 12 : hr % 12) << ":"
        << setfill('0') << setw(2) << min << " " << (hr < 12 ? "AM" : "PM") << endl;

    return output;
}

// >> overloaded operator
istream& operator>>(istream& input, Time& t1)
{
    int hr, min;
    string meridiem;
    input >> setw(2) >> hr;
    input.ignore();
    input >> setw(2) >> min;
    input.ignore();
    input >> setw(2) >> meridiem;
    // cout << "For trouble shooting" << hr << " " << min << endl;
    transform(meridiem.begin(), meridiem.end(), meridiem.begin(), ::toupper);
    t1.convertUniversal(hr, min, meridiem);
    return input;

}



