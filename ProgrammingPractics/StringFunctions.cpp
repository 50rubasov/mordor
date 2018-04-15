#include "stdafx.h"
#include "StringFunctions.h"
/*---------------------Копирование строки------------------------------*/
void CopyString(char* string1, const char* string2)		//копирование строки 
{
	int i = 0;
	for (; string2[i]; i++)
	{
		string1[i] = string2[i];
	}
	string1[i] = '\0';
}
/*---------------------Объединение строк------------------------------*/
char* Concatenate(char* string1, char* string2)
{
	int first = 0;
	int second = 0;
	for (int i = 0; string1[i] != '\0'; i++)
	{
		first++;
	}
	for (int i = 0; string2[i] != '\0'; i++)
	{
		string1[first + i] = string2[i];
		second++;
	}
	string1[first + second] = 0;
	return string1;
}
char* Concatenate(char* string1, const char* string2)
{
	int first = 0;
	int second = 0;
	for (int i = 0; string1[i] != '\0'; i++)
	{
		first++;
	}
	for (int i = 0; string2[i] != '\0'; i++)
	{
		string1[first + i] = string2[i];
		second++;
	}
	string1[first + second] = 0;
	return string1;
}