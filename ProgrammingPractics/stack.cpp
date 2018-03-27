#include "stdafx.h"
#include "stack.h"

using namespace std;

void Resize(Stack* st)
{
	st->bufsize *= 2;
	int* pdarr = new int[st->bufsize];

	for (int i = 0; i < st->length; i++)
	{
		pdarr[i] = st->array[i];
	}
	delete[] st->array;
	st->array = pdarr;
}

void PushStack(Stack* st, int value)
{
	if (st->length == st->bufsize)
		Resize(st);
	st->array[st->length] = value;
	st->length++;
}
void DelStack(Stack* st)
{
	delete[] st->array;
	delete st;
}
int PopStack(Stack* st)
{
	st->length--;
	return st->array[st->length];
}


Stack* CreateStack()
{
	Stack* st = new Stack;
	st->bufsize = 2;
	st->length = 0;
	st->array = new int[st->bufsize];
	return st;
}