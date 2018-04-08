#pragma once
#include "stdafx.h"
#include "Person.h"
#include "PersonTools.h"
class PersonList
{
private:
	class PersonListItem
	{
	private:
		Person * _value; //_value

	public:
		PersonListItem(Person* person)
		{
			_value = person;
		}

		Person* GetValue()
		{
			return _value;
		}

		PersonListItem* Next = nullptr;
		PersonListItem* Prev = nullptr;
	};

	PersonListItem * _head;
	PersonListItem * _tail;
	int _count;

public:
	PersonList(){};
	void Add(Person* person);
	Person* Find(int index);
	int IndexOf(Person* person);
	void RemoveAt(int index);
	void Clear();
	int GetCount();
	//Person* Read();
	//static Person* MakeRandomPerson();
	void ShowList();
	//void ShowPerson(Person* person);
	~PersonList() {};
}; 
