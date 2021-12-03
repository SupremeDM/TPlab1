#pragma once

#include "name.h"

using namespace std;

class university
{
protected:
	name name;
	university* next;

public:
	virtual ~university();

	virtual void setName() = 0;
	virtual void setType() = 0;
	virtual void getData(char**) = 0;
	virtual string getName() = 0;
	virtual string getType() = 0;
	virtual void show() = 0;

	university* getNext();
	void setNext(university*);
};

