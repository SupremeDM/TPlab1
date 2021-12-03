#define _CRT_SECURE_NO_WARNINGS

#include "staff.h"
#include <iostream>
#include <cstring>
#include <conio.h>

#define NUM_FIRST  0x20
//#define NUM_BAD    0x21
#define NUM_SEPAR  0x22
#define NUM_END    0x23
#define NUM_LEN    0x24

using namespace std;

staff::staff()
{
    cout << "Staff constructor" << endl;
    setType();
    setName();
    setPosition();
    //setNumber();
    setArea();
}

staff::staff(char** data)
{
    cout << "Staff constructor" << endl;

    setType();
    name.setName(data);

    if (*data[2] == ' ')
        *data[2]++;

    if (*data[3] == ' ')
        *data[3]++;

    if (*data[4] == ' ')
        *data[4]++;

    position = new char[strlen(data[2]) + 1];
    strcpy(position, data[2]);

    responsibilityArea = new char[strlen(data[3]) + 1];
    strcpy(responsibilityArea, data[3]);

    strncpy(telephoneNumber, data[4], 20);

    *data[2]--;
    *data[3]--;
    *data[4]--;
}

staff::staff(const staff& s)
{}

staff::~staff()
{
    cout << "Staff destructor" << endl;
    delete position;
    delete responsibilityArea;
}

void staff::setName()
{
    name.setName();
}

void staff::setPosition()
{
    string str;
    const char* arr;
    int arrlen;

    cout << "Position: ";

    while (true)
    {
        getline(cin, str);
        if (!str.empty())
            break;
    }

    arr = str.c_str();
    arrlen = strlen(arr);
    position = new char[arrlen + 1];
    strcpy(position, arr);
}
/*void staff::setNumber()
{
    char arr[21];
    char c;
    int i = 0;
    cout << "Number:";
    c = getchar();
    cout << c;
    arr[i] = c;
    ++i;
    strcpy(telephoneNumber, arr);
}*/





void staff::setArea()
{
    string str;
    const char* arr;
    int arrlen;

    cout << "Responsibility area: ";

    while (true)
    {
        getline(cin, str);
        if (!str.empty())
            break;
    }

    arr = str.c_str();
    arrlen = strlen(arr);
    responsibilityArea = new char[arrlen + 1];
    strcpy(responsibilityArea, arr);
}

void staff::setType()
{
    type = "staff";
}

void staff::getData(char** arr)
{
    arr[0] = new char[6];
    strcpy(arr[0], "Staff");

    arr[1] = new char[getName().size() + 8];
    strcpy(arr[1], "Name: ");
    strcat(arr[1], getName().c_str());

    arr[2] = new char[strlen(position) + 11];
    strcpy(arr[2], "Position: ");
    strcat(arr[2], position);

    arr[3] = new char[strlen(responsibilityArea) + 25];
    strcpy(arr[3], "Area of responsibility: ");
    strcat(arr[3], responsibilityArea);

    /* arr[4] = new char[30];
     strcpy( arr[4], "Telephone number: " );
     strcat( arr[4], telephoneNumber );*/
}

char* staff::getPosition()
{
    return position;
}

/*char *staff::getNumber()
{
  return telephoneNumber;
}*/

char* staff::getArea()
{
    return responsibilityArea;
}

string staff::getName()
{
    return name.getName();
}

string staff::getType()
{
    return type;
}

void staff::show()
{
    cout << "Name: " << getName() << "\nPosition: " << getPosition()/* << "\nNumber: "
      << getNumber()*/ << "\nResponsibility area: " << getArea() << endl;
}
