#include "stdafx.h"
#include "Child.h"
#include "PersonTools.h"

Child::Child(char* name, char* surname, int age, Sex sex, Person* mother, Person* father) : Person(name, surname, age, sex)
{
	SetMother(mother);
	SetFather(father);
};

void Child::SetAge(unsigned int age)
{
	if (age < 18)
	{
		_age = age;
	}
	else
	{
		_age = 17;
	}
}

void Child::SetMother(Person* mother)
{
	_mother = mother;
}

void Child::SetFather(Person* father)
{
	_father = father;
}

char* Child::GetDescription()
{
	char* description = Person::GetDescription();
	if (_mother == nullptr && _father == nullptr)
	{
		Concatenate(description, "Сирота.");
	}
	else if (_mother == nullptr)
	{
		Concatenate(description, "Отец: ");
		Concatenate(description, _father->GetName());
		Concatenate(description, " ");
		Concatenate(description, _father->GetSurname());
		Concatenate(description, ".");
	}
	else if (_father == nullptr)
	{
		Concatenate(description, "Мать: ");
		Concatenate(description, _mother->GetName());
		Concatenate(description, " ");
		Concatenate(description, _mother->GetSurname());
		Concatenate(description, ".");
	}
	else
	{
		Concatenate(description, "Родители: ");
		Concatenate(description, _father->GetName());
		Concatenate(description, " ");
		Concatenate(description, _father->GetSurname());
		Concatenate(description, " , ");
		Concatenate(description, _mother->GetName());
		Concatenate(description, " ");
		Concatenate(description, _mother->GetSurname());
		Concatenate(description, ".");
	}
	return description;
}
Child* Child::GetRandomChild()
{
	char const* maleNames[] = { "Джон", "Бран", "Давос", "Джорах","Рамси" };
	char const* maleSurnames[] = { "Сноу" , "Старк", "Сиворт", "Мормонт", "Болтон" };
	char const* famaleNames[] = { "Арья", "Дейнерис", "Маргери", "Серсея","Эллария" };
	char const* famaleSurnames[] = { "Старк", "Таргариен", "Тирелл" ,"Ланнистер","Сэнд"};

	char* name = new char[20];
	char* surname = new char[20];
	char* school = new char[20];
	
	int tempAge = rand() % 17;
	Sex tempSex = Sex(rand() % 2);

	Person* tempFather;
	Person* tempMother;
	
	if (rand() % 3)
	{
		tempMother = Adult::GetRandomAdult();
	}
	else
	{
		tempMother = nullptr;
	}

	if (rand() % 3)
	{
		tempFather = PersonTools::MakeRandomPerson();
	}
	else
	{
		tempFather = nullptr;
	}

	if (tempSex)
	{
		CopyString(name, maleNames[rand() % 5]);
		CopyString(surname, maleSurnames[rand() % 5]);
	}
	else
	{
		CopyString(name, famaleNames[rand() % 5]);
		CopyString(surname, famaleSurnames[rand() % 5]);
	}
	return new Child(name, surname, tempAge, tempSex, tempMother, tempFather);

}