#include "lab1.h"
#include "stdafx.h"

using namespace std;

int globalVariable = 7;

void GlobalPlusTwo() 
{
	globalVariable += 2;
}
void GlobalMultiplyThree() 
{
	globalVariable *= 3; 
}
void GlobalEqualsOne() 
{ 
	globalVariable = 1; 
}

int CinDigit()
{
	int value;
	while (!(cin >> value))
	{
		cout << "������������ ����!!!\n ������� �������� ��� ���: ";
		cin.clear(); //���������� ������
		while (cin.get() != '\n');//��� � ������ ���� ����������� �������, �� ��� ������ ��� �� �����, ��� � ����� ������
	}
	return value;
}

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

int PointerGetRoots(int a, int b, int c, double* x1, double* x2) 
{
	int D, countRoots;
	if ((a == 0) && (b!=0))
	{
		countRoots = 1;
		*x1 = -c/b;
		cout << "x = " << *x1 << endl;
	}
	if ((a == 0)&&(b==0))
	{
		countRoots = 0;
	}
	else if (a != 0)
	{
		D = b * b - 4 * a * c;
		cout << "������������ = " << D << endl;
		if (D > 0)
		{
			countRoots = 2;
			*x1 = (-b - sqrt(D)) / 2 * a;
			*x2 = (-b + sqrt(D)) / 2 * a;

			cout << "x1 = " << *x1 << endl;
			cout << "x2 = " << *x2 << endl;
		}
		else if (D == 0)
		{
			countRoots = 1;
			*x1 = (-b + sqrt(D)) / 2 * a;
			cout << "x = " << *x1 << endl;
		}
		else if (D < 0)
		{
			countRoots = 0;
		}
	}
	return countRoots;
}
int ReferenceGetRoots(int a, int b, int c, double& x1, double& x2)
{
	int D, countRoots;
	if ((a == 0) && (b != 0))
	{
		countRoots = 1;
		x1 = -c / b;
		cout << "x = " << x1 << endl;
	}
	if ((a == 0) && (b == 0))
	{
		countRoots = 0;
	}
	else if (a != 0)
	{
		D = b * b - 4 * a * c;
		cout << "������������ = " << D << endl;
		if (D > 0)
		{
			countRoots = 2;
			x1 = (-b - sqrt(D)) / 2 * a;
			x2 = (-b + sqrt(D)) / 2 * a;

			cout << "x1 = " << x1 << endl;
			cout << "x2 = " << x2 << endl;
		}
		else if (D == 0)
		{
			countRoots = 1;
			x1 = (-b + sqrt(D)) / 2 * a;
			cout << "x = " << x1 << endl;
		}
		else if (D < 0)
		{
			countRoots = 0;
		}
	}
	return countRoots;
}

void SummNumbers(int value1, int value2) //���������� ����� ���� ������������� ����������  
{
	cout << "����� �����: "<< value1 + value2 << endl; 
}
void SummNumbers(double value1, double value2) //���������� ����� ���� ������������� ���������� 

{  
	cout << "����� ������������: " << value1 + value2 << endl;
} 
void SummNumbers(int value1, double value2) 
{  
	cout << "����� ����� � ������������: " << value1+value2 << endl; 
}

int GetPower(int base, int power) 
{
	if (power == 0) 
	{ 
		return 1; 
	}
	else
	{
		return base * GetPower(base, power-1);
	}
}

void PlayGame()
{
	srand(time(NULL));    // ��� ������� ���������� ���������� �����  
	cout << "\n---������ ����� 2.0---\n";  
	int range = 10;
	cout << "\n������ �������� �����: ";
	range = CinDigit();
	int guessNumber = rand()%range;   // ��������� ������������ �����   
	int enteredNumber;   // �������� ������������� �����  

	int shots = 1;     // ���������� ���������
	int attempt = 2;
	cout << "\n ����� ����� �� 0 �� " << range << ": ";
	enteredNumber = CinDigit();
	while ((guessNumber != enteredNumber)  && (attempt > 0))
	{   
		shots++;   

		cout << "�� �����. � ���� �������� " << attempt << " �������" << endl;
		cout << "����� ����� ��� ���: ";
		enteredNumber = CinDigit();
		attempt--;
	} 
	if(attempt > 0)
	{
		cout << "�� ������� � " << shots << " �������. ���!!!!";

	

		Sleep(250);
		Beep(264, 125);
		Sleep(250);
		Beep(264, 125);
		Sleep(125);
		Beep(297, 500);
		Sleep(125);
		Beep(264, 500);
		Sleep(125);
		Beep(396, 500);
		Sleep(125);
		Beep(352, 1000);
	}
	else
	{
		cout << "�� �� ��������, ����� ������ ";
		int a = 750;

		Beep(622, a*0.75);
		Beep(466, a*0.25);

		Beep(369, a);
		Beep(311, a*0.75);
		Beep(466, a*0.25);
		Beep(392, a * 2);
		
	}
}

