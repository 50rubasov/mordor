#include "stdafx.h"
#include "PersonList.h"



using namespace std;
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
	PersonTools person;
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
		person.ShowPerson(searchedItem->GetValue());
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
