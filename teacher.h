#pragma once

#include "name.h"
#include "university.h"

using namespace std;

class teacher : public university
{
private:
	string type;
	char** studyGroups;
	char** subjects;
	int groupsNum;
	int subjectsNum;

public:
	teacher();
	teacher(char**);
	teacher(const teacher&);
	~teacher();

	void setName();
	void setGroups();
	void setSubjects();
	void setType();
	char** getGroups();
	char** getSubjects();
	void getData(char**);
	string getName();
	string getType();
	void show();
};

