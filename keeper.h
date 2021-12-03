#pragma once

#include "student.h"
#include "teacher.h"
#include "staff.h"

class keeper
{
private:
	university* head;

public:
	keeper();
	keeper(const keeper&);
	~keeper();

	void add();
	void del();
	void show();
	void write();
	void read();
	void change();

	friend ostream& operator << (ostream&, keeper&);
};
