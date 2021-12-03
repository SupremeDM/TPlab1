#pragma once

#include "name.h"
#include "university.h"

using namespace std;

class student : public university
{
private:
	string type;
	char* group;
	char* specialty;
	int currentCourse;
	float averageMark;

public:
	student();
	student(char**);
	student(const student&);
	~student();

	void setName();
	void setGroup();
	void setSpecialty();
	void setCourse();
	void setMark();
	void setType();
	void getData(char**);
	char* getGroup();
	char* getSpecialty();
	int getCourse();
	float getMark();
	string getName();
	string getType();
	void show();
};