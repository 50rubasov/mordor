#pragma once
#include <stdlib.h>
#include "lab3.h"
struct Node
{
	Person* person;  //TODO сделать указателем
	Node* next = NULL;
	Node* prev = NULL;
};

struct List
{
	Node* head = NULL;
	Node* tail = NULL;
};
void CopyString(char* string1, const char* string2);	//копирование строк
void AddLast(List* list, Person* person);								//добавление списка в конец
void Show(List* list);									//вывод списка на экран
Person* MakeRandomPerson();								//рандомные персоны
Person* Get(int index, List* list);						//поиск адреса по индексу
void Remove(int index, List* list);						//удаление элемента по индексу
void Clear(List* list);									//очистка списка
void Insert(List* list, Person* person, int index);						//добавление элемента до массива
void LaunchLab4();