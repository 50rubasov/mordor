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

		cout << "Нажмите... \n";
		cout << "'1' - Hello world \n";
		cout << "'2' - Калькулятор \n";
		


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

			cout << "input two values: ";        //Диалог: введите число

			while ((!(cin >> value1)) || (!(cin >> value2))) 
			{
				cout << "INCORRECT SYMBOL!!!\n Please, input two values again: ";
				cin.clear(); /*Сбрасываем ошибку*/
				while (cin.get() != '\n');/*Раз в строке есть посторонние символы, то эта строка нам не нужна, идём в конец строки*/
			}

			cout << ("\n Enter mathematic operation (+, -, *, /, %): ");
			operationKey = _getch();
			while ((operationKey != '+') && (operationKey != '-') && (operationKey != '*') && (operationKey != '/') && (operationKey != '%'))
			{
				//если введенный символ нас не устраивает, то нужно  
				//вывести сообщение на экран и запросить повторный ввод.  
				cout << "\nINCORRECT SYMBOL!!!\nPlease, enter (+, -, *, /, %):";
				operationKey = _getch();
				fflush(stdin);   //функция очистки стандартного буфера ввода      
								 //на случай ввода нескольких символов вместо одного 
			}
			cout << MakeCalculation(value1, value2, operationKey) << endl;

			system("pause");
			break;
		}
	}
	
}
