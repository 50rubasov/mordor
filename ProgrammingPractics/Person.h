#pragma once
#include "StringFunctions.h"
using namespace std;

enum Sex
{
	famale,
	male
};

class Person
{
protected:
	char* _name;//char*
	char* _surname;//char*
	int _age;
	Sex _sex;
public:
	Person() {};
	Person(char* name, char* surname, unsigned int age, Sex sex);
	void SetName(char *name);
	void SetSurname(char *surname);
	virtual void SetAge(unsigned int age);
	void SetSex(Sex sex);
	char* GetName();
	char* GetSurname();
	int GetAge();
	Sex GetSex();

	virtual char* GetDescription();
	~Person() {};
};
