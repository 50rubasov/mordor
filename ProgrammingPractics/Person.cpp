#include "stdafx.h"
#include "Person.h"

using namespace std;

Person::Person(char* name, char* surname, unsigned int age, enum Sex sex)
{
	SetName(name);
	SetSurname(surname);
	SetAge(age);
	SetSex(sex);
}

void Person::SetName(char* name)
{
	_name = name;
}

void Person::SetSurname(char* surname)
{
	_surname = surname;
}
void Person::SetAge(unsigned int age)
{
	_age = age;
}
void Person::SetSex(enum Sex sex)
{
	_sex = sex;
}
char* Person::GetName()
{
	return _name;
}
char* Person::GetSurname()
{
	return _surname;
}
int Person::GetAge()
{
	return _age;
}
Sex Person::GetSex()
{
	return _sex;
}
char* Person::GetDescription()
{
	char* description = new char[200];
	*description = '\0';
	char* age = new char[5];
	Concatenate(description, _name);
	Concatenate(description, " ");
	Concatenate(description, _surname);
	Concatenate(description, ", ");
	_itoa_s(_age, age, 10, 10);
	Concatenate(description, age);
	Concatenate(description, " лет, ");
	_sex == male ? Concatenate(description, "мужчина.") : Concatenate(description, "женщина.");
	return description;

}