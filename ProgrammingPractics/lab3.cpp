#pragma once
#include "stdafx.h"
#include "lab3.h"


using namespace std;
/*---------------------Замена табов на пробелы-------------------------------*/
char* ReplaceTabsOnSpaces(char* string)
{
	char* result = new char[100];
	int i = 0;
	int j = 0;//разница

	for (; string[i]; i++)
	{
		if (string[i] == '\t')
		{
			for (; (i + j + 1) % 8 != 0; j++)
			{
				result[i + j] = ':';
			}
			result[i + j] = ':';
		}
		else
		{
			result[i + j] = string[i];
		}
	}
	result[i + j] = '\0';
	return result;
}

/*---------------------Поиск длинны строки------------------------------*/
int GetLength(char* string)
{
	int count = 0;
	for (int i = 0; string[i] != '\0'; i++)
	{
		count++;
	}
	return count;

}
/*---------------------Проверка на правильность ввода символов------------------------------*/
int EnterValue()
{
	int value;
	while (!(cin >> value))
	{
		cout << "НЕКОРРЕКТНЫЙ ВВОД!!!\n ВВЕДИТЕ ЗНАЧЕНИЕ ЕЩЕ РАЗ: ";
		cin.clear(); //Сбрасываем ошибку
		while (cin.get() != '\n');//Раз в строке есть посторонние символы, то эта строка нам не нужна, идём в конец строки
	}
	while (cin.get() != '\n');//Раз в строке есть посторонние символы, то эта строка нам не нужна, идём в конец строки
	return value;
}
/*---------------------Верхний регистр------------------------------*/
char* Uppercase(char* string)
{
	for (int i = 0; string[i] != '\0'; i++)
	{
		if ((string[i] > 96) && (string[i] < 123)) 
		{
			string[i] = string[i] - 32;
		}
	}
	return string;
}
/*---------------------Нижний регистр------------------------------*/
char* Lowercase(char* string)
{
	for (int i = 0; string[i] != '\0'; i++)
	{
		if ((string[i] > 64) && (string[i] < 90))
		{
			string[i] = string[i] + 32;
		}
	}
	return string;
}
/*---------------------Поиск подстроки в строке------------------------------*/
int FindSubstring(char* string, char* substring) 
{
	int j = 0;
	int count=0;
	for(int i=0; string[i] != '\0'; i++)
	{
		if (string[i] == substring[j])
		{
			for (; substring[j] != '\0'; j++)
			{
				if (substring[j+1] == string[i+1])
				{
					return i;
				}
			}
			j = 0;
		}
	}
return -1;
}
/*---------------------Объединение строк------------------------------*/
char* Concatenate(char* string1, char* string2) 
{
	int first = GetLength(string1);
	for (int i = 0; string2[i] != '\0'; i++)
	{
		string1[first + i] = string2[i];
	}
	string1[first + GetLength(string2)] = 0;
	return string1;
}
/*----------------------Вывод построки-----------------------------*/
char* GetSubstring(char* string, int startIndex, int charCount) 
{
	int length = GetLength(string);
	
	if ((startIndex >= 0) && (startIndex+charCount <= length) && (charCount > 0))
	{
		char* substring = new char[charCount + 1];
		for (int i = 0; i < charCount; i++) 
		{
			substring[i] = string[startIndex + i];
		}
		substring[charCount] = 0;
		return substring;
	}
	else return NULL;
}
/*-------------------------Разбитие файла на дерикторию, имя, расширение--------------------------*/
void SplitFilename(char* source, char* path, char* name, char* extension) 
{
	int slash = 0;
	int dot = 0;
	int length = GetLength(source + 1);
	int j = 0;
	for (int i = 0; source[i] != '\0'; i++)
	{
		if (source[i] == 92) //92 это "\"
		{
			slash = i+1;
		}
		if (source[i] == '.')
		{
			dot = i;
		}
	}
		if (slash > 0)
		{
			for (int i = 0; i < slash; i++)
			{
				path[j] = source[i];
				j++;
			}
			j = 0;
		}
		if (dot == 0)
		{
			dot = length+1;
		}
			for (int i = slash; i < dot; i++)
			{
				name[j] = source[i];
				j++;
			}
			j = 0;
			if (dot != length)
			{

				for (int i = dot; source[i] != '\0'; i++)
				{
					extension[j] = source[i];
					j++;
				}
				j = 0;
			}
	
}
/*--------------------------Проверка на надобность табуляции-------------------------*/
bool isNeedTab(char* string, int i, int tab)
{
	while (i % tab != 0)
	{
		if (string[i] != ':')
		{
			return false;
		}
		i++;
	}
	return true;
}
/*---------------------------Замена пробелов на табы------------------------*/
char* ReplaceSpacesOnTabs(char* string)
{
	char* resultString = new char[50];
	int tab = 8;
	int i = 0;
	int j = 0;

	for (; string[i + j]; i++)
	{
		if (string[i + j] == ':' && isNeedTab(string, i + j + 1, tab))
		{
			while ((i + j + 1) % 8 != 0)
			{
				j++;
			}
			resultString[i] = '\t';
		}
		else
		{
			resultString[i] = string[i + j];
		}
	}
	resultString[i] = '\0';
	return resultString;
}

