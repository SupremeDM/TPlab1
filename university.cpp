#include "university.h"
#include <iostream>
using namespace std;

university::~university()
{
	cout << "university destructor" << endl;
}

university* university::getNext()
{
	return next;
}

void university::setNext(university* ptr)
{
	next = ptr;
}
