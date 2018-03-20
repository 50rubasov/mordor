#pragma once
#include "stdafx.h"
#include "lab4.h"
#include "lab3.h"

using namespace std;

void CopyString(char* string1, const char* string2)		//копирование строки
{
	int i = 0;
	for (; string2[i]; i++)
	{
		string1[i] = string2[i];
	}
	string1[i] = '\0';
}

Person MakeRandomPerson()								//генерация рандомной личности
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
void AddLast(List* list)								//добавление в конец 
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


void Show(List* list)									//показать список
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

Person* Get(int index, List* list)						//поиск адреса по индексу
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

void Remove(int index, List* list)						//удаление элемента по индексу
{
	Node* node = list->head;

	if (index >= 0 && node)
	{
		for (int i = 0; i < index; i++)
		{
			if (node->next == NULL)	
			{
				cout << "Индекс выходит за пределы списка\n";
				return;
			}
			node = node->next;
		}
	}
	else
	{
		cout << "Индекс меньше нуля или список пуст\n";
		return;
	}
	if (node->prev)
	{
		node->prev->next = node->next;
	}
	else
	{
		list->head = node->next;
	}
	if (node->next)
	{
		node->next->prev = node->prev;
	}
	else
	{
		list->tail = node->prev;
	}
	delete node;
	cout << "Элемент удален\n";
}

void Clear(List* list)									//очистка списка
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

void Insert(List* list, int index)						//Добавление элемента до массива
{
	Node* newNode = new Node;
	newNode->person = MakeRandomPerson();

	Node* node = list->head;
	if (index >= 0 && node)
	{
		for (int i = 0; i < index; i++)
		{
			if (node->next == NULL)
			{
				cout << "Индекс выходит за пределы списка\n";
				return;
			}
			node = node->next;
		}
	}
	else
	{
		cout << "Индек меньше нуля или список пуст\n";
		return;
	}
	newNode->next = node;
	newNode->prev = node->prev;
	if (node->prev)
	{
		node->prev->next = newNode;
	}
	else
	{
		list->head = newNode;
		node->prev = newNode;
	}
	cout << "Элемент добавлен\n";
}

void LaunchLab4()
{
	setlocale(0, "");
	//Покраска консоли в матрицу
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);

	List* list = new List;

	int ascii = 0;
	char key;
	int index;
	while (ascii != 27)
	{
		system("cls");

		cout << "Нажмите... \n";
		cout << "'1' - Добавление в конец \n";
		cout << "'2' - Показать список \n";
		cout << "'3' - Вывод адресса элемента по индексу \n";
		cout << "'4' - Удаление элемента по индексу элемента \n";
		cout << "'5' - Добавление по индексу \n";
		cout << "'6' - Очистка списка \n";

		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '1':
		{
			AddLast(list);
			cout << "Элемент добавлен в конец\n";
			system("pause");
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

			cout << "Введите индекс элемента, адресс которого нужно вывести \n";
			cin >> index;
			cout << "Адрес: " << Get(index, list) << endl;
			system("pause");
			break;
		}
		case '4':
		{
			cout << "Введите индекс элемента, который нужно удалить\n";
			cin >> index;
			Remove(index, list);
			system("pause");
			break;
		}
		case '5':
		{
			cout << "Введите индекс элемента, перед которым нужно добавить элемент\n";
			cin >> index;
			Insert(list, index);
			break;
		}
		case '6':
		{
			Clear(list);
			cout << "Список очищен\n";
			system("pause");
			break;
		}
		}
	}
}