#include "stdafx.h"
#include "Adult.h"
#include "Child.h"
#include "PersonList.h"

using namespace std;

void LaunchLab6()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	char key;
	int AsciiValue = 0;

	PersonList list;
	while (AsciiValue != 27)
	{
	system("cls");
		SetConsoleTextAttribute(hStdOut, 2);


		list.ShowDescriptions();

		SetConsoleTextAttribute(hStdOut, 3);
		cout << "Нажмите:";

		SetConsoleTextAttribute(hStdOut, 5);
		cout << "\n 1: Взрослый";

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
		list.Add(Adult::GetRandomAdult());
		list.Add(Child::GetRandomChild());
		break;
		}
		}
	}
}