/*----------------------------Работа со структурами-----------------------*/

Person ReadPerson()
{
	int key=0;
	Person person;
	cout << "\nВведите Фамилию: ";
	gets_s(person.Surname);
	cout << "\nВведите Имя: ";
	gets_s(person.Name);
	cout << "\nВведите Возраст: ";
	person.Age = EnterValue();
	cout << "\nУкажите пол: 0-Женский/1-Мужской" << endl;
	key = _getch() - 48;
	while ((key != 0) && (key != 1))
	{
		cout << "\nУкажите пол: 0-Женский/1-Мужской" << endl;
		key = _getch() - 48;
	}
	person.sex = (Sex)key;
	return person;
}
void PrintPerson(Person person)
{
	cout << "Фамилия: " << person.Surname << endl;
	cout << "Имя: " << person.Name << endl;
	if (person.sex == 1) 
	{
		cout << "Пол: Мужской" << endl;
	}
	else
	{
		cout << "Пол: Женский" << endl;
	}
	cout << "Возраст: " << person.Age << endl;
}
void LaunchLab3()
{
	setlocale(0, "");

	int ascii = 0;
	char key;

	while (ascii != 27)
	{
		system("cls");

		cout << "Нажмите... \n";
		cout << "'1' - Длинна строки \n";
		cout << "'2' - Объединение двух строк \n";
		cout << "'3' - Вывод подстроки \n";
		cout << "'4' - Поиск подстроки в строке \n";
		cout << "'5' - Приведение строки к регистру \n";
		cout << "'6' - Разделение строки \n";
		cout << "'7' - Замена табуляции на пробелы \n";
		cout << "'8' - Замена пробелов на табы \n";
		cout << "'9' - Структуры \n";

		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '1':
		{
			char str[20];
			cout << "Введите строку: ";
			gets_s(str); // Считываем строку с клавиатуры. 
			cout << GetLength(str) << endl;
			system("pause");
			break;
		}
		case '2':
		{
			char str1[20];
			cout << "Введите строку 1: ";
			gets_s(str1); 
			char str2[20];
			cout << "Введите строку 1: ";
			gets_s(str2);

			cout << Concatenate(str1, str2) << endl;;
			system("pause");
			break;
		}
		case '3':
		{
			char str[50];
			int startIndex, charCount;
			cout << "Введите строку: ";
			gets_s(str);
			cout << "Введите стартовый индекс: ";
			startIndex = EnterValue();
			cout << "Введите количество символов: ";
			charCount = EnterValue();
			char* substring = GetSubstring(str, startIndex, charCount);

			if (substring)
			{
				cout << substring << endl;
			}
			else cout << "NULL" << endl;

			delete[] substring;
			system("pause");
			break;
		}
		case '4':
		{
			
			char str[50], substring[50];
			cout << "Введите строку: ";
			gets_s(str);
			cout << "Введите подстроку: ";
			gets_s(substring);
			cout << FindSubstring(str,substring);
			system("pause");
			break;
		}
		case '5':
		{

			char str[100];
			cout << "Введите строку: ";
			gets_s(str);
			cout << "Нижний регистр: " << Lowercase(str) << endl;
			
			cout << "Верхний регистр: " << Uppercase(str) << endl;
			system("pause");
			break;
		}
		case '6':
		{
			char source[100] = "";
			char path[100] = "";
			char name[100] = "";
			char extension[100] = "";
			cout << "Введите путь: ";
			gets_s(source);
			SplitFilename(source, path, name, extension);
			cout << "Дериктория: " << path << endl;
			cout << "Название: " << name << endl;
			cout << "Расширение: " << extension << endl;
			system("pause");
			break;
		}
		case '7':
		{
			char str[] = "Cake\tis\ta lie!";
			cout << "!\t!\t!\t!\t!\t!" << endl;
			cout << str << endl;
			char* result = ReplaceTabsOnSpaces(str);
			cout << result;
			delete[] result;
			system("pause");
			break;
		}
		case '8':
		{

			//char str[] = "Cake::::is::a:lie!";
			char str[100];
			cout << "Введите строку с пробелами, которые нужно заменить на табы";
			gets_s(str);
			cout << "!\t!\t!\t!\t!\t!" << endl;
			cout << str << endl;
			char* result = ReplaceSpacesOnTabs(str);
			cout << result;
			delete[] result;
			system("pause");
			break;
		}
		case '9':
		{
			Person person = ReadPerson();
			PrintPerson(person);
			
			system("pause");
			break;
		}
		}
	}
}