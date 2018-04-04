#pragma once
#include "PersonList.h"
class PersonTools
{
	public:
	static Person* MakeRandomPerson();
	static Person* Read();
	static void ShowPerson(Person* person);
};