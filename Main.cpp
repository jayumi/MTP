#include "CourseSchedule.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Date startDate;
    Date endDate;
    int maxClass;
    string studentName, semesterName;
    char selection;

    cout << "Enter your name: ";
    getline(cin, studentName);
    cout << "Enter semester name: ";
    getline(cin, semesterName);
    cout << "Enter the start date (MM/DD/YYYY): ";
    cin >> startDate;
    cout << "Enter the end date (MM/DD/YYYY): ";
    cin >> endDate;
    cout << "Enter maximum number of classes: ";
    cin >> maxClass;

    Semester semester(semesterName, startDate, endDate);
    CourseSchedule courseSchedule(studentName, semester, maxClass);

    do {
        cout << "\nCOURSE ENTRY MENU FOR: " << semester << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "1) Enter a new course" << endl;
        cout << "2) Remove a course" << endl;
        cout << "3) Print a Semester Schedule" << endl;
        cout << "q) Quit the program" << endl;
        cin >> selection;
        cin.ignore();

        switch (selection) 
        {
        case '1':
        {
            Time startTime;
            Time endTime;

            Date startDate;
            Date endDate;

            double courseUnits;
            string courseName, courseNum, meetingDays;

            if (courseSchedule.getNumOfCourses() == maxClass)
            {
                cout << "\nYou've reached the max amount of classes you can take this semester." << endl;
                break;
            }

            cout << "\n\nEnter course number: ";
            getline(cin, courseNum);
            cout << "Enter course name: ";
            getline(cin, courseName);
            cout << "Number of units for course: ";
            cin >> courseUnits;
            cin.ignore();
            cout << "Enter course meeting days (MTWTHF): ";
            getline(cin, meetingDays);
            cout << "Enter the starting time (00:00 AM/PM): ";
            cin >> startTime;
            cout << "Enter the ending time (00:00 AM/PM): ";
            cin >> endTime;
            cout << "Enter the start date (MM/DD/YYYY): ";
            cin >> startDate;
            cout << "Enter the end date (MM/DD/YYYY): ";
            cin >> endDate;

            Course course(courseNum, courseName, meetingDays, courseUnits, startDate, endDate, startTime, endTime);

            if (courseSchedule.addCourse(course))
            {
                cout << "\nCourse has been successfully added." << endl;
            }
            else
            {
                cout << "\nERROR: INVALID INPUT!" << endl;
            }
            break;
        }

        case '2':
        {
            Time startTime;
            Time endTime;

            Date startDate;
            Date endDate;

            double courseUnits;
            string courseName, courseNum, meetDays;

            if (courseSchedule.getNumOfCourses() == 0)
            {
                cout << "\nYou currently have no courses to remove.\n";
                break;
            }
            cout << "\nEnter Course Number: ";
            getline(cin, courseNum);
            cout << "Enter Course Name: ";
            getline(cin, courseName);

            Course course(courseNum, courseName);

            if (courseSchedule.removeCourse(course)) 
            {
                cout << "\nThe course has been successfully removed.\n";
            }
            else 
            {
                cout << "\nERROR: INVALID INPUT!" << endl;
            }
            break;
        }

        case '3':
        {
            cout << courseSchedule;
            break;
        }

        case 'Q':
        case 'q':
        {
            cout << "\nYou've chosen to quit the program." << endl;
            break;
        }
        default:
            cout << "\nInvalid choice. Please try again." << endl;
            break;
        }
    } while (toupper(selection) != ('Q'));

    system("PAUSE");
    return 0;
}
