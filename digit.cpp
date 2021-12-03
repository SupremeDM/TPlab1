#include "digit.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>

#define BAD_NUM 0x6

using namespace std;

int digitCounter(int number)
{
    int result = 0;

    if (number == 0)
        return 1;

    while (number != 0)
    {
        number /= 10;
        result++;
    }

    return result;
}

int getNum()
{
    string str;
    const char* arr;
    int num;

    while (true)
    {
        try
        {
            getline(cin, str);
            arr = str.c_str();

            if (digitCounter(atoi(arr)) != strlen(arr))
                throw BAD_NUM;
            else
            {
                if (*arr < '0' || *arr > '9')
                    throw BAD_NUM;

                num = atoi(arr);
                break;
            }
        }
        catch (int)
        {
            cout << "You should enter a number" << endl;
            continue;
        }
    }
    return num;
}
