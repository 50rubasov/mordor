#include "stdafx.h"
#include "PersonList.h"
#include "CorrectEnter.h"
//--------------------------------------------добавить в список---------------------------------------------
void PersonList::Add(Person* person)
{
	PersonListItem* temp = new PersonListItem(person);

	if (_head == nullptr)
	{
		_head = _tail = temp;
	}
	else
	{
		temp->Prev = _tail;
		_tail->Next = temp;
		_tail = temp;
	}
	_count++;
}

//-----------------------------------------поиск по индексу---------------------------------------------
Person* PersonList::Find(int index)
{
	if (index < 0)
	{
		return nullptr;
	}

	PersonListItem* searchedItem = _head;

	for (int i = 0; i < index; i++)
	{
		if (searchedItem->Next != nullptr)
		{
			searchedItem = searchedItem->Next;
		}
	}
	
	if (searchedItem->GetValue() != nullptr)
	{
		ShowPerson(searchedItem->GetValue());
	}
	return searchedItem->GetValue();
}

//-----------------------------------вернуть индекс-----------------------------------------------------
int PersonList::IndexOf(Person* person)
{
	PersonListItem* searchedPerson = _head;
	int index = 0;
	while (searchedPerson != nullptr)
	{
		if (searchedPerson->GetValue() == person)
		{
			return index;
		}
		index++;
		searchedPerson = searchedPerson->Next;
	}
	return -1;
}

//------------------------------удалить по индексу------------------------------------------
void PersonList::RemoveAt(int index)
{
	Person *person = Find(index);
	PersonListItem* temp = _head;
	while (temp != NULL)
	{
		if (temp->GetValue() == person)
		{
			if (_head == temp)
			{
				if (temp->Next == NULL)
				{
					_head = NULL;
					_tail = NULL;
					break;
				}
				_head->Next->Prev = NULL;
				_head = _head->Next;
				break;
			}

			if (_tail == temp)
			{
				_tail->Prev->Next = NULL;
				_tail = _tail->Prev;
				break;
			}

			if (_head != temp && _tail != temp)
			{
				temp->Prev->Next = temp->Next;
				temp->Next->Prev = temp->Prev;
				break;
			}
		}
		temp = temp->Next;
	}
}


//---------------------------------------------------------------очистить список----------------------------------------------------------------
void PersonList::Clear()
{
	PersonListItem* temp = _head;
	while (temp != nullptr)
	{
		PersonListItem* tempNext = temp->Next;
		//delete temp->GetValue();
		delete temp;
		temp = tempNext;
	}
	_head = nullptr;
	_tail = nullptr;
	_count = 0;
}

//----------------------------------------------------------получить количество элементов-------------------------------------------------------
int PersonList::GetCount()
{
	return _count;
}

Person* PersonList::MakeRandomPerson()
{
	char names[5][10] = { "Геральт", "Павел", "Король", "Джек",	"Родион" };
	char surnames[5][15] = {"Раскольников" , "Лич", "Селиванов", "Воробей", "Из Ривии" };

	char Name[20];
	char Surname[20];
	int tempAge;
	Sex tempSex;

	strcpy_s(Name, names[rand() % 5]);
	strcpy_s(Surname, surnames[rand() % 5]);
	tempAge = rand() % 100;
	tempSex = Sex(male);
	
	return new Person(Name, Surname, tempAge, tempSex);
}

Person* PersonList::Read()
{
	bool key = true;
	char tempName[20];
	char tempSurname[20];
	unsigned int tempAge;
	Sex tempSex;

	while (key)
	{
		cout << endl << "Введите фамилию: ";
		cin >> tempSurname;
		key = !CheckChar(tempSurname);
	}

	key = true;

	while (key)
	{
		cout << endl << "Введите имя: ";
		cin >> tempName;
		key = !CheckChar(tempName);
	}

	cout << endl << "Введите пол 0 - человек(женский пол), 1 - человек(мужской пол): ";
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
	default:
		break;
	}

	cout << endl << "Введите возраст: ";
	tempAge = CorrectEnter();
	return new Person(tempName, tempSurname, tempAge, tempSex);
}

bool PersonList::CheckChar(char name[])
{
	bool isTrueName = true;
	for (int i = 0; i < strlen(name); i++)
	{
		if (isdigit(name[i]) || isspace(name[i]))
		{
			isTrueName = false;
			break;
		}

		if (name[i] == '-')
		{
			if (islower(name[i + 1]))
			{
				name[i + 1] = toupper(name[i + 1]);
			}
			else
			{
				isTrueName = false;
				break;
			}
		}
	}
	return isTrueName;
}


void PersonList::ShowPerson(Person* person)
{
	cout << "Имя: ";
	cout << person->GetName() << endl;
	cout << "Фамилия: ";
	cout << person->GetSurname() << endl;
	cout << "Возраст: " << person->GetAge() << endl;
	switch (person->GetSex())
	{
	case famale:
		cout << "Пол:";
		cout << "Женщина" << endl << endl;
		break;
	case male:
		cout << "Пол:";
		cout << "Мужчина" << endl << endl;
		break;
	default: break;
	}
}

void PersonList::ShowList()
{
	PersonListItem* temp = _head;

	if (temp)
	{
		int index = 0;

		while (temp)
		{
			cout << "Индекс: " << index++ << endl;
			
			cout << "Имя: " << temp->GetValue()->GetName() << endl;
			cout << "Фамилия: " << temp->GetValue()->GetSurname() << endl;
			if (temp->GetValue()->GetSex() == 1)
			{
				cout << "Пол: Мужской" << endl;
			}
			else
			{
				cout << "Пол: Женский" << endl;
			}
			cout << "Возраст: " << temp->GetValue()->GetAge() << endl << endl;
			temp = temp->Next;
		}
	}
	else
	{
		cout << "Список пуст\n";
	}
}