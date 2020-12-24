// Lab_06_1.cpp 
// < Базарник Максим > 
// Лабораторна робота № 6.1 
// Варіант 1
#include <iostream>
#include <time.h>

using namespace std;

void CreateArray(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		CreateArray(a, size, Low, High, i + 1);
}

void PrintArray(int* a, const int size, int i)
{
	if (i == 0)
		cout << "a[n=" << size << "] = {";
	if (i > 0)
		cout << ", ";
	cout << a[i];
	if (i == (size - 1))
		cout << "}" << endl;

	if (i < size - 1)
		PrintArray(a, size, i + 1);
}

int GetSum(int* a, const int i) 
{
	int s = 0;

	if ((a[i] > 0) && !(i % 5 == 0)) {
		s = a[i];
	}

	if (i > 0) {
		s += GetSum(a, i - 1);
	}

	return s;
}

int GetAmount(int* a, const int i) 
{
	int am = 0;

	if ((a[i] > 0) && !(i % 5 == 0)) {
		am++;
	}

	if (i > 0) {
		am += GetAmount(a, i - 1);
	}

	return am;
}

void Set0(int* a, const int size, int i)
{
	if (i < size) {
		if ((a[i] > 0) && !(i % 5 == 0)) {
			a[i] = 0;
		}
		Set0(a, size, i + 1);
	}
}

int main()
{
	srand((unsigned)time(NULL)); 

	const int k = 20; 

	int a[k]; 

	int Low = -21;
	int High = 49;
	cout << "Massive :" << endl;
	CreateArray(a, k, Low, High, 0);

	PrintArray(a, k, 0);
	cout << endl;

	cout << "Sum = " << GetSum(a, k - 1) << endl;
	cout << "Amount = " << GetAmount(a, k - 1) << endl;
	cout << endl;
	cout << "Replacing :" << endl;
	Set0(a, k, 0);

	PrintArray(a, k, 0);
	cout << endl;

	return 0;
}
