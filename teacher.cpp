#define _CRT_SECURE_NO_WARNINGS
#include "teacher.h"
#include "teacher.h"
#include <iostream>
#include <string>
#include <cstring>
#include "digit.h"

using namespace std;

teacher::teacher()
{
    cout << "Teacher constructor" << endl;
    groupsNum = 0;
    subjectsNum = 0;
    setType();
    setName();
    setGroups();
    setSubjects();
}

teacher::teacher(char** data)
{
    cout << "Teacher constructor" << endl;

    setType();
    name.setName(data);

    if (*data[2] == ' ')
        data[2]++;

    if (*data[3] == ' ')
        data[3]++;

    groupsNum = 1;
    studyGroups = new char* [1];
    *studyGroups = new char[strlen(data[2]) + 1];
    strcpy(*studyGroups, data[2]);

    subjectsNum = 1;
    subjects = new char* [1];
    *subjects = new char[strlen(data[3]) + 1];
    strcpy(*subjects, data[3]);

    *data[2]--;
    *data[3]--;
}

teacher::teacher(const teacher&)
{}

teacher::~teacher()
{
    cout << "Teacher destructor" << endl;

    while (groupsNum != 0)
    {
        delete* (studyGroups + groupsNum - 1);
        groupsNum--;
    }
    delete[] studyGroups;

    while (subjectsNum != 0)
    {
        delete* (subjects + subjectsNum - 1);
        subjectsNum--;
    }
    delete[] subjects;
}

void teacher::setName()
{
    name.setName();
}

void teacher::setGroups()
{
    string str;
    const char* arr;

    cout << "Quantity of groups: ";

    while (true)
    {
        getline(cin, str);
        arr = str.c_str();

        if (digitCounter(atoi(arr)) != strlen(arr))
        {
            cout << "You should enter the quantity of groups";
            cout << endl << "Quantity of groups: ";
            continue;
        }
        else
        {
            groupsNum = atoi(arr);
            break;
        }
    }

    studyGroups = new char* [groupsNum];

    int i = 0;
    int arrlen;

    while (i != groupsNum)
    {
        cout << "Group " << i + 1 << " title: ";

        while (true)
        {
            getline(cin, str);
            if (!str.empty())
                break;
        }

        arr = str.c_str();
        arrlen = strlen(arr);
        *(studyGroups + i) = new char[arrlen + 1];
        strcpy(*(studyGroups + i), arr);
        ++i;
    }
}

void teacher::setSubjects()
{
    string str;
    const char* arr;

    cout << "Quantity of subjects: ";

    while (true)
    {
        getline(cin, str);
        arr = str.c_str();

        if (digitCounter(atoi(arr)) != strlen(arr))
        {
            cout << "You should enter the quantity of subjects";
            cout << endl << "Quantity of subjects: ";
            continue;
        }
        else
        {
            subjectsNum = atoi(arr);
            break;
        }
    }

    subjects = new char* [subjectsNum];

    int i = 0;
    int arrlen;

    while (i != subjectsNum)
    {
        cout << "Subject " << i + 1 << ": ";

        while (true)
        {
            getline(cin, str);
            if (!str.empty())
                break;
        }

        arr = str.c_str();
        arrlen = strlen(arr);
        *(subjects + i) = new char[arrlen + 1];
        strcpy(*(subjects + i), arr);
        ++i;
    }
}

void teacher::setType()
{
    type = "teacher";
}

char** teacher::getGroups()
{
    return studyGroups;
}

char** teacher::getSubjects()
{
    return subjects;
}

void teacher::getData(char** arr)
{
    string str;

    arr[0] = new char[8];
    strcpy(arr[0], "Teacher");

    arr[1] = new char[getName().size() + 8];
    strcpy(arr[1], "Name: ");
    strcat(arr[1], getName().c_str());

    for (int i = 0; i < groupsNum; ++i)
    {
        str += *(studyGroups + i);

        if (i != groupsNum - 1)
            str += ", ";
    }

    arr[2] = new char[str.size() + 16];
    strcpy(arr[2], "Study groups: ");
    strcat(arr[2], str.c_str());

    str.clear();
    for (int i = 0; i < subjectsNum; ++i)
    {
        str += *(subjects + i);

        if (i != subjectsNum - 1)
            str += ", ";
    }

    arr[3] = new char[str.size() + 12];
    strcpy(arr[3], "Subjects: ");
    strcat(arr[3], str.c_str());
}

string teacher::getName()
{
    return name.getName();
}

string teacher::getType()
{
    return type;
}

void teacher::show()
{
    cout << "Name: " << getName() << endl;

    cout << "Groups: ";
    for (int i = 0; i < groupsNum; ++i)
    {
        cout << *(studyGroups + i);
        if (i != groupsNum - 1)
            cout << ", ";
    }

    cout << endl;

    cout << "Subjects: ";
    for (int i = 0; i < subjectsNum; ++i)
    {
        cout << *(subjects + i);
        if (i != subjectsNum - 1)
            cout << ", ";
    }

    cout << endl;
}
