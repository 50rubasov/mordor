#include "stdafx.h"
#include "List.h"
#include "lab7.h"
using namespace std;

void LaunchLab7()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	char key;						
	int AsciiValue = 0;				

	while (AsciiValue != 27)
	{
		SetConsoleTextAttribute(hStdOut, 2);

		SetConsoleTextAttribute(hStdOut, 3);
		cout << "Нажмите:";

		SetConsoleTextAttribute(hStdOut, 5);
		cout << "\n 1: Демонстрация на вещественных";
		cout << "\n 2: Демонстрация на *Person";
		cout << "\n 3: Демонстрация на вещественном массиве";
		cout << "\n 4: Демонстрация на вещественном списке";

		SetConsoleTextAttribute(hStdOut, 4);
		cout << "\nНажмите Esc для выхода";
		cout << "\n------------------------------------------------------\n";

		key = _getch();
		AsciiValue = key;

		SetConsoleTextAttribute(hStdOut, 7);


		switch (AsciiValue)
		{
		case '1':
		{
			List<double> list;

			cout << "Добавление в список пять элементов\n";

			list.AddLast(1.1);
			list.AddLast(1.2);
			list.AddLast(-1.3);
			list.AddLast(1.4);
			list.AddLast(1.6);

			list.Show();
			system("pause");

			cout << "Удаление второго \n";

			list.RemoveAt(2);

			list.Show();
			system("pause");

			cout << "Добавление элемента по индексу\n";

			list.Insert(50.0, 3);

			list.Show();
			system("pause");

			break;
		}

		case '2':
		{
			List<Person*> list;

			cout << "Добавление в список пять элементов\n";

			list.AddLast(PersonTools::MakeRandomPerson());
			list.AddLast(PersonTools::MakeRandomPerson());
			list.AddLast(PersonTools::MakeRandomPerson());
			list.AddLast(PersonTools::MakeRandomPerson());
			list.AddLast(PersonTools::MakeRandomPerson());

			list.Show();
			system("pause");

			cout << "Удаление второго \n";

			list.RemoveAt(2);

			list.Show();
			system("pause");

			cout << "Добавление элемента по индексу\n";

			list.Insert(PersonTools::MakeRandomPerson(), 3);

			list.Show();
			system("pause");

			break;
		}

		case '3':
		{
			List<double*> list;

			double arr1[] = { 1.1, -2.1, -4.33, 9.1, 4.3 };
			double arr2[] = { 2.1, -1.1, 3.8, 4.44, 0.1 };
			double arr3[] = { 3.3, 0.3, -1.4, -5.5, 0.5 };

			cout << "Добавление в список трех элементов\n";

			list.AddLast(arr1);
			list.AddLast(arr2);

			list.Show();
			system("pause");

			cout << "Удаление второго \n";

			list.RemoveAt(2);

			list.Show();
			system("pause");

			cout << "Добавление элемента по индексу\n";

			list.Insert(arr3, 3);

			list.Show();
			system("pause");

			break;
		}

		case '4':
		{
			List<List<double>*> list;

			List<double> list1;

			list1.AddLast(5.2);
			list1.AddLast(21.4);
			list1.AddLast(15.3);
			list1.AddLast(7.21);
			list1.AddLast(13.12);

			List<double> list2;
			list2.AddLast(-1.33);
			list2.AddLast(-5.76);
			list2.AddLast(-9.09);
			list2.AddLast(-8.65);
			list2.AddLast(-2.43);

			List<double> list3;
			list3.AddLast(13.45);
			list3.AddLast(54.11);
			list3.AddLast(87.54);
			list3.AddLast(63.96);
			list3.AddLast(13.54);

			cout <<  "Добавление в список двух элементов\n";

			list.AddLast(&list1);
			list.AddLast(&list2);

			list.Show();
			system("pause");

			cout << "Удаление по индексу \n";

			list.RemoveAt(2);

			list.Show();
			system("pause");

			cout << "Добавление по индексу\n";

			list.Insert(&list3, 3);

			list.Show();
			system("pause");

			break;
		}
		}
	}
}