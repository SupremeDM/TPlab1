#define _CRT_SECURE_NO_WARNINGS
#include "keeper.h"
#include <iostream>
#include <string>
#include <fstream>
#include <typeinfo>
#include "digit.h"


#define BAD_INPUT    0x0
#define EMPTY_LIST   0x10
#define BAD_ITEM     0x11
#define BAD_TYPE     0x20
#define BAD_STR      0x21
#define FILE_N_O     0x30
//#define FILE_EMPTY   0x31
#define FILE_IS_READ 0x32

using namespace std;

keeper::keeper()
{
    cout << "keeper constructor" << endl;
    head = nullptr;
}

keeper::~keeper()
{
    university* ptr = nullptr;

    write();

    while (head != nullptr)
    {
        if (head->getNext() != nullptr)
            ptr = head->getNext();
        else
            ptr = nullptr;

        delete head;
        head = ptr;
    }

    cout << "keeper destructor" << endl;
}

void keeper::add()
{
    string str;
    const char* arr;
    int menu;
    university* ptr = head;

    system("cls");

    while (true)
    {
        cout << "1. Student\n2. Teacher\n3. Staff\nYour choice: ";

        while (true)
        {
            getline(cin, str);
            arr = str.c_str();

            if (digitCounter(atoi(arr)) != strlen(arr))
            {
                cout << "You need to select a menu item";
                getchar();
                cout << endl << "Your choice: ";
                continue;
            }
            else
            {
                menu = atoi(arr);
                break;
            }
        }

        if (head != nullptr)
            while (ptr->getNext() != nullptr)
                ptr = ptr->getNext();

        try
        {
            switch (menu)
            {
            case 1:
                if (head != nullptr)
                {
                    ptr->setNext(new student);
                    ptr = ptr->getNext();
                    ptr->setNext(nullptr);
                }
                else
                {
                    head = new student;
                    head->setNext(nullptr);
                }
                break;

            case 2:
                if (head != nullptr)
                {
                    ptr->setNext(new teacher);
                    ptr = ptr->getNext();
                    ptr->setNext(nullptr);
                }
                else
                {
                    head = new teacher;
                    head->setNext(nullptr);
                }
                break;

            case 3:
                if (head != nullptr)
                {
                    ptr->setNext(new staff);
                    ptr = ptr->getNext();
                    ptr->setNext(nullptr);
                }
                else
                {
                    head = new staff;
                    head->setNext(nullptr);
                }
                break;

            default:
                throw BAD_INPUT;
            }
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
}

void keeper::del()
{
    university* ptr = head;
    university* tmp;
    int i, choice;

    system("cls");

    while (true)
    {
        try
        {
            if (ptr == nullptr)
                throw EMPTY_LIST;

            for (i = 0; ptr != nullptr; ++i, ptr = ptr->getNext())
                cout << i + 1 << ". " << ptr->getName() << endl;

            cout << "Which one would you like to delete: ";

            choice = getNum();

            if (choice > i || choice == 0)
                throw BAD_ITEM;

            ptr = head;
            if (choice == 1)
            {
                if (ptr->getNext() != nullptr)
                {
                    head = ptr->getNext();
                    delete ptr;
                    ptr = head;
                }
                else
                {
                    delete head;
                    head = nullptr;
                    ptr = nullptr;
                    break;
                }
            }
            else
            {
                --choice;
                while (--choice)
                    ptr = ptr->getNext(); // we are now at the (choice - 1)-th element

                tmp = ptr;
                ptr = ptr->getNext();

                if (ptr->getNext() == nullptr)
                    tmp->setNext(nullptr);
                else
                    tmp->setNext(ptr->getNext());

                delete ptr;
                ptr = nullptr;
            }

        }
        catch (int exc)
        {
            if (exc == EMPTY_LIST)
            {
                cout << "There are no elements to delete";
                getchar();
                break;
            }
            else if (exc == BAD_ITEM)
            {
                cout << "You should enter a number from 1 to " << i << endl;
                continue;
            }
        }

    }
}

void keeper::show()
{
    university* ptr = head;
    system("cls");

    if (ptr == nullptr)
        cout << "The list is empty" << endl;

    while (ptr != nullptr)
    {
        ptr->show();
        cout << endl;
        ptr = ptr->getNext();
    }

    getchar();
}

void keeper::write()
{
    university* ptr = head;
    char* data[6];
    int cnt;

    if (head != nullptr)
    {
        ofstream fout("D:\\lab1aydarov\\file.txt");

        if (!fout.is_open())
        {
            throw "File can't be opened\n";
            getchar();
            return;
        }

        while (ptr != nullptr)
        {
            if (ptr->getType() == "student")
                cnt = 6;
            else if (ptr->getType() == "teacher")
                cnt = 4;
            else if (ptr->getType() == "staff")
                cnt = 5;

            ptr->getData(data);

            for (int i = 0; i < cnt; i++)
                fout << data[i] << endl;

            fout << endl;

            ptr = ptr->getNext();
        }

        fout.close();
    }
}

void keeper::read()
{
    char** data;
    string str;
    int strcnt = 1;
    int ceil;
    university* ptr = head;
    head = nullptr;

    write();

    ifstream fin("D:\\lab1aydarov\\\\lab1aydarov\\file.txt");

    data = new char* [6];
    while (true)
    {
        ceil = 100;

        try
        {
            if (!fin.is_open())
            {
                throw FILE_N_O;
                getchar();
                return;
            }

            /*if( fin.peek() == EOF )
            {
              throw FILE_EMPTY;
              getchar();
              return;
            }*/

            for (int i = 0; i < ceil; i++)
            {
                if (i == 0)
                    getline(fin, str, '\n');
                else
                    getline(fin, str, ':');

                switch (i)
                {
                case 0:
                    if (str != "Student" && str != "Teacher" && str != "Staff")
                    {
                        if (fin.peek() == EOF)
                            throw FILE_IS_READ;

                        if (str.size() != 0)
                            throw BAD_TYPE;

                        i--;
                        break;
                    }

                    if (str == "Student")
                        ceil = 6;
                    else if (str == "Teacher")
                        ceil = 4;
                    else if (str == "Staff")
                        ceil = 5;
                    break;

                case 1:
                    if (str != "Name")
                        throw BAD_STR;

                    getline(fin, str);
                    break;

                case 2:
                    if (str != "Position" && str != "Group" && str != "Study groups")
                        throw BAD_STR;

                    getline(fin, str);
                    break;

                case 3:
                    if (str != "Area of responsibility" && str != "Specialty" && str != "Subjects")
                        throw BAD_STR;

                    getline(fin, str);
                    break;

                case 4:
                    if (str != "Telephone number" && str != "Current course")
                        throw BAD_STR;

                    getline(fin, str);
                    break;

                case 5:
                    if (str != "Average mark")
                        throw BAD_STR;

                    getline(fin, str);
                    break;
                }

                data[i] = new char[str.size() + 2];
                strcpy(data[i], str.c_str());
                strcnt++;
            }

            if (ptr == nullptr)
            {
                if (strcmp(data[0], "Student") == 0)
                    ptr = new student(data);
                else if (strcmp(data[0], "Teacher") == 0)
                    ptr = new teacher(data);
                else if (strcmp(data[0], "Staff") == 0)
                    ptr = new staff(data);

                ptr->setNext(nullptr);
                head = ptr;
            }
            else
            {
                if (strcmp(data[0], "Student") == 0)
                    ptr->setNext(new student(data));
                else if (strcmp(data[0], "Teacher") == 0)
                    ptr->setNext(new teacher(data));
                else if (strcmp(data[0], "Staff") == 0)
                    ptr->setNext(new staff(data));

                ptr = ptr->getNext();
                ptr->setNext(nullptr);
            }

            for (int i = 0; i < ceil; i++)
                delete data[i];
        }
        catch (int exc)
        {
            switch (exc)
            {
            case BAD_TYPE:
            {
                cout << "Incorrect person type in string " << strcnt;
                getchar();
                break;
            }

            case BAD_STR:
            {
                cout << "Incorrect string " << strcnt;
                getchar();
                break;
            }

            case FILE_N_O:
            {
                cout << "File can't be opened" << endl;
                getchar();
                break;
            }

            /*case FILE_EMPTY:
              {
                cout << "File is empty" << endl;
                getchar();
                break;
              }*/

            case FILE_IS_READ:
            {
                cout << "File is read" << endl;
                getchar();
                break;
            }
            }

            break;
        }
    }

    fin.close();
}

void keeper::change()
{
    university* ptr = head;
    university* tmp;
    const char* arr;
    string str;
    int i, choice, menu;

    system("cls");

    while (true)
    {
        try
        {
            if (ptr == nullptr)
                throw EMPTY_LIST;

            for (i = 0; ptr != nullptr; ++i, ptr = ptr->getNext())
                cout << i + 1 << ". " << ptr->getName() << endl;

            cout << "Which one would you like to change: ";

            choice = getNum();

            if (choice > i || choice == 0)
                throw BAD_ITEM;

            ptr = head;
            cout << "1. Student\n2. Teacher\n3. Staff\nYour choice: ";

            while (true)
            {
                getline(cin, str);
                arr = str.c_str();

                if (digitCounter(atoi(arr)) != strlen(arr))
                {
                    cout << "You need to select a menu item";
                    getchar();
                    cout << endl << "Your choice: ";
                    continue;
                }
                else
                {
                    menu = atoi(arr);
                    system("cls");
                    break;
                }
            }

            if (choice == 1)
            {
                if (head->getNext() != nullptr)
                {
                    ptr = head->getNext();
                    delete head;

                    switch (menu)
                    {
                    case 1:
                        head = new student;
                        break;

                    case 2:
                        head = new teacher;
                        break;

                    case 3:
                        head = new staff;
                        break;
                    }

                    head->setNext(ptr);
                    break;
                }
            }
            else
            {
                --choice;
                while (--choice)
                    ptr = ptr->getNext(); // we are now at the (choice - 1)-th element

                if (ptr->getNext() != nullptr)
                {
                    tmp = head->getNext();
                    delete ptr;

                    switch (menu)
                    {
                    case 1:
                        ptr = new student;
                        break;

                    case 2:
                        ptr = new teacher;
                        break;

                    case 3:
                        ptr = new staff;
                        break;
                    }

                    ptr->setNext(tmp);
                    break;
                }
            }

        }
        catch (int exc)
        {
            if (exc == EMPTY_LIST)
            {
                cout << "There are no elements to change";
                getchar();
                break;
            }
            else if (exc == BAD_ITEM)
            {
                cout << "You should enter a number from 1 to " << i << endl;
                continue;
            }
        }

    }
}

ostream& operator << (ostream& out, keeper& obj)
{
    obj.show();
    return out;
}
