#include "stdafx.h"
#include "PersonTools.h"
#include "StringFunctions.h"
#include "CorrectEnter.h"
using namespace std;



ostream& operator << (ostream &out, Person* person)
{
	out << '(' << person->GetName() << ", " << person->GetSurname() << ", " << person->GetAge() << ", " << person->GetSex() << ')';
	return out;
}

istream& operator >> (istream &in, Person* person)
{
	bool key = true;
	char* tempName = new char[20];
	char* tempSurname = new char[20];
	unsigned int tempAge;
	Sex tempSex;

	while (key)
	{
		cout << endl << "������� �������: ";
		cin >> tempSurname;
		key = !CheckChar(tempSurname);
	}
	person->SetSurname(tempSurname);

	key = true;

	while (key)
	{
		cout << endl << "������� ���: ";
		cin >> tempName;
		key = !CheckChar(tempName);
	}
	person->SetName(tempName);
	cout << endl << "������� ��� 0 - �������(������� ���), 1 - �������(������� ���): ";
	int n;

	do
	{
		n = CorrectEnter();
	} while (n != 0 && n != 1);

	switch (n)
	{
	case famale:
		tempSex = (Sex)famale;
		break;
	case male:
		tempSex = (Sex)male;
		break;
	}
	person->SetSex(tempSex);

	cout << endl << "������� �������: ";
	tempAge = CorrectEnter();
	person->SetAge(tempAge);
	return in;
}
Person* PersonTools::MakeRandomPerson()
{
	char const* names[5] = { "�������", "�����", "������", "����",	"������" };
	char const* surnames[5] = { "������������" , "���", "���������", "�������", "�� �����" };

	char* name = new char[20];
	char* surname = new char[20];
	int tempAge;
	Sex tempSex;

	CopyString(name, names[rand() % 5]);
	CopyString(surname, surnames[rand() % 5]);
	tempAge = rand() % 100;
	tempSex = Sex(male);

	return new Person(name, surname, tempAge, tempSex);
}

Person* PersonTools::Read()
{
	Person* person = new Person();
	cin >> person;

	return person;
	
}

void PersonTools::ShowPerson(Person* person)
{
	cout << person << endl;
}
