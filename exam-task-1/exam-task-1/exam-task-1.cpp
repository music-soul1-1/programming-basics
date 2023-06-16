/* ����� �4 �������� �2
�������� ������� 6x6 ��������� ����������� ������ ������� [-15...15]. 
³���������� ������� �������� ������� �� ���������� �� ��������. 
������ ����������� ����� �� ���� ������� ����� ��������, 
�� ���������� ����� ������ �������. 
������� �� ������� ��������� �� ����������� �������, �������� �����. 
����������� �������.
*/

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

const int SIZE = 7;

struct maxNum
{
    int value, 
        rowIndex, 
        columnIndex;
};

void printMatrix(int** matrix)
{
    // index reference:
    cout << setw(3) << " ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(3) << i << " ";
    }
    cout << "\n\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << i << "  "; // index reference

        for (int j = 0; j < SIZE; j++)
        {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void fillMatrix(int** matrix)
{
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = rand() % 31 - 15; // random between -15 and 15
        }
    }
}

void sortMainDiagonal(int** matrix)
{
    // ���������� ������� ������� �� ����������
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (matrix[i][i] < matrix[j][j])
            {
                swap(matrix[i][i], matrix[j][j]);
            }
        }
    }
}

maxNum findMaxNumber(int** matrix)
{
    int maxValue = -16, rowIndex{}, colIndex{};
    for (int i = SIZE - 1; i > 0; i--)
    {
        for (int j = SIZE - i; j < SIZE; j++)
        {
            if (matrix[i][j] > maxValue)
            {
                maxValue = matrix[i][j];
                rowIndex = i;
                colIndex = j;
            }
        }
    }

    return { maxValue, rowIndex, colIndex };
}

int main()
{
    int** matrix = new int* [SIZE]; // creating rows

    for (int i = 0; i < SIZE; i++)
    {
        matrix[i] = new int[SIZE]; // creating columns
    }
    fillMatrix(matrix);
    printMatrix(matrix);

    cout << "\nMatrix after sorting:\n";

    sortMainDiagonal(matrix);
    printMatrix(matrix);

    maxNum maxValue = findMaxNumber(matrix);
    cout << "\nMaximum number:\n" 
         << maxValue.value << "[" << maxValue.rowIndex << "]"
         << "[" << maxValue.columnIndex << "]\n";

    for (int i = 0; i < SIZE; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
