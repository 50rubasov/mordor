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

char* ReplaceTabsOnSpaces(char* string);									//������ ����� �� �������
char* ReplaceSpacesOnTabs(char* string);									//������ �������� �� ����
bool isNeedTab(char* string, int i, int tab);								//�������� �� ���������� ���������(���� �� �����-������ ������� ����� ��������)
int EnterValue();															//�������� �� ������������ ����� � �������� ����
char* Uppercase(char* string);												//������� ��������
char* Lowercase(char* string);												//������ �������
void SplitFilename(char* source, char* path, char* name, char* extension);	//���������� ���������� �����


void PrintPerson(Person person);

int GetLength(char* string);												//���������� ������ ������	
char* Concatenate(char* string1, char* string2);							//����������� �����
char* GetSubstring(char* string, int startIndex, int charCount);			//����� ���������
int FindSubstring(char* string, char* substring);							//����� ��������� � ������

void LaunchLab3();
