#pragma once
#include "stdafx.h"
#include "lab3.h"


using namespace std;
/*---------------------������ ����� �� �������-------------------------------*/
char* ReplaceTabsOnSpaces(char* string)
{
	char* result = new char[100];
	int i = 0;
	int j = 0;//�������

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

/*---------------------����� ������ ������------------------------------*/
int GetLength(char* string)
{
	int count = 0;
	for (int i = 0; string[i] != '\0'; i++)
	{
		count++;
	}
	return count;

}
/*---------------------�������� �� ������������ ����� ��������------------------------------*/
int EnterValue()
{
	int value;
	while (!(cin >> value))
	{
		cout << "������������ ����!!!\n ������� �������� ��� ���: ";
		cin.clear(); //���������� ������
		while (cin.get() != '\n');//��� � ������ ���� ����������� �������, �� ��� ������ ��� �� �����, ��� � ����� ������
	}
	while (cin.get() != '\n');//��� � ������ ���� ����������� �������, �� ��� ������ ��� �� �����, ��� � ����� ������
	return value;
}
/*---------------------������� �������------------------------------*/
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
/*---------------------������ �������------------------------------*/
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
/*---------------------����� ��������� � ������------------------------------*/
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
/*---------------------����������� �����------------------------------*/
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
/*----------------------����� ��������-----------------------------*/
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
/*-------------------------�������� ����� �� ����������, ���, ����������--------------------------*/
void SplitFilename(char* source, char* path, char* name, char* extension) 
{
	int slash = 0;
	int dot = 0;
	int length = GetLength(source + 1);
	int j = 0;
	for (int i = 0; source[i] != '\0'; i++)
	{
		if (source[i] == 92) //92 ��� "\"
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
/*--------------------------�������� �� ���������� ���������-------------------------*/
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
/*---------------------------������ �������� �� ����------------------------*/
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

/*----------------------------������ �� �����������-----------------------*/

Person ReadPerson()
{
	int key=0;
	Person person;
	cout << "\n������� �������: ";
	gets_s(person.Surname);
	cout << "\n������� ���: ";
	gets_s(person.Name);
	cout << "\n������� �������: ";
	person.Age = EnterValue();
	cout << "\n������� ���: 0-�������/1-�������" << endl;
	key = _getch() - 48;
	while ((key != 0) && (key != 1))
	{
		cout << "\n������� ���: 0-�������/1-�������" << endl;
		key = _getch() - 48;
	}
	person.sex = (Sex)key;
	return person;
}
void PrintPerson(Person person)
{
	cout << "�������: " << person.Surname << endl;
	cout << "���: " << person.Name << endl;
	if (person.sex == 1) 
	{
		cout << "���: �������" << endl;
	}
	else
	{
		cout << "���: �������" << endl;
	}
	cout << "�������: " << person.Age << endl;
}
void LaunchLab3()
{
	setlocale(0, "");

	int ascii = 0;
	char key;

	while (ascii != 27)
	{
		system("cls");

		cout << "�������... \n";
		cout << "'1' - ������ ������ \n";
		cout << "'2' - ����������� ���� ����� \n";
		cout << "'3' - ����� ��������� \n";
		cout << "'4' - ����� ��������� � ������ \n";
		cout << "'5' - ���������� ������ � �������� \n";
		cout << "'6' - ���������� ������ \n";
		cout << "'7' - ������ ��������� �� ������� \n";
		cout << "'8' - ������ �������� �� ���� \n";
		cout << "'9' - ��������� \n";

		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '1':
		{
			char str[20];
			cout << "������� ������: ";
			gets_s(str); // ��������� ������ � ����������. 
			cout << GetLength(str) << endl;
			system("pause");
			break;
		}
		case '2':
		{
			char str1[20];
			cout << "������� ������ 1: ";
			gets_s(str1); 
			char str2[20];
			cout << "������� ������ 1: ";
			gets_s(str2);

			cout << Concatenate(str1, str2) << endl;;
			system("pause");
			break;
		}
		case '3':
		{
			char str[50];
			int startIndex, charCount;
			cout << "������� ������: ";
			gets_s(str);
			cout << "������� ��������� ������: ";
			startIndex = EnterValue();
			cout << "������� ���������� ��������: ";
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
			cout << "������� ������: ";
			gets_s(str);
			cout << "������� ���������: ";
			gets_s(substring);
			cout << FindSubstring(str,substring);
			system("pause");
			break;
		}
		case '5':
		{

			char str[100];
			cout << "������� ������: ";
			gets_s(str);
			cout << "������ �������: " << Lowercase(str) << endl;
			
			cout << "������� �������: " << Uppercase(str) << endl;
			system("pause");
			break;
		}
		case '6':
		{
			char source[100] = "";
			char path[100] = "";
			char name[100] = "";
			char extension[100] = "";
			cout << "������� ����: ";
			gets_s(source);
			SplitFilename(source, path, name, extension);
			cout << "����������: " << path << endl;
			cout << "��������: " << name << endl;
			cout << "����������: " << extension << endl;
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
			cout << "������� ������ � ���������, ������� ����� �������� �� ����";
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