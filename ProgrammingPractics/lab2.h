#pragma once

int CinDigit();
void PrintHelloWorld();
double MakeCalculation(int value1, int value2, char key);
int PointerGetRoots(int a, int b, int c, double* x1, double* x2);
int ReferenceGetRoots(int a, int b, int c, double& x1, double& x2);

void SummNumbers(int value1, int value2);
void SummNumbers(double value1, double value2);
void SummNumbers(int value1, double value2);
void PlayGame();

void BubbleSortArray1(double doubleArray[5]);
void BubbleSortArray2(double doubleArray[], int arraySize);
void BubbleSortArray3(double* arrayPointer, int arraySize);

void MultiplyMatrices();

int GetPower(int base, int power);

void LaunchLab2();
