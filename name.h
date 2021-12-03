#pragma once

#include <string>

class name
{
private:
	const char* first;
	const char* surname;
	const char* patronymic;
public:
	name();
	name(const name&);
	~name();

	void setName();
	void setName(char**);
	std::string getName();
};