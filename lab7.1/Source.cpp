#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Change(int** R, const int row1, const int row2, const int colCount);

void Create(int** R, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			R[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** R, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << R[i][j];
		cout << endl;
	}
	cout << endl;
}

void Sort(int** R, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((R[i1][0] > R[i1 + 1][0])
				||
				(R[i1][0] == R[i1 + 1][0] &&
					R[i1][1] < R[i1 + 1][1])
				||
				(R[i1][0] == R[i1 + 1][0] &&
					R[i1][1] == R[i1 + 1][1] &&
					R[i1][2] < R[i1 + 1][2]))
				Change(R, i1, i1 + 1, colCount);
}
void Change(int** R, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = R[row1][j];
		R[row1][j] = R[row2][j];
		R[row2][j] = tmp;
	}
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (a[i][j] % 2 == 0 || (i % 3 != 0 && j % 3 != 0))
			{
				S += a[i][j];
				k++;
				a[i][j] = 0;
			}
}

int main()
{
	srand((unsigned)time(NULL));
	int Low = 4;
	int High = 51;

	int rowCount = 8;
	int colCount = 5;

	int** R = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		R[i] = new int[colCount];

	cout << "Generated matrix: " << endl;
	Create(R, rowCount, colCount, Low, High);
	Print(R, rowCount, colCount);
	cout << "Sorted matrix: " << endl;
	Sort(R, rowCount, colCount);
	Print(R, rowCount, colCount);

	int S = 0;
	int k = 0;
	Calc(R, rowCount, colCount, S, k);
	cout << "Sum of values = " << S << endl;
	cout << "Number of values = " << k << endl;
	Print(R, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)

		delete[] R[i];
	delete[] R;
	return 0;
}
