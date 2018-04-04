#include "stdafx.h"
using namespace std;
int CorrectEnter()
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

bool CheckChar(char* name)
{
	bool isCorrect = true;
	for (int i = 0; i < strlen(name); i++)
	{
		if (isdigit(name[i]) || isspace(name[i]))
		{
			isCorrect = false;
			break;
		}

		if (name[i] == '-')
		{
			if (islower(name[i + 1]))
			{
				name[i + 1] = toupper(name[i + 1]);
			}
			else
			{
				isCorrect = false;
				break;
			}
		}
	}
	return isCorrect;
}