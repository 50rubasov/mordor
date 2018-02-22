#include "lab1.h"
#include "stdafx.h"
#include <conio.h>

using namespace std;

void Initialization()
{
	cout << "Hello, World!\n";

	
	int a; // ����������
	a = 5; // �������������
	int b = 3; 
	cout << "\n Variable a equals " << a; //����� ��������
	cout << "\n Variable b equals " << b;
	cout << "\n Summ of a and b equal = " << a + b << endl; 
}
void Division()
{
	int a = 5;
	int b = 2;
	float z = 5.0;
	float y = 3.0;
	cout << "Float variables division: " << z / y << endl;
	cout << "Integer variables division: " << a / b << endl;

}

void Addition()
{

	int a;
	int b;
	cout << "Program for integer summation";
	cout << "\n\n Enter first integer value: ";
	cin >> a;
	cout << "\n\n Enter second integer value: ";
	cin >> b;
	cout << " \n Summ of and equals " << a << " " << b << " = " << a + b << endl;

}

void Pointer()
{
	int value;
	int* pointer; // ���������� ��������� �� ������������� ��� ������
	int anotherValue;
	value = 5;
	pointer = &value;  // �������� ������ ������ ����������       
					   // pointer ����� ������� ����� ������       
					   // ������������� ���������� 
	anotherValue = *pointer; // �������� ������������� 
							 // ����� ��������, ����������� ��� ������������� ��������� 
	cout << "Value, stored in pointer: " << anotherValue << endl;
	// ����� ������, ������� �������� � ��������� 
	cout << "Address in pointer: " << pointer << endl;
	// ����� ���������� ������������� ���������
	cout << "Value in pointer:" << *pointer << endl;

}
void ParityOddness()
{
	int a;
	cout << "Enter value for check on even/odd: ";
	cin >> a;
	if (a % 2 == 0)
	{
		cout << "\n Value is " << a << " even!" << endl;
	}
	else
	{
		cout << "\n Value is " << a << " odd!" << endl;
	}
}
void Multiplicity()
{
	int a;
	cout << "Enter value for check on even/odd: ";
	cin >> a;
	if (a % 5 == 0)
	{
		cout << "\n Value " << a << " multiples 5!" << endl;;
	}
	else if (a % 2 == 0)
	{
		cout << "\n Value " << a << " multiples 2!" << endl;
	}
	else
	{
		cout << "\n Value " << a << " doesn`t multiply 5 or 2!" << endl;
	}
}
void Precondition()
{
	int a = 0;
	while (a < 5) 
	{
		cout << "Value is " << a << " now \n";
		a++;
	}
}

void Postcondition()
{
	int a = 0;
	do 
	{
		cout << "Value is " << a << " now \n";
		a++;
	} while (a < 5);
}

void Iterative()
{
	int a = 10;
	for (int i = 0; i < 10; i++)
	{
		cout << "Iteration =" << i << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < a; i++)
	{
		a--;
		cout << "Iteration " << i << "   Value is " << a << endl;;
	}
}

void EarlyCompletion() {
	cout << "\n" << "\n" << endl << endl;
	int a = 10; 
	for (int i = 0; i < 10; i++)
	{
		a--;
		if (i >= a)
		{
			cout << endl << "I is more or equal A! Break of cycle";
			break; // ��������� ����������
		}
	}
	cout << "\n A is " << a << endl;
}
void Converting() {
	int a = 5;
	int b = 3;
	float z;
	// ������� ���������� ����� 
	z = a;
	cout << endl << "Value of z is " << z << endl;
	// ����� ���������� ����� 
	a = (int)z;
	cout << endl << "Value of a is " << a << endl;
	// ������� ���������� ���������� �������  
	// ������������� ���������� 
	z = a / b;
	cout << endl << "Value of z is " << z << endl;
	// ����� ���������� � � float � ������� b � float  
	// ��� ���������� �������
	z = ((float)a) / float(b);
	cout << endl << "Value of z is " << z << endl;
}

void LaunchLab1() 
{
	setlocale(0, "");

	int ascii = 0;
	char key;

	while (ascii != 27)
	{
		system("cls");

		cout << "�������... \n";
		cout << "'1' - Hello world � ������������� \n";
		cout << "'2' - ������� ������������� ������������ ����������  \n";
		cout << "'3' - ������ ���� ���������� � ����� �� ����� \n";
		cout << "'4' - ������ ���������, �������� ������������� � ������ ������ \n";
		cout << "'5' - ������/�������� ����� \n";
		cout << "'6' - ��������� ���������� ����� 5 ��� 2 \n";
		cout << "'7' - ���� � ����-�������� \n";
		cout << "'8' - ���� � ����-�������� \n";
		cout << "'9' - ������������ ���� \n";
		cout << "'0' - Break ��� ���������� ���������� ������ \n";
		cout << "'-' - �������������� ����� ������ \n";


		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '1':
			Initialization();
			system("pause");
			break;
		case '2':
			Division();
			system("pause");
			break;
		case '3':
			Addition();
			system("pause");
			break;
		case '4':
			Pointer();
			system("pause");
			break;
		case '5':
			ParityOddness();
			system("pause");
			break;
		case '6':
			Multiplicity();
			system("pause");
			break;
		case '7':
			Precondition();
			system("pause");
			break;
		case '8':
			Postcondition();
			system("pause");
			break;
		case '9':
			Iterative();
			system("pause");
			break;
		case '0':
			EarlyCompletion();
			system("pause");
			break;
		case '-':
			Converting();
			system("pause");
			break;
		}
	}
}

