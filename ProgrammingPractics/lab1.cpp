#include "lab1.h"
#include "stdafx.h"

using namespace std;

void task1() 
{
	cout << "Hello, World!\n";

	
	int a; // ����������
	a = 5; // �������������
	int b = 3; 
	cout << "\n Variable a equals " << a; //����� ��������
	cout << "\n Variable b equals " << b;
	cout << "\n Summ of a and b equal = " << a + b; 
}
void task2()
{
	int a = 5;
	int b = 3;
	float z = 5.0;
	float y = 3.0;
	cout << "Float variables division: \n" << z / y;
	cout << endl << "Integer variables division:\n" << a / b;

}
void task3()
{
	int a;
	int b;
	cout << "-- - Program for integer summation-- - ";
	cout << "\n\n Enter first integer value: ";
	cin >> a;
	cout << "\n\n Enter second integer value: ";
	cin >> b;
	cout << " \n Summ of and equals \n" << a << " " << b << " " << a + b;

}
void task4() {
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
void task5() {
	int a;
	cout << "Enter value for check on even/odd: ";
	cin >> a;
	if (a % 2 == 0)
	{
		cout << "\n Value is " << a << " even!";
	}
	else
	{
		cout << "\n Value is " << a << " odd!";
	}
}
void task6() {
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
void task7() {
	int a = 0;
	while (a < 5) 
	{
		cout << "Value is " << a << " now \n";
		a++;
	}
}
void task8() {
	int a = 0;
	do 
	{
		cout << "Value is " << a << " now \n";
		a++;
	} while (a < 5);
}
void task9() {
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
void task10() {
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
	cout << "\n A is " << a;
}
void task11() {
	int a = 5;
	int b = 3;
	float z;
	// ������� ���������� ����� 
	z = a;
	cout << endl << "Value of z is " << z << endl;
	// ����� ���������� ����� 
	a = (int)z;
	cout << endl << "Value of a is \n" << a << endl;
	// ������� ���������� ���������� �������  
	// ������������� ���������� 
	z = a / b;
	cout << endl << "Value of z is \n" << z << endl;
	// ����� ���������� � � float � ������� b � float  
	// ��� ���������� �������
	z = ((float)a) / b;
	cout << endl << "Value of z is \n" << z << endl;
}