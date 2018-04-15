#include "stdafx.h"
#include "Adult.h"
#include "PersonTools.h"

Adult::Adult(char* name, char* surname, int age, enum Sex sex, Person* marriedOn, char* workPlace) : Person(name, surname, age, sex)
{
	SetMarriedOn(marriedOn);
	SetWorkPlace(workPlace);
}

void Adult::SetAge(unsigned int age)
{
	if (age >= 18)
	{
		_age = age;
	}
	else
	{
		_age = 18;
	}
}

void Adult::SetMarriedOn(Person* marriedOn)
{
	_marriedOn = marriedOn;
}

void Adult::SetWorkPlace(char* workPlace)
{
	_workPlace = workPlace;
}

char* Adult::GetDescription()
{
	char* description = Person::GetDescription();

	if (_workPlace != nullptr)
	{
		Concatenate(description, _workPlace);
		Concatenate(description, ",");
	}
	else
	{
		Concatenate(description, " ����������� ");
	}
	if (_marriedOn)
	{
		Concatenate(description, " ������ �� ");
		Concatenate(description, _marriedOn->GetName());
		Concatenate(description, " ");
		Concatenate(description, _marriedOn->GetSurname());
		Concatenate(description, ".");
	}
	else
	{
		Concatenate(description, " �� �����");
	}
	return description;
}

Adult* Adult::GetRandomAdult() 
{
	char const* names[] = { "��������", "����", "�����", "������","����" };
	char const* surnames[] = { "�����������" , "��������", "���������", "�������", "������" };
	const char* workPlaces[] = { "����������", "el presidente", "�������" , "������������������ ��" , "���������" };

	char* name = new char[20];
	char* surname = new char[20];
	char* workPlace = new char[50];
	int tempAge;

	Person* tempMarriedOn = PersonTools::MakeRandomPerson();

	CopyString(name, names[rand() % 5]);
	CopyString(surname, surnames[rand() % 5]);
	CopyString(workPlace, workPlaces[rand() % 5]);
	tempAge = 18 + rand() % 100;

	return new Adult(name, surname, tempAge, Sex(famale), tempMarriedOn, workPlace);
}