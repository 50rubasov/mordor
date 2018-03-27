#pragma once
#include "stdafx.h"
#include "lab4.h"
#include "lab3.h"
#include "stack.h"
using namespace std;


Person* MakeRandomPerson()								//генерация рандомной личности
{
	Person *newPerson = new Person;

	char names[10][10] = { "Павел","Егор", "Иван", "Артем", "Сергей", "Николай","Алексей","Генадий","Владимир","Начин" };
	char surnames[10][15] = { "Петров","Аншаков", "Селиванов", "Леонтев", "Юшманов", "Баринов","Чуватов","Ивлев","Ткаченко","Дууза" };
	CopyString(newPerson->Name, names[rand() % 10]);
	CopyString(newPerson->Surname, surnames[rand() % 10]);
	newPerson->Age = rand() % 100;
	newPerson->sex = Sex(male);

	return newPerson;
}
void AddLast(List* list, Person* person)								//добавление в конец 
{
	Node* newNode = new Node; 
	newNode->person = person;      
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
			PrintPerson(*node->person);
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
				return node->person;
			}
			node = node->next;
		}
	}
	return NULL;
}

void Remove(int index, List* list)						//удаление элемента по индексу
{
	Node* node = list->head;

	try //код, который может привести к ошибке, располагается тут
	{
		if ((index < 0) || (node == NULL))
		{
			throw 1; //генерировать ошибку
		}
		for (int i = 0; i < index; i++)
		{
			if (node->next == NULL)
			{
				throw 2;
			}
			node = node->next;
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

}

void Clear(List* list)									//очистка списка
{
	Node* node = list->head;
	if (node)
	{
		while (node->next)
		{
			node = node->next;
			delete node->prev->person;
			delete node->prev;
		}
		delete node->person;
		delete node;

		list->head = NULL;
		list->tail = NULL;
	}
}

void Insert(List* list, Person* person, int index)						//добавление элемента до массива
{
	Node* newNode = new Node;
	newNode->person = person;     //TODO передавать персону в параметр

	Node* node = list->head;

	try //код, который может привести к ошибке, располагается тут
	{
		if ((index < 0) || (node == NULL))
		{
			throw 1; //генерировать ошибку
		}
		for (int i = 0; i < index; i++)
		{
			if (node->next == NULL)
			{
				throw 2;
			}
			node = node->next;
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
	int index, value;
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
		cout << "'7' - Стек \n";

		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '1':
		{
			AddLast(list, MakeRandomPerson());
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
			Insert(list, MakeRandomPerson(), index);
			system("pause");
			break;
		}
		case '6':
		{
			Clear(list);
			cout << "Список очищен\n";
			system("pause");
			break;
		}
		case '7':
		{

			int AssciiValue1 = 0;
			Stack* stack = CreateStack();
			while (AssciiValue1 != 27)
			{
				system("cls");

				cout << "Нажмите клавишу\n";
				cout << "1: Информация о стеке" << endl;
				cout << "2: Добавление элемента " << endl;
				cout << "3: Удаление элемента " << endl;

				key = _getch();
				AssciiValue1 = key;

				switch (AssciiValue1)
				{
				case '1':

					cout << endl << "Стек: ";
					for (int i = 0; i < stack->length; i++)
					{
						cout << stack->array[i] << " ";
					}
					cout << endl;
					cout << "Длина Стека: " << stack->length << endl;
					cout << "Длина буфера: " << stack->bufsize << endl;
					system("pause");
					break;

				case '2':

					cout << "Введите добавляемый элемент\n";
					cin >> value;
					PushStack(stack, value);
					break;
				case '3':
					if (stack->length > 0)
					{
						int data = PopStack(stack);
						cout << endl << "Полученный элемент = " << data << "\n";
						system("pause");
					}
					else
					{
						cout << endl << "Стек пуст" << endl;
						system("pause");
					}
					break;
				}
			}

			DelStack(stack);
			break;
		}
		}
	}
}