void BubbleSortArray1(double doubleArray[5])
{ 
	for (int i = 4; i > 0; i--)
	{
		for (int j = 0; j<i; j++)
		{
			if (doubleArray[j] > doubleArray[j + 1])
			{
				int tmp = doubleArray[j];
				doubleArray[j] = doubleArray[j + 1];
				doubleArray[j + 1] = tmp;
			}
		}
	}
}
void BubbleSortArray2(double doubleArray[], int arraySize)
{
	for (int i = arraySize-1; i > 0; i--)
	{
		for (int j = 0; j<i; j++)
		{
			if (doubleArray[j] > doubleArray[j + 1])
			{
				int tmp = doubleArray[j];
				doubleArray[j] = doubleArray[j + 1];
				doubleArray[j + 1] = tmp;
			}
		}
	}
}
void BubbleSortArray3(double* arrayPointer, int arraySize)
{ 
	
	for (int i = arraySize - 1; i > 0; i--)
	{
		for (int j = 0; j<i; j++)
		{
			if (arrayPointer[j] > arrayPointer[j + 1])
			{
				int tmp = arrayPointer[j];
				arrayPointer[j] = arrayPointer[j + 1];
				arrayPointer[j + 1] = tmp;
			}
		}
	}
}

void MultiplyMatrices(int** matrixA, int rowsA, int columnsA, int** matrixB, int rowsB, int columnsB, int** matrixResult)
{
	for (int i = 0; i < rowsA; i++)
	{
		for (int j = 0; j < columnsB; j++)
		{
			matrixResult[i][j] = 0;
			for (int k = 0; k < columnsA; k++)
			{
				matrixResult[i][j] += (matrixA[i][k] * matrixB[k][j]);
			}
		}
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
		cout << "'3' - ������� ����������� ���������(����� ���������) \n";
		cout << "'4' - ������� ����������� ���������(����� ������) \n";
		cout << "'5' - ���������� ������� \n";
		cout << "'6' - ���������� ���������� \n";
		cout << "'7' - ���������� ������� \n";
		cout << "'8' - ������� \n";
		cout << "'9 - ���������� ������� \n";
		cout << "'0 - ������������ ������ \n";

		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '1':
			PrintHelloWorld();
			system("pause");
			break;
		case'2':
		{
			int value1, value2;
			char operationKey;
			cout << "������� ������ ��������: ";
			value1 = CinDigit();
			cout << "\n ������� ������ ��������: ";
			value2 = CinDigit();

			cout << ("\n ������� �������������� ��������� (+, -, *, /, %): ");
			operationKey = _getch();
			while ((operationKey != '+') && (operationKey != '-') && (operationKey != '*') && (operationKey != '/') && (operationKey != '%'))
			{
				//���� ��������� ������ ��� �� ����������, �� �����  
				//������� ��������� �� ����� � ��������� ��������� ����.  
				cout << "\n������������ ����!!!\n ������� (+, -, *, /, %):";
				operationKey = _getch();
				fflush(stdin);   //������� ������� ������������ ������ �����      
								 //�� ������ ����� ���������� �������� ������ ������ 
			}
			cout << MakeCalculation(value1, value2, operationKey) << endl;

			system("pause");
			break;
		}
		case '3':
		{
			int a, b, c, roots;
			double x1, x2;
			double* x1Pointer = &x1;
			double* x2Pointer = &x2;
			cout << "������� ����������� a: ";
			a = CinDigit();
			cout << "������� ����������� b: ";
			b = CinDigit();
			cout << "������� ����������� c: ";
			c = CinDigit();

			roots = PointerGetRoots(a, b, c, x1Pointer, x2Pointer);
			if (roots == 1)
			{
				cout << roots << " ������� \n";
			}
			if (roots == 0)
			{
				cout << "��� ������� \n";
			}

			system("pause");
			break;
		}
		case '4':
		{
			int a, b, c, roots;
			double x1, x2;
			double& x1Reference = x1;
			double& x2Reference = x2;
			cout << "������� ����������� a: ";
			a = CinDigit();
			cout << "������� ����������� b: ";
			b = CinDigit();
			cout << "������� ����������� c: ";
			c = CinDigit();

			roots = ReferenceGetRoots(a, b, c, x1Reference, x2Reference);
			if (roots == 1)
			{
				cout << roots << " ������� \n";
			}
			if (roots == 0)
			{
				cout << "��� ������� \n";
			}

			system("pause");
			break;
			}
		case '5':
		{
			int a = 1;  
			int b = 2;

			SummNumbers(a, b);

			double x = 3.0;  
			double y = 4.0;  

			SummNumbers(x, y); 

			SummNumbers(a, y);  

			float m = 5.0; 
			float n = 6.0;  

			SummNumbers(m, n);

			system("pause");
			break;
		}

		case '6':
		{
			cout << "�������� ���������� ���������: " << globalVariable << endl;  
			GlobalPlusTwo();  
			cout << "�������� ���������� ���������: " << globalVariable << endl;
			GlobalMultiplyThree();  
			cout << "�������� ���������� ���������: " << globalVariable << endl;
			GlobalEqualsOne();  
			cout << "�������� ���������� ���������: " << globalVariable << endl;
			globalVariable = 5;  
			cout << "�������� ���������� ���������: " << globalVariable << endl;

			system("pause");
			break;
		}

		case '7':
		{
			int base, power;
			cout << "������� ���������: ";
			base = CinDigit();
			cout << "������� �������: ";
			power = CinDigit();
			cout << "����� " << base << " � ������� " << power << " = " << GetPower(base, power) << endl;

			system("pause");
			break;
		}

		case '8':
		{
			PlayGame();
			system("pause");
			break;
		}
		case '9':
		{

			const int n = 5;  
			double Array[n];  
			for (int i = 0; i < n; i++) 
			{ 
				Array[i] = rand()%100; 
				cout << Array[i] << " ";
			}
			
			BubbleSortArray1(Array);
			cout << "\n (����� 1)��������������� ������: \n";

			//BubbleSortArray2(Array,n);
			//cout << "\n (����� 2)��������������� ������: \n";

			//BubbleSortArray3(Array,n);
			//cout << "\n (����� 3)��������������� ������: \n";

			for (int i = 0; i < n; i++)
			{
				cout << Array[i] << " ";
			}
			system("pause");
			break;
		}
		case '0':
		{

			cout << "\n������� ������ ������� �: ";
			int rowsA = CinDigit();
			cout << "\n������� ������� ������� A: ";
			int columnsA = CinDigit();
			cout << "\n������� ������ ������� B: ";
			int rowsB = CinDigit();
			cout << "\n������� ������� ������� B: ";
			int columnsB = CinDigit();

			if (columnsA == rowsB)
			{
				int rowsResult = rowsA;
				int columnsResult = columnsB;

				int** matrixA = new int*[rowsA];
				for (int i = 0; i < rowsA; i++)
					matrixA[i] = new int[columnsA];

				int** matrixB = new int*[rowsB];
				for (int i = 0; i < rowsB; i++)
					matrixB[i] = new int[columnsB];

				int** matrixResult = new int*[rowsResult];
				for (int i = 0; i < rowsResult; i++)
					matrixResult[i] = new int[columnsResult];

				for (int i = 0; i < rowsA; i++)
					for (int j = 0; j < columnsA; j++)
						matrixA[i][j] = rand() % 100;

				for (int i = 0; i < rowsB; i++)
					for (int j = 0; j < columnsB; j++)
						matrixB[i][j] = rand() % 100;

				MultiplyMatrices(matrixA, rowsA, columnsA, matrixB, rowsB, columnsB, matrixResult);

				cout << "������� A:" << endl;
				for (int i = 0; i < rowsA; i++)
				{
					for (int j = 0; j < columnsA; j++)
					{
						cout.width(8);
						cout << matrixA[i][j];
					}
					cout << endl;
				}
				cout << "������� B:" << endl;
				for (int i = 0; i < rowsB; i++)
				{
					for (int j = 0; j < columnsB; j++)
					{
						cout.width(8);
						cout << matrixB[i][j];
					}
					cout << endl;
				}
				cout << "�������������� �������:" << endl;
				for (int i = 0; i < rowsResult; i++)
				{
					for (int j = 0; j < columnsResult; j++)
					{
						cout.width(8);
						cout << matrixResult[i][j];
					}
					cout << endl;
				};

				for (int i = 0; i < rowsA; i++)
					delete[] matrixA[i];
				for (int i = 0; i < rowsB; i++)
					delete[] matrixB[i];
				for (int i = 0; i < rowsResult; i++)
					delete[] matrixResult[i];
				delete[] matrixA, matrixB, matrixResult;

				
			}
			else
				cout << "������� �� ����������!" << endl;
			system("pause");
			break;
			
		}
		}
	}
}

