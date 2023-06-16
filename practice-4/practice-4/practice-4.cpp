/* ������� ���� ������ ���� ���������� ��� �������� :
<�������>, <����� �����>, <������ 1>, <������ 2>, <������ 3>;
��� ����� ������� �� �� ����� 12 �������, ����� ����� � ���� ��
211 �� 216, ����� ������ � �� 2, 3, 4 ��� 5. ����� ������ � �� ������� ��
���������, ����� � �� ������, � ����� � �� �������������.��� ���
�������� �������������� ������ ";".

��������� �������� ��������, ��� �������� �� ������� �� � ���� ����
����������:
4. ������� ��������, ����� ������� ��������, �� ����� �� ��������
�� 5 �� 4; 
*/

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <sstream>
#include <string>

using namespace std;

const int NUM_SURNAMES = 50;

const char* surnames[NUM_SURNAMES] = {
    "��������", "��������", "���������", "���������", "���������",
    "����������", "��������", "���������", "��������", "�������",
    "���������", "��������", "��������", "���������", "�������",
    "������", "��������", "���������", "�������", "��������",
    "������", "���������", "���������", "��������", "���������",
    "���������", "�������", "��������", "�����", "��������",
    "���������", "���������", "���������", "�����������", "���������",
    "����������", "�������", "ǳ������", "�������", "��������",
    "�������", "���������", "�������", "����������", "�����",
    "����������", "�������", "�������", "�����", "ѳ��������"
};


float calculatePercentage(int value, int totalValue)
{
    return (static_cast<float>(value) / totalValue) * 100;
}

// Creates text file and fills it with students data.
void generateInputFile(const char* fileName)
{
    ofstream file(fileName);
    srand(time(NULL));

    if (file) {
        for (int i = 0; i < NUM_SURNAMES; i++) {
            int index = rand() % NUM_SURNAMES;  // ���������� ������ ������
            int groupNumber = rand() % 6 + 211;
            int grades[3]{};

            for (int i = 0; i < 3; i++) {
                grades[i] = rand() % 4 + 2;
            }

            cout << surnames[index] << ',' << groupNumber << ',' << grades[0]
                << ',' << grades[1] << ',' << grades[2] << ';' << endl;

            file << surnames[index] << ',' << groupNumber << ',' << grades[0]
                << ',' << grades[1] << ',' << grades[2] << ";\n";
        }
    }
    else {
        cout << "Error opening the file " << fileName;
    }
    
    file.close();
}

void outputEducationQuality(const char* inFilename, const char* outFilename = "output.txt")
{
    ofstream file(outFilename);
    ifstream inFile(inFilename);
    string line;
    int counter{};
    char delimiter = ',';

    if (file) {
        cout << "\n<-------³�������-------> \n";

        while (getline(inFile, line)) {
            string surname;
            int groupNumber, grade1, grade2, grade3;

            istringstream inputStream(line);

            getline(inputStream, surname, delimiter);

            inputStream >> groupNumber
                >> delimiter >> grade1
                >> delimiter >> grade2
                >> delimiter >> grade3;

            if (grade1 > 3 && grade2 > 3 && grade3 > 3) {
                // ��������� �������� ������� �� �����
                cout << "�������: " << surname << endl;
                cout << "����� �����: " << groupNumber << endl;
                cout << "������: " << grade1 << ", " << grade2 << ", " << grade3 << endl;
                cout << endl;
                file << surname
                    << delimiter << groupNumber
                    << delimiter << grade1
                    << delimiter << grade2
                    << delimiter << grade3 << ";\n";

                counter++;
            }
        }
        if (counter < 1) {
            cout << "³������� ���� :(\n";
        }

        int percentage = calculatePercentage(counter, NUM_SURNAMES);
        cout << "����� ��������: " << percentage << "%\n";
        file << "����� ��������: " << percentage << "%\n";
    }
    else {
        cout << "Error while opening file" << outFilename;
    }

    file.close();
    inFile.close();
}

int main()
{
    SetConsoleOutputCP(1251); // ��������� ��� ������ ����������
    const char* inFile = "inputFile.txt";

    generateInputFile(inFile);
    outputEducationQuality(inFile);
}
