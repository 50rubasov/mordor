#pragma once

using namespace std;

enum Sex
{
	famale,
	male
};

class Person
{
public:
	Person(char _name[40], char _surname[40], unsigned int _age, Sex _sex);
	void SetName(char _name[40]);
	void SetSurname(char _surname[40]);
	void SetAge(unsigned int _age);
	void SetSex(Sex _sex);
	char* GetName();
	char* GetSurname();
	int GetAge();
	Sex GetSex();
private:
	char _name[40];//char*
	char _surname[40];//char*
	int _age;
	Sex _sex;
};
