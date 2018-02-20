#include "lab1.h"
#include "stdafx.h"
#include <conio.h>
using namespace std;

void task1() 
{
	cout << "Hello, World!\n";

	
	int a; // Объявление
	a = 5; // Инициализация
	int b = 3; 
	cout << "\n Variable a equals " << a; //вывод значений
	cout << "\n Variable b equals " << b;
	cout << "\n Summ of a and b equal = " << a + b << endl; 
}
void task2()
{
	int a = 5;
	int b = 3;
	float z = 5.0;
	float y = 3.0;
	cout << "Float variables division: " << z / y << endl;
	cout << "Integer variables division: " << a / b << endl;

}
void task3()
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
void task4() {
	int value;
	int* pointer; // Объявление указателя на целочисленный тип данных
	int anotherValue;
	value = 5;
	pointer = &value;  // Операция взятия адреса переменной       
					   // pointer может хранить адрес только       
					   // целочисленной переменной 
	anotherValue = *pointer; // Операция разыменования 
							 // Вывод значения, полученного при разыменовании указателя 
	cout << "Value, stored in pointer: " << anotherValue << endl;
	// Вывод адреса, который хранится в указателе 
	cout << "Address in pointer: " << pointer << endl;
	// Вывод результата разыменования указателя
	cout << "Value in pointer:" << *pointer << endl;

}
void task5() {
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
			break; // досрочное завершение
		}
	}
	cout << "\n A is " << a << endl;
}
void task11() {
	int a = 5;
	int b = 3;
	float z;
	// Неявное приведение типов 
	z = a;
	cout << endl << "Value of z is " << z << endl;
	// Явное приведение типов 
	a = (int)z;
	cout << endl << "Value of a is " << a << endl;
	// Неявное приведение результата деления  
	// целочисленных переменных 
	z = a / b;
	cout << endl << "Value of z is " << z << endl;
	// Явное приведение а к float и неявное b к float  
	// для выполнения деления
	z = ((float)a) / b;
	cout << endl << "Value of z is " << z << endl;
}

void launchLab1() 
{
	setlocale(0, "");

	int ascii = 0;
	char key;

	while (ascii != 27)
	{
		system("cls");

		cout << "Нажмите... \n";
		cout << "'1' - Hello world и инициализация \n";
		cout << "'2' - Деление целочисленных вещественных переменных  \n";
		cout << "'3' - Чтение двух переменных и вывод их суммы \n";
		cout << "'4' - Работа указателя, операция разыменования и взятия адреса \n";
		cout << "'5' - Четное/нечетное число \n";
		cout << "'6' - Кратность введенного числа 5 или 2 \n";
		cout << "'7' - Цикл с пред-условием \n";
		cout << "'8' - Цикл с пост-условием \n";
		cout << "'9' - Итерационный цикл \n";
		cout << "'0' - Break для досрочного завершения работы \n";
		cout << "'-' - Преобразование типов данных \n";


		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '1':
			task1();
			system("pause");
			break;
		case '2':
			task2();
			system("pause");
			break;
		case '3':
			task3();
			system("pause");
			break;
		case '4':
			task4();
			system("pause");
			break;
		case '5':
			task5();
			system("pause");
			break;
		case '6':
			task6();
			system("pause");
			break;
		case '7':
			task7();
			system("pause");
			break;
		case '8':
			task8();
			system("pause");
			break;
		case '9':
			task9();
			system("pause");
			break;
		case '0':
			task10();
			system("pause");
			break;
		case '-':
			task11();
			system("pause");
			break;
		}
	}
}