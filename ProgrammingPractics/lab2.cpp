#include "lab1.h"
#include "stdafx.h"

using namespace std;

void PrintHelloWorld() 
{ 
	cout << "Hello, World!\n"; 
}

double MakeCalculation(int value1, int value2, char  operationKey)
{
	if (operationKey == '+')
	{
		return value1 + value2;
	}
	if (operationKey == '*')
	{
		return value1 * value2;
	}
	else if (operationKey == '-')
	{
		return value1 - value2;
	}
	else if (operationKey == '/')
	{
		return value1 / value2;
	}
	else if (operationKey == '%')
	{
		return value1 % value2;
	}

}

void LaunchLab2()
{
	setlocale(0, "");

	int ascii = 0;
	char key;

	while (ascii != 27)
	{
		system("cls");

		cout << "�������... \n";
		cout << "'1' - Hello world \n";
		cout << "'2' - ����������� \n";
		


		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '1':
			PrintHelloWorld();
			system("pause");
			break;
		case'2':
			int value1, value2;
			char operationKey;

			cout << "input two values: ";        //������: ������� �����

			while ((!(cin >> value1)) || (!(cin >> value2))) 
			{
				cout << "INCORRECT SYMBOL!!!\n Please, input two values again: ";
				cin.clear(); /*���������� ������*/
				while (cin.get() != '\n');/*��� � ������ ���� ����������� �������, �� ��� ������ ��� �� �����, ��� � ����� ������*/
			}

			cout << ("\n Enter mathematic operation (+, -, *, /, %): ");
			operationKey = _getch();
			while ((operationKey != '+') && (operationKey != '-') && (operationKey != '*') && (operationKey != '/') && (operationKey != '%'))
			{
				//���� ��������� ������ ��� �� ����������, �� �����  
				//������� ��������� �� ����� � ��������� ��������� ����.  
				cout << "\nINCORRECT SYMBOL!!!\nPlease, enter (+, -, *, /, %):";
				operationKey = _getch();
				fflush(stdin);   //������� ������� ������������ ������ �����      
								 //�� ������ ����� ���������� �������� ������ ������ 
			}
			cout << MakeCalculation(value1, value2, operationKey) << endl;

			system("pause");
			break;
		}
	}
	
}
