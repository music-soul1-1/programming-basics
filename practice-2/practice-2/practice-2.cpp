// Практична №2
// Варіант 4
// 4. У двовимірному масиві (N+5)x(N+5), відсортувати парні рядки за
// збільшенням, числа генерувати випадково в інтервалі[-100; 100].

#include <iostream>
#include <iomanip>

using namespace std;

// Creates new 2D array of size [size][size] and returns it.
int** createArray(int size)
{
    int** array = new int* [size];

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = new int[size];

        for (int j = 0; j < size; j++) {
            array[i][j] = rand() % 201 - 100; // Random number in the range [-100, 100]
        }
    }

    return array;
}

// Deletes the passed array from memory.
void deleteArray(int** array, int size)
{
    for (int i = 0; i < size; i++) {
        delete[] array[i];
    }
    delete[] array;
}

// Prints the array.
// If array length >= 18, printing the array in a more compact way.
void printArray(int** array, int size)
{
    if (size < 18) // if array length < 18, printing the array in a wider way.
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << " |" << setw(5) << array[i][j];  // Access and use array elements
            }
            cout << " |" << endl;
        }
    }
    else // if array length >= 18, printing the array in a more compact way.
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << setw(4) << array[i][j];  // Access and use array elements
            }
            cout << endl;
        }
    }
}

#pragma region Sorting functions

// Partitions a given row of the 2D array based on a pivot element.
// Elements smaller than the pivot are moved to the left, and elements larger than the pivot are moved to the right.
// Parameters:
//   - array: The 2D array to be partitioned.
//   - low: The starting index of the partitioning range.
//   - high: The ending index of the partitioning range.
//   - indexOfRow: The index of the row to be partitioned.
// Returns:
//   - The index of the pivot element after partitioning.
int partition(int** array, int low, int high, int indexOfRow) 
{
    int pivot = array[indexOfRow][high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (array[indexOfRow][j] < pivot) {
            i++;
            swap(array[indexOfRow][i], array[indexOfRow][j]);
        }
    }
    swap(array[indexOfRow][i + 1], array[indexOfRow][high]);

    return i + 1;
}

// Sorts a given row of the 2D array using the QuickSort algorithm.
// Parameters:
//   - array: The 2D array to be sorted.
//   - low: The starting index of the row to be sorted.
//   - high: The ending index of the row to be sorted.
//   - indexOfRow: The index of the row to be sorted.
void quickSort(int** array, int low, int high, int indexOfRow) 
{
    if (low < high) {
        int partitionIndex = partition(array, low, high, indexOfRow);

        quickSort(array, low, partitionIndex - 1, indexOfRow);
        quickSort(array, partitionIndex + 1, high, indexOfRow);
    }
}

// Main sorting function.
// It calls quickSort for every even row.
void sortEvenRows(int** array, int size) 
{
    for (int i = 1; i <= size; i++) 
    {
        if (i % 2 == 0) // if is even
        { 
            quickSort(array, 0, size - 1, i-1); // 'i' is the index of a row
        }
    }
}

#pragma endregion

int main()
{
    int arraySize;

    // while the user input is less than 0, ask them to enter the size again
    do {
        cout << "Enter the size of the array (must be >= 0):\nsize: ";
        cin >> arraySize;
    } while (arraySize < 0);

    // Incrementing arraySize by 5
    arraySize += 5;

    // Creating new array
    int** array = createArray(arraySize);

    // Printing and deleting the array:
    cout << "Before sort:\n";
    printArray(array, arraySize);

    cout << "After sort:\n";
    sortEvenRows(array, arraySize);
    printArray(array, arraySize);

    deleteArray(array, arraySize);
}
