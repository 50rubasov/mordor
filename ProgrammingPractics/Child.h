#pragma once

#include "stdafx.h"
#include "Person.h"


class Child : public Person
{
private:
	Person *_mother;
	Person* _father;
public:
	Child(char* name, char* surname, int age, Sex sex, Person* mother, Person* father);
	char* GetDescription();
	static Child* GetRandomChild();

	void SetAge(unsigned int age) override;
	void SetMother(Person* mother);
	void SetFather(Person* father);
};