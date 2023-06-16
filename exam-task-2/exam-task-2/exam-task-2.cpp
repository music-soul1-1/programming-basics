/* ����� �4 �������� �3
3. ��������� ��������� ����, �� ������ ��� �����: 
�����_�����:�������_���������(������_������)�������_����������;�������� 
������� �� ����� �� ������� � ����� ���� ������� ��������� �� ����� �����, 
���� � ���� ����� � ����� ���λ, 
� �������� ���������� ����� 1000 �� ����� 8700.
*/

#define _CRT_SECURE_NO_WARNINGS // ������ ������� ��� strtok

#include <iostream>
#include <ctime>
#include <Windows.h>
#include <cstring>
#include <fstream>

using namespace std;

const int ARR_SIZE = 40;

const char* companies[ARR_SIZE] =
{
    "�������", "����������", "��������", "��������",
    "���������", "����������", "�����ò��", "���������",
    "������������", "������", "��������", "�����������",
    "���������", "���������", "�������", "Գ��������",
    "̳������", "����������", "���������", "������",
    "����������", "�������", "��������", "���������",
    "���������", "������������", "���������", "����������",
    "������", "�������������", "������������", "������",
    "�����̳�", "���������", "������", "����������",
    "���������", "�������", "�����������", "�������"
};

const char* surnames[ARR_SIZE] = {
    "��������", "��������", "���������", "���������", "���������",
    "����������", "��������", "���������", "��������", "�������",
    "���������", "��������", "��������", "���������", "�������",
    "������", "��������", "���������", "�������", "��������",
    "������", "���������", "���������", "��������", "���������",
    "���������", "�������", "��������", "�����", "��������",
    "���������", "���������", "���������", "�����������", "���������",
    "����������", "�������", "ǳ������", "�������", "��������",
};

struct Data
{
    char* company,
        * director,
        * accountant;
    int salary;
};

void generateInputFile()
{
    ofstream file("input.txt");

    if (file)
    {
        for (int i = 0; i < ARR_SIZE; i++)
        {
            srand((i + 1) * time(NULL));
            file << companies[rand() % ARR_SIZE] << ":" << surnames[rand() % ARR_SIZE]
                << " " << surnames[rand() % ARR_SIZE] << ";" << rand() % 9001 + 800 << "\n";
        }
    }
    else 
    {
        cout << "Error opening file";
    }
    file.close();
};

void findRequiredData(const char* filename, const char* outputFilename)
{
    ifstream inFile(filename);
    ofstream outFile(outputFilename);

    const int lineLength = 100;

    if (inFile)
    {
        char line[lineLength];
        Data data{};

        while (inFile.getline(line, lineLength))
        {
            //cout << line << endl;

            data.company = strtok(line, ":");
            data.director = strtok(nullptr, " ");
            data.accountant = strtok(nullptr, ";");
            char* salaryString = strtok(nullptr, " ");
            data.salary = atoi(salaryString);

            if (strstr(data.company, "���") && data.salary > 1000 && data.salary < 8700)
            {
                cout << data.director << " | " << data.company << endl;

                if (outFile)
                {
                    outFile << data.director << "," << data.company << ";\n";
                }
            }
        }
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    generateInputFile();
    findRequiredData("input.txt", "output.txt");

    int x = 10, y = 5;
    bool isCute = false;

    if (x != y && isCute || y == 5)
    {
        cout << "ABOAB";
    }

};
