#pragma once

#include "stdafx.h"
#include "Person.h"

class Adult : public Person 
{
private:
	Person* _marriedOn = nullptr;
	char* _workPlace;
public:
	Adult(char* name, char* surname, int age, enum Sex sex, Person* marriedOn, char* workPlace);
	char* GetDescription();

	void SetAge(int unsigned age) override;
	void SetMarriedOn(Person* marriedOn);
	void SetWorkPlace(char* workPlace);

	static Adult* GetRandomAdult();
	~Adult();
};
