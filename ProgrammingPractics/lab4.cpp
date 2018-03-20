#pragma once
#include "stdafx.h"
#include "lab4.h"
#include "lab3.h"

using namespace std;

void CopyString(char* string1, const char* string2)
{
	int i = 0;
	for (; string2[i]; i++)
	{
		string1[i] = string2[i];
	}
	string1[i] = '\0';
}

Person MakeRandomPerson()
{
	Person newPerson;
	char names[10][10] = { "Павел","Егор", "Иван", "Артем", "Сергей", "Николай","Алексей","Генадий","Владимир","Начин" };
	char surnames[10][15] = { "Петров","Аншаков", "Селиванов", "Леонтев", "Юшманов", "Баринов","Чуватов","Ивлев","Ткаченко","Дууза" };
	CopyString(newPerson.Name, names[rand() % 10]);
	CopyString(newPerson.Surname, surnames[rand() % 10]);
	newPerson.Age = rand() % 100;
	newPerson.sex = Sex(male);

	return newPerson;
}
void AddLast(List* list)
{
	Node* newNode = new Node; 
	newNode->person = MakeRandomPerson();
	if (list->tail == NULL)
		list->head = newNode;
	else
	{
		newNode->prev = list->tail;
		list->tail->next = newNode;
	}
	list->tail = newNode;
}


void Show(List* list)
{
	Node* node = list->head;
	int index = 0;
	if (node)
	{
		while (node)
		{
			cout << "\nИндекс: " << index << endl;
			index++;
			PrintPerson(node->person);
			node = node->next;
		}
	}
	else
	{
		cout << "Список пуст";
	}
}

Person* Get(int index, List* list)
{
	Node* node = list->head;

	if (index >= 0)
	{
		for (int i = 0; node; i++)
		{
			if (i == index)
			{
				return &node->person;
			}
			node = node->next;
		}
	}
	return NULL;
}

void Remove(int index, List* list)
{
	Node* node = list->head;
	Person element = node->person;
	while (node)
	{
		{

		}
		node = node->next;
	}
}

void Clear(List* list) 
{
	Node* node = list->head;
	if (node)
	{
		while (node->next)
		{
			node = node->next;
			delete node->prev;
		}
		delete node;

		list->head = NULL;
		list->tail = NULL;
	}
}

void LaunchLab4()
{
	setlocale(0, "");

	List* list = new List;

	int ascii = 0;
	char key;

	while (ascii != 27)
	{
		system("cls");

		cout << "Нажмите... \n";
		cout << "'1' - Добавление в конец \n";
		cout << "'2' - Показать список \n";
		cout << "'3' - Вывод адресса элемента \n";

		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '1':
		{
			AddLast(list);
			break;
		}
		case '2':
		{
			Show(list);
			system("pause");
			break;
		}
		case '3':
		{
			int index;
			cout << "Введите индекс элемента, адресс которого нужно вывести \n";
			cin >> index;
			cout << Get(index,list);
			system("pause");
			break;
		}
		}
	}
}