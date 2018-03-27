#pragma once
#include "stdafx.h"
#include "lab4.h"
#include "lab3.h"
#include "stack.h"
using namespace std;


Person* MakeRandomPerson()								//��������� ��������� ��������
{
	Person *newPerson = new Person;

	char names[10][10] = { "�����","����", "����", "�����", "������", "�������","�������","�������","��������","�����" };
	char surnames[10][15] = { "������","�������", "���������", "�������", "�������", "�������","�������","�����","��������","�����" };
	CopyString(newPerson->Name, names[rand() % 10]);
	CopyString(newPerson->Surname, surnames[rand() % 10]);
	newPerson->Age = rand() % 100;
	newPerson->sex = Sex(male);

	return newPerson;
}
void AddLast(List* list, Person* person)								//���������� � ����� 
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
			PrintPerson(*node->person);
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
				return node->person;
			}
			node = node->next;
		}
	}
	return NULL;
}

void Remove(int index, List* list)						//�������� �������� �� �������
{
	Node* node = list->head;

	try //���, ������� ����� �������� � ������, ������������� ���
	{
		if ((index < 0) || (node == NULL))
		{
			throw 1; //������������ ������
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

	catch (int i)//���� ���������� ������
	{
		if (i == 1)
		{
			cout << "������ �" << i << " - ������ ������ ���� ��� ������ ����\n" << endl;
		}
		if (i == 2)
		{
			cout << "������ �" << i << " - ������ ������� �� ������� ������\n" << endl;
		}
	}

}

void Clear(List* list)									//������� ������
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

void Insert(List* list, Person* person, int index)						//���������� �������� �� �������
{
	Node* newNode = new Node;
	newNode->person = person;     //TODO ���������� ������� � ��������

	Node* node = list->head;

	try //���, ������� ����� �������� � ������, ������������� ���
	{
		if ((index < 0) || (node == NULL))
		{
			throw 1; //������������ ������
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

	catch (int i)//���� ���������� ������
	{
		if (i == 1)
		{
			cout << "������ �" << i << " - ������ ������ ���� ��� ������ ����\n" << endl;
		}
		if (i == 2)
		{
			cout << "������ �" << i << " - ������ ������� �� ������� ������\n" << endl;
		}
	}
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
	int index, value;
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
		cout << "'7' - ���� \n";

		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '1':
		{
			AddLast(list, MakeRandomPerson());
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
			Insert(list, MakeRandomPerson(), index);
			system("pause");
			break;
		}
		case '6':
		{
			Clear(list);
			cout << "������ ������\n";
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

				cout << "������� �������\n";
				cout << "1: ���������� � �����" << endl;
				cout << "2: ���������� �������� " << endl;
				cout << "3: �������� �������� " << endl;

				key = _getch();
				AssciiValue1 = key;

				switch (AssciiValue1)
				{
				case '1':

					cout << endl << "����: ";
					for (int i = 0; i < stack->length; i++)
					{
						cout << stack->array[i] << " ";
					}
					cout << endl;
					cout << "����� �����: " << stack->length << endl;
					cout << "����� ������: " << stack->bufsize << endl;
					system("pause");
					break;

				case '2':

					cout << "������� ����������� �������\n";
					cin >> value;
					PushStack(stack, value);
					break;
				case '3':
					if (stack->length > 0)
					{
						int data = PopStack(stack);
						cout << endl << "���������� ������� = " << data << "\n";
						system("pause");
					}
					else
					{
						cout << endl << "���� ����" << endl;
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