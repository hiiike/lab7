#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** P, const int rowCount, const int colCount, int High, int Low) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            P[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** P, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << P[i][j];
        }
        cout << endl;
    }
}

int rowMin(int** P, const int colCount, const int i, int rowMinEl)
{
    for (int j = 0; j < colCount; j++) {
        if (rowMinEl > P[i][j]) {
            rowMinEl = P[i][j];
        }
    }
    return rowMinEl;
}

void arrSearch(int** P, const int rowCount, const int colCount, int& minEl) {
    for (int i = 0; i < rowCount; i++) {
        int rowMinEl = rowMin(P, colCount, i, P[i][0]);
        if (rowMinEl > minEl) {
            minEl = rowMinEl;
        }
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

    int** P = new int* [colCount];
    for (int j = 0; j < colCount; j++)
        P[j] = new int[rowCount];

    Create(P, rowCount, colCount, High, Low);
    Print(P, rowCount, colCount);

    int minEl = rowMin(P, colCount, 0, P[0][0]);
    arrSearch(P, rowCount, colCount, minEl);
    cout << "max = " << minEl << endl;


    system("pause");
    cin.get();
    return 0;
}
