#define _CRT_SECURE_NO_WARNINGS
#include "name.h"
#include <iostream>
#include <conio.h>
#define NAME_BAD 0x10
#define NAME_LEN 0x11
#include <iostream>
using namespace std;
using namespace std;

name::name()
{
	cout << "Name constructor" << endl;
}

name::~name()
{
	cout << "Name destructor" << endl;
	delete first;
	delete surname;
	delete patronymic;
}

void name::setName()
{
	string str;
	char c;
	int i = 0;

	cout << "Surname: ";

	while (i < 3)
	{
		try
		{
			c = _getch();

			if (c == '\r')
			{
				if (str != "")
				{
					if (i == 0)
					{
						surname = new char[strlen(str.c_str()) + 1];
						strcpy((char*)surname, str.c_str());
						cout << endl << "Name: ";
						str.clear();
						++i;
						continue;
					}
					else if (i == 1)
					{
						first = new char[strlen(str.c_str()) + 1];
						strcpy((char*)first, str.c_str());
						cout << endl << "Patronymic: ";
						str.clear();
						++i;
						continue;
					}
					else
					{
						patronymic = new char[strlen(str.c_str()) + 1];
						strcpy((char*)patronymic, str.c_str());
						cout << endl;
						break;
					}
				}
				else
					throw NAME_LEN;
			}

			if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
				throw NAME_BAD;

			cout << c;
			str += c;
		}
		catch (int exc)
		{
			cout << endl;

			switch (exc)
			{
			case NAME_BAD:
				cout << "It can be only letters" << endl;
				break;

			case NAME_LEN:
				cout << "It can be minimum 1 letter" << endl;
				break;
			}

			str.clear();

			if (i == 0)
				cout << "Surname: ";
			else if (i == 1)
				cout << "Name: ";
			else if (i == 2)
				cout << "Patronymic: ";

			continue;
		}
	}
}

void name::setName(char** data)
{
	char* arr;
	string str;

	arr = new char[strlen(data[1])];
	strcpy(arr, data[1]);

	while ((*arr < 'a' || *arr > 'z') && (*arr < 'A' || *arr > 'Z'))
		arr++;

	while (*arr >= 'a' && *arr <= 'z' || *arr >= 'A' && *arr <= 'Z')
	{
		str += *arr;
		arr++;
	}

	surname = new char[str.size() + 1];
	strcpy((char*)surname, str.c_str());

	str.clear();
	while ((*arr < 'a' || *arr > 'z') && (*arr < 'A' || *arr > 'Z'))
		arr++;

	while (*arr >= 'a' && *arr <= 'z' || *arr >= 'A' && *arr <= 'Z')
	{
		str += *arr;
		arr++;
	}

	first = new char[str.size() + 1];
	strcpy((char*)first, str.c_str());

	str.clear();
	while ((*arr < 'a' || *arr > 'z') && (*arr < 'A' || *arr > 'Z'))
		arr++;

	while (*arr >= 'a' && *arr <= 'z' || *arr >= 'A' && *arr <= 'Z')
	{
		str += *arr;
		arr++;
	}

	patronymic = new char[str.size() + 1];
	strcpy((char*)patronymic, str.c_str());
}

string name::getName()
{
	string str = surname;
	str += ' ';
	str += first;
	str += ' ';
	str += patronymic;

	return str;
}