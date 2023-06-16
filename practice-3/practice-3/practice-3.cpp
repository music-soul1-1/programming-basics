/* 
4. Для двох файлів А та В, які включають по 17 елементів:
A = { a_i }, i = 1, 17 (в періоді), B = { b_i }, необхідно виконати наступні дії
c_i = ((a_i - b_i) / a_i)
та отримані значення c_i записати до файлу c = { c_i }.
*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;

// Converts array of characters to number.
unsigned int convertString(const char* line)
{
    unsigned int result = 0;
    for (int i = 0; i < strlen(line); i++)
    {
        result += static_cast<int>(line[i]);
    }
    return result;
}

#pragma region Text files

// Creates text file and fills it with given number of random numbers.
void createFile(const char* fileName, int numberOfElements = 17) 
{
    // Generate a seed based on the file name and time
    srand(convertString(fileName) * time(NULL));
    ofstream file(fileName);

    if (!file.is_open()) {
        cout << "Error while opening file" << fileName;
    }

    for (int i = 0; i < numberOfElements; i++) {
        file << rand() % 2001 - 1000 << " ";
    }

    file.close();
}

// Calculates desired values and writes them to fileC.
// Output file (fileC) is created automatically.
void calculate(const char* fileA, const char* fileB, const char* fileC, int size) 
{
    double a, b, c;
    ifstream myfileA(fileA);
    ifstream myfileB(fileB);
    ofstream myfileC(fileC);

    if (!myfileA || !myfileB || !myfileC) {
        cout << "Failed to open files." << endl;
    }

    // Read values from files A and B, calculate 'c' and write it to fileC:
    for (int i = 0; i < size; i++) {
        myfileA >> a;
        myfileB >> b;

        c = static_cast<double>((a - b) / a);

        myfileC << c << " ";
    }

    myfileA.close();
    myfileB.close();
    myfileC.close();
}

// Prints file's content.
// Second papameter is needed to determine what type of values are written in the file.
void printFile(const char* filename, bool isInt = true)
{
    ifstream file(filename);
    cout << '\n' << filename << ": \n\n";

    if (!file) {
        cout << "Error while opening " << filename;
    }

    if (isInt) {
        int value;

        while (file >> value) {
            cout << setw(6) << value;
        }
    }
    else {
        double value;

        while (file >> value) {
            cout << setw(10) << value;
        }
    }
    cout << '\n';

    file.close();
}

#pragma endregion

#pragma region Binary

// Creates binary file and fills it with given number of random numbers.
void createBinaryFile(const char* fileName, int numberOfElements = 17)
{
    int value;
    ofstream file(fileName, ios::binary);
    // Generate a seed based on the file name and time
    srand(convertString(fileName) * time(NULL));

    if (!file.is_open()) {
        cout << "Error while opening file" << fileName;
    }

    for (int i = 0; i < numberOfElements; i++) {
        value = rand() % 2001 - 1000;
        file.write(reinterpret_cast<const char*>(&value), sizeof(value));
    }

    file.close();
}

// Calculates desired values and writes them to binary fileC.
// Output file (fileC) is created automatically.
void calculateBinary(const char* fileA, const char* fileB, const char* fileC, int size)
{
    int a{}, b{};
    double c{};
    ifstream myfileA(fileA, ios::binary);
    ifstream myfileB(fileB, ios::binary);
    ofstream myfileC(fileC, ios::binary);

    if (!myfileA || !myfileB || !myfileC) {
        cout << "Failed to open files." << endl;
    }

    for (int i = 0; i < size; i++) {
        // Read values from files A and B
        myfileA.read(reinterpret_cast<char*>(&a), sizeof(a));
        myfileB.read(reinterpret_cast<char*>(&b), sizeof(b));

        c = static_cast<double>((a - b)) / a; // calculate the value

        // writing value to file C
        myfileC.write(reinterpret_cast<const char*>(&c), sizeof(c));
    }

    myfileA.close();
    myfileB.close();
    myfileC.close();
}

// Prints binary file's content.
// Second papameter is needed to determine what type of values are written in the file.
void printBinaryFile(const char* filename, bool isInt = true) 
{
    ifstream fileBin(filename, ios::binary);

    cout << '\n' << filename << ": \n\n";

    if (!fileBin) {
        cout << "Error opening " << filename << '\n';
    }

    if (isInt) {
        int value{};

        while (fileBin.read(reinterpret_cast<char*>(&value), sizeof(value))) {
            cout << setw(6) << value;
        }
    }
    else {
        double value{};

        while (fileBin.read(reinterpret_cast<char*>(&value), sizeof(value))) {
            cout << setw(10) << value;
        }
    }
    cout << '\n';

    fileBin.close();
}

#pragma endregion

int main()
{
    const int numberOfElements = 17;

    createFile("A.txt", numberOfElements);
    createFile("B.txt", numberOfElements);

    createBinaryFile("A.bin", numberOfElements);
    createBinaryFile("B.bin", numberOfElements);

    calculate("A.txt", "B.txt", "C.txt", numberOfElements);
    calculateBinary("A.bin", "B.bin", "C.bin", numberOfElements);

    cout << "#####Text files:";
    printFile("A.txt");
    printFile("B.txt");
    printFile("C.txt", false);

    cout << "\n#####Binary files:";
    printBinaryFile("A.bin");
    printBinaryFile("B.bin");
    printBinaryFile("C.bin", false);
}
