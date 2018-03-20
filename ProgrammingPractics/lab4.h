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

void AddLast(List* list);
void GetLength(List* list);
void Show(List* list);
Person MakeRandomPerson();
void LaunchLab4();