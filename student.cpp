#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include "student.h"
#include <iostream>
#include <string>
#include <cstring>
#include "digit.h"
#include <conio.h>

#define MARK_FORMAT   0x40
#define DOUBLE_DOT    0x41
#define BAD_COURSE    0x50

using namespace std;

student::student()
{
    cout << "Student constructor" << endl;
    setType();
    setName();
    setGroup();
    setSpecialty();
    setCourse();
    setMark();
}

student::student(char** data)
{
    cout << "Student constructor" << endl;

    setType();
    name.setName(data);

    if (*data[2] == ' ')
        *data[2]++;

    if (*data[3] == ' ')
        *data[3]++;

    group = new char[strlen(data[2]) + 1];
    strcpy(group, data[2]);

    specialty = new char[strlen(data[3]) + 1];
    strcpy(specialty, data[3]);

    currentCourse = atoi(data[4]);
    averageMark = atof(data[5]);

    *data[2]--;
    *data[3]--;
}

student::student(const student&)
{}

student::~student()
{
    cout << "Student destructor" << endl;
    delete group;
    delete specialty;
}

void student::setName()
{
    name.setName();
}

void student::setGroup()
{
    string str;
    const char* arr;
    int arrlen;

    cout << "Group: ";

    while (true)
    {
        getline(cin, str);
        if (!str.empty())
            break;
    }

    arr = str.c_str();
    arrlen = strlen(arr);
    group = new char[arrlen + 1];
    strcpy(group, arr);
}

void student::setSpecialty()
{
    string str;
    const char* arr;
    int arrlen;

    cout << "Specialty: ";

    while (true)
    {
        getline(cin, str);
        if (!str.empty())
            break;
    }

    arr = str.c_str();
    arrlen = strlen(arr);
    specialty = new char[arrlen + 1];
    strcpy(specialty, arr);
}

void student::setCourse()
{
    while (true)
    {
        cout << "Course: ";
        currentCourse = getNum();
        if (currentCourse > 99 || currentCourse == 0)
        {
            cout << "Current course cannot be like that" << endl;
            continue;
        }

        break;
    }
}



void student::setMark()
{
    string str;
    char c;
    int dot = 0;

    cout << "Average mark: ";

    while (true)
    {
        try
        {
            c = _getch();

            if (c == '.')
            {
                if (dot == 0)
                {
                    if (str.empty())
                        throw MARK_FORMAT;

                    dot = 1;
                    cout << c;
                    str += c;
                    continue;
                }
                else
                    throw DOUBLE_DOT;
            }

            if (c < '0' || c > '9')
            {
                if (c == '\r')
                {
                    cout << endl;
                    str += '\0';
                    break;
                }
                else
                    throw MARK_FORMAT;
            }

            cout << c;
            str += c;
        }
        catch (int exc)
        {
            cout << endl;

            switch (exc)
            {
            case MARK_FORMAT:
                cout << "Average mark shold be written as a float type number";
                break;

            case DOUBLE_DOT:
                cout << "Average mark shold be written as a float type number (with only one dot)";
                break;
            }

            str.clear();
            cout << endl << "Average mark: ";
            continue;
        }
    }

    averageMark = atof(str.c_str());
}

void student::setType()
{
    type = "student";
}

void student::getData(char** arr)
{
    char tmp[3];

    arr[0] = new char[8];
    strcpy(arr[0], "Student");

    arr[1] = new char[getName().size() + 7];
    strcpy(arr[1], "Name: ");
    strcat(arr[1], getName().c_str());

    arr[2] = new char[strlen(group) + 9];
    strcpy(arr[2], "Group: ");
    strcat(arr[2], group);

    arr[3] = new char[strlen(specialty) + 12];
    strcpy(arr[3], "Specialty: ");
    strcat(arr[3], specialty);

    arr[4] = new char[20];
    strcpy(arr[4], "Current course: ");
    //strcat( arr[4], itoa( currentCourse, tmp, 10 ) );

    arr[5] = new char[30];
    sprintf(arr[5], "Average mark: %.1f", averageMark);
}

char* student::getGroup()
{
    return group;
}

char* student::getSpecialty()
{
    return specialty;
}

int student::getCourse()
{
    return currentCourse;
}

float student::getMark()
{
    return averageMark;
}

string student::getName()
{
    return name.getName();
}

string student::getType()
{
    return type;
}

void student::show()
{
    cout << "Name: " << getName() << "\nGroup: " << getGroup() << "\nSpecialty: "
        << getSpecialty() << "\nCourse: " << getCourse() << "\nAverage mark: " << getMark() << endl;
}
