#pragma once
#include "stdafx.h"
#include "lab4.h"
#include "lab3.h"

using namespace std;

void CopyString(char* string1, const char* string2)		//����������� ������
{
	int i = 0;
	for (; string2[i]; i++)
	{
		string1[i] = string2[i];
	}
	string1[i] = '\0';
}

Person MakeRandomPerson()								//��������� ��������� ��������
{
	Person newPerson;
	char names[10][10] = { "�����","����", "����", "�����", "������", "�������","�������","�������","��������","�����" };
	char surnames[10][15] = { "������","�������", "���������", "�������", "�������", "�������","�������","�����","��������","�����" };
	CopyString(newPerson.Name, names[rand() % 10]);
	CopyString(newPerson.Surname, surnames[rand() % 10]);
	newPerson.Age = rand() % 100;
	newPerson.sex = Sex(male);

	return newPerson;
}
void AddLast(List* list)								//���������� � ����� 
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


void Show(List* list)									//�������� ������
{
	Node* node = list->head;
	int index = 0;
	if (node)
	{
		while (node)
		{
			cout << "\n������: " << index << endl;
			index++;
			PrintPerson(node->person);
			node = node->next;
		}
	}
	else
	{
		cout << "������ ����";
	}
}

Person* Get(int index, List* list)						//����� ������ �� �������
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

void Remove(int index, List* list)						//�������� �������� �� �������
{
	Node* node = list->head;

	if (index >= 0 && node)
	{
		for (int i = 0; i < index; i++)
		{
			if (node->next == NULL)	
			{
				cout << "������ ������� �� ������� ������\n";
				return;
			}
			node = node->next;
		}
	}
	else
	{
		cout << "������ ������ ���� ��� ������ ����\n";
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
	cout << "������� ������\n";
}

void Clear(List* list)									//������� ������
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

void Insert(List* list, int index)						//���������� �������� �� �������
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
				cout << "������ ������� �� ������� ������\n";
				return;
			}
			node = node->next;
		}
	}
	else
	{
		cout << "����� ������ ���� ��� ������ ����\n";
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
	cout << "������� ��������\n";
}

void LaunchLab4()
{
	setlocale(0, "");
	//�������� ������� � �������
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);

	List* list = new List;

	int ascii = 0;
	char key;
	int index;
	while (ascii != 27)
	{
		system("cls");

		cout << "�������... \n";
		cout << "'1' - ���������� � ����� \n";
		cout << "'2' - �������� ������ \n";
		cout << "'3' - ����� ������� �������� �� ������� \n";
		cout << "'4' - �������� �������� �� ������� �������� \n";
		cout << "'5' - ���������� �� ������� \n";
		cout << "'6' - ������� ������ \n";

		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '1':
		{
			AddLast(list);
			cout << "������� �������� � �����\n";
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

			cout << "������� ������ ��������, ������ �������� ����� ������� \n";
			cin >> index;
			cout << "�����: " << Get(index, list) << endl;
			system("pause");
			break;
		}
		case '4':
		{
			cout << "������� ������ ��������, ������� ����� �������\n";
			cin >> index;
			Remove(index, list);
			system("pause");
			break;
		}
		case '5':
		{
			cout << "������� ������ ��������, ����� ������� ����� �������� �������\n";
			cin >> index;
			Insert(list, index);
			break;
		}
		case '6':
		{
			Clear(list);
			cout << "������ ������\n";
			system("pause");
			break;
		}
		}
	}
}