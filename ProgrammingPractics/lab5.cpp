#include "stdafx.h"
#include "PersonList.h"

using namespace std;

void LaunchLab5()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	char key;						
	int AsciiValue = 0;				

	PersonList list1;

	list1.Add(PersonTools::MakeRandomPerson());
	list1.Add(PersonTools::MakeRandomPerson());
	list1.Add(PersonTools::MakeRandomPerson());

	PersonList list2;

	list2.Add(PersonTools::MakeRandomPerson());
	list2.Add(PersonTools::MakeRandomPerson());
	list2.Add(PersonTools::MakeRandomPerson());
	

	while (AsciiValue != 27)
	{
		system("cls");

		SetConsoleTextAttribute(hStdOut, 2);

		cout << "Список 1";
		cout << "\n-------------------------------------------------------\n";
		list1.ShowList();
		cout << "-------------------------------------------------------\n";
		cout << "Список 2";
		cout << "\n-------------------------------------------------------\n";
		list2.ShowList();
		cout << "-------------------------------------------------------\n";

		SetConsoleTextAttribute(hStdOut, 3);
		cout << "Нажмите:";

		SetConsoleTextAttribute(hStdOut, 5);
		cout << "\n 1: Добавление в конец 1го списка ";
		cout << "\n 2: Копировние второго человека из первого списка в конец второго списка";
		cout << "\n 3: Удаление второго человека из первого списка";
		cout << "\n 4: Очистка второго списка";

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
			list1.Add(PersonTools::MakeRandomPerson());
			break;
		}
		case '2':
		{
			list2.Add(list1.Find(1));
			break;
		}
		case '3':
		{
			list1.RemoveAt(1);
			break;
		}
		case '4':
		{
			list2.Clear();
			break;
		}
		}
	}
}