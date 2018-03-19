#pragma once

enum Sex
{
	male,
	famale
};

struct Person
{
	char Surname[40];
	char Name[20];
	int Age;
	Sex sex;

};

char* ReplaceTabsOnSpaces(char* string);									//Замена табов на пробелы
char* ReplaceSpacesOnTabs(char* string);									//Замена пробелов на табы
bool isNeedTab(char* string, int i, int tab);								//Проверка на надобность табуляции(есть ли какие-нибудь символы кроме пробелов)
int EnterValue();															//Проверка на правильность ввода и отчистка кода
char* Uppercase(char* string);												//Верхний регистра
char* Lowercase(char* string);												//Нижний регистр
void SplitFilename(char* source, char* path, char* name, char* extension);	//Разделение дериктории файла


void PrintPerson(Person person);

int GetLength(char* string);												//Нахождение длинны строки	
char* Concatenate(char* string1, char* string2);							//Объединение строк
char* GetSubstring(char* string, int startIndex, int charCount);			//Вывод подстроки
int FindSubstring(char* string, char* substring);							//Поиск подстроки в строке

void LaunchLab3();
