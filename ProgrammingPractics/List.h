#pragma once
#include "stdafx.h"
#include "Person.h"
#include "PersonTools.h"

using namespace std;

template <class T>
class List
{
private:

	template <class TNode>
	class ListItem
	{
	public:

		ListItem()
		{
		};

		ListItem(TNode data)
		{
			_value = data;
		};

		TNode GetValue()
		{
			return _value;
		};

		ListItem<TNode>* Next = nullptr;
		ListItem<TNode>* Prev = nullptr;

	private:
		TNode _value;
	};

	ListItem<T>* _head = nullptr;
	ListItem<T>* _tail = nullptr;
	int _count = 0;

public:
	List() {};
	


	void AddLast(T data)
	{
		ListItem<T>* temp = new ListItem<T>(data);
		if (!_head)
		{
			_head = temp;
		}
		else
		{
			temp->Prev = _tail;
			_tail->Next = temp;
		}
		_tail = temp;
		_count++;
	};

	void Show()
	{

		ListItem<T>* temp = _head;
		int index = 0;
		if (temp)
		{
			while (temp)
			{
				cout << "\nИндекс: " << index++ << endl;
				cout << temp->GetValue() << endl;
				temp = temp->Next;
			}
		}
		else
		{
			cout << "Список пуст";
		}

	};

	void Insert(T element, int index)
	{
		if (_head == nullptr || index < 0)
		{
			return;
		}

		ListItem<T>* temp = _head;
		int i = 0;
		while (i < index)
		{
			temp = temp->Next;
			i++;
			if (temp == nullptr)
			{
				AddLast(element);
				return;
			}
		};


		if (temp == _head)
		{
			ListItem<T>* newNode = new ListItem<T>();
			_head->Prev = newNode;
			newNode->Next = _head;

			_head = newNode;
			return;
		}

		if (temp == _tail)
		{
			ListItem<T>* newNode = new ListItem<T>(element);
			_tail->Prev->Next = newNode;
			newNode->Prev = _tail->Prev;
			newNode->Next = _tail;
			_tail->Prev = newNode;
			_tail->Next = nullptr;
			return;
		}


		if (temp != nullptr)
		{
			ListItem<T>* newNode = new ListItem<T>(element);
			temp->Prev->Next = newNode;
			newNode->Prev = temp->Prev;
			newNode->Next = temp;
			temp->Prev = newNode;
		}
		return;
	}

	T Find(int index)
	{
		if (index < 0)
		{
			return nullptr;
		}

		ListItem<T>* searchedItem = _head;

		for (int i = 0; i < index; i++)
		{
			if (searchedItem->Next)
			{
				searchedItem = searchedItem->Next;
			}
		}
		return searchedItem->GetValue();
	};

	int IndexOf(T data)
	{
		ListItem<T>* searchedData = _head;
		int index = 0;
		while (searchedData)
		{
			if (searchedData->GetValue() == data)
			{
				return index;
			}
			index++;
			searchedData = searchedData->Next;
		}
		return -1;
	};

	int GetCount()
	{
		return _count;
	};

	void Remove(T data)
	{
		ListItem<T>* temp = temp->head;

		try //код, который может привести к ошибке, располагается тут
		{
			if ((index < 0) || (temp == NULL))
			{
				throw 1; //генерировать ошибку
			}
			for (int i = 0; i < index; i++)
			{
				if (temp->next == NULL)
				{
					throw 2;
				}
				temp = temp->next;
			}

			if (temp->prev)
			{
				temp->prev->next = temp->next;
			}
			else
			{
				_head = temp->next;
			}
			if (temp->next)
			{
				temp->next->prev = temp->prev;
			}
			else
			{
				_tail = temp->prev;
			}
			delete temp;
		}

		catch (int i)//сюда передастся ошибка
		{
			if (i == 1)
			{
				cout << "Ошибка №" << i << " - Индекс меньше нуля или список пуст\n" << endl;
			}
			if (i == 2)
			{
				cout << "Ошибка №" << i << " - Индекс выходит за пределы списка\n" << endl;
			}
		}
	};

	void RemoveAt(int index)
	{
		ListItem<T>* deletedItem = _head;

		if (index >= 0)
		{
			for (int i = 0; i < index; i++)
			{
				if (!deletedItem->Next)
				{
					return;
				}
				deletedItem = deletedItem->Next;
			}
		}
		else
		{
			return;
		}

		if (deletedItem->Prev)
			deletedItem->Prev->Next = deletedItem->Next;
		else
			_head = deletedItem->Next;

		if (deletedItem->Next)
			deletedItem->Next->Prev = deletedItem->Prev;
		else
			_tail = deletedItem->Prev;

		delete deletedItem;
	};


	void Clear()
	{
		ListItem<T>* temp = _head;
		ListItem<T>* tempNext;
		while (temp)
		{
			tempNext = temp->Next;
			delete temp;
			temp = tempNext;
		}
		_head = nullptr;
		_tail = nullptr;
		_count = 0;
	};

	~List()
	{
		Clear();
	};


	friend std::ostream & operator<<(std::ostream &out, List<T>* list)
	{
		ListItem<T>* temp = list->_head;
		while (temp)
		{
			out << temp->GetValue() << ' ';
			temp = temp->Next;
		}
		return out;
	}
};
ostream& operator << (ostream &out, Person* person)
{
	out << '(' << person->GetName() << ", " << person->GetSurname() << ", " << person->GetAge() << ", " << person->GetSex() << ')';
	return out;
}

ostream & operator << (ostream &out, double* d)
{
	for (int i = 0; i < 5; i++)
	{
		out << d[i] << ' ';
	}
	return out;
}

