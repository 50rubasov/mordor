#pragma once
#include <stdlib.h>
#include "lab3.h"
struct Node
{
	Person person;  
	Node* next = NULL;
	Node* prev = NULL;
};

struct List
{
	Node* head = NULL;
	Node* tail = NULL;
};
void CopyString(char* string1, const char* string2);	//����������� �����
void AddLast(List* list);								//���������� ������ � �����
void Show(List* list);									//����� ������ �� �����
Person MakeRandomPerson();								//��������� �������
Person* Get(int index, List* list);						//����� ������ �� �������
void Remove(int index, List* list);						//�������� �������� �� �������
void Clear(List* list);									//������� ������
void Insert(List* list, int index);						//���������� �������� �� �������
void LaunchLab4();