#pragma once

#include "name.h"
#include "university.h"

using namespace std;

class staff : public university
{
private:
	string type;
	char* position;
	char* responsibilityArea;
	char telephoneNumber[21];

public:
	staff();
	staff(char**);
	staff(const staff&);
	~staff();

	void setName();
	void setPosition();
	// void setNumber();
	void setArea();
	void setType();
	void getData(char**);
	char* getPosition();
	char* getArea();
	// char *getNumber();
	string getName();
	string getType();
	void show();
};