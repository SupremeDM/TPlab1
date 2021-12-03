#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "digit.h"
#include "university.h"
#include "keeper.h"

#define BAD_INPUT 0x0

using namespace std;

int main()
{
	int menu;
	string str;
	const char* arr;
	keeper obj;
	string pass = "Password", bufPas;
	cout << "Enter password:";
	cin >> bufPas;

	while (bufPas == pass)
	{
		while (true)
		{
			system("cls");
			cout << "1. Add\n2. Delete\n3. Show\n4. Read from file\n5.Write\n6 Change the element\n0. Exit\nYour choice: ";
			getline(cin, str);
			arr = str.c_str();

			if (digitCounter(atoi(arr)) != strlen(arr))
			{
				cout << "You need to select a menu item";
				getchar();
				continue;
			}
			else
			{
				menu = atoi(arr);
				break;
			}
		}

		system("cls");

		try
		{
			switch (menu)
			{
			case 1:
				obj.add();
				break;

			case 2:
				obj.del();
				break;

			case 3:
				cout << obj;
				break;

			case 4:
				obj.read();
				break;
			case 5:
				obj.write();
				break;

			case 6:
				obj.change();
				break;

			case 0:
				break;

			default:
				throw BAD_INPUT;
			}

			if (menu == 0)
				break;
		}
		catch (int)
		{
			cout << "There is no such item in the menu" << endl;
			getchar();
			system("cls");
			continue;
		}
	}

	return 0;
}