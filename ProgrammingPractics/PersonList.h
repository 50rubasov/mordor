#pragma once
#include "stdafx.h"
#include "Person.h"

class PersonList
{
private:
	class PersonListItem
	{
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
	private:
		Person * _value; //_value
	};

	PersonListItem * _head;
	PersonListItem * _tail;
	int _count;
	bool CheckChar(char name[]);//char*
public:
	PersonList(){};
	void Add(Person* person);
	Person* Find(int index);
	int IndexOf(Person* person);
	void RemoveAt(int index);
	void Clear();
	int GetCount();
	Person* Read();
	static Person* MakeRandomPerson();
	void ShowList();
	void ShowPerson(Person* person);
}; //operator>> operator<<
