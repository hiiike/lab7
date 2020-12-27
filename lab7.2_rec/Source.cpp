#include <iostream>
#include <iomanip>
#include <time.h>


using namespace std;

void CreateRow(int** P, const int colCount, int High, int Low, int rowNo, int colNo)
{
    P[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < colCount - 1)
    {
        CreateRow(P, colCount, High, Low, rowNo, colNo + 1);
    }
}


void Create(int** P, const int rowCount, const int colCount, int High, int Low, int rowNo)
{
    CreateRow(P, colCount, High, Low, rowNo, 0);
    if (rowNo < rowCount - 1)
    {
        Create(P, rowCount, colCount, High, Low, rowNo + 1);
    }
}




void PrintRow(int** P, const int colCount, int rowNo, int colNo)
{
    cout << setw(4) << P[rowNo][colNo];
    if (colNo < colCount - 1)
    {
        PrintRow(P, colCount, rowNo, colNo + 1);
    }
    else
    {
        cout << endl;
    }
}

void Print(int** P, const int rowCount, const int colCount, int rowNo)
{
    PrintRow(P, colCount, rowNo, 0);
    if (rowNo < rowCount - 1)
    {
        Print(P, rowCount, colCount, rowNo + 1);
    }
    else
    {
        cout << endl;
    }
}



int rowMin(int** P, const int colCount, const int i, int rowMinEl, int j)
{
    if (P[i][j] < rowMinEl)
    {
        rowMinEl = P[i][j];
    }
    if (j > colCount - 1)
    {
        rowMin(P, colCount, i + 1, rowMinEl, j);
    }
    else
    {
        return rowMinEl;
    }
}

int arrSearchRow(int** P, const int rowCount, const int colCount, int minEl, int i)
{
    int rowMinEl = rowMin(P, colCount, i, P[i][0], 0);
    if (rowMinEl < minEl)
    {
        minEl = rowMinEl;
    }
    if (i < rowCount - 2)
    {
        arrSearchRow(P, rowCount, colCount, minEl, i + 1);
    }
    else
    {
        return minEl;
    }
}


int main()
{
    int Low = 10;
    int High = 90;

    int rowCount;
    int colCount;

    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** P = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        P[i] = new int[colCount];

    Create(P, rowCount, colCount, High, Low, 0);
    Print(P, rowCount, colCount, 0);

    int minEl = rowMin(P, colCount, 0, P[0][0], 0);

    cout << arrSearchRow(P, rowCount, colCount, minEl, 0) << endl;

    system("pause");
    cin.get();
    return 0;
}
