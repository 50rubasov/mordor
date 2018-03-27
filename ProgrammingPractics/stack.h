#pragma once
using namespace std;

struct Stack {
	int* array;
	int length;
	int bufsize;
};

//void Initial(Array* arr);						//Инициализация
void Resize(Stack* st);						//Изменение длины буфера
//void Add(Array* arr, int value, int index);		//Добавление элемента по индексу
//void Delete(Array* arr, int index);				//Удаление		
void PushStack(Stack* st, int value);
int PopStack(Stack* st);
void DelStack(Stack* st);
Stack* CreateStack();