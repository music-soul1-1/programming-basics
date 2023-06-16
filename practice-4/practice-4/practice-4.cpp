/* Вхідний файл зберігає таку інформацію про студентів :
<прізвище>, <номер групи>, <оцінка 1>, <оцінка 2>, <оцінка 3>;
При цьому прізвище має не більше 12 символів, номер групи – ціле від
211 до 216, кожна оцінка – це 2, 3, 4 або 5. Перша оцінка – за екзамен по
матаналізу, друга – по фізиці, а третя – по програмуванню.Дані про
студентів відокремлюються знаком ";".

Необхідно написати програму, яка виводить на консоль та у файл таку
інформацію:
4. «Якість» навчання, тобто процент студентів, які здали всі екзамени
на 5 та 4; 
*/

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <sstream>
#include <string>

using namespace std;

const int NUM_SURNAMES = 50;

const char* surnames[NUM_SURNAMES] = {
    "Іваненко", "Петренко", "Сидоренко", "Коваленко", "Морозенко",
    "Бондаренко", "Грищенко", "Дмитренко", "Павленко", "Мельник",
    "Ковальчук", "Шевченко", "Ткаченко", "Біленький", "Романов",
    "Олійник", "Савченко", "Кравченко", "Лисенко", "Марченко",
    "Поліщук", "Федоренко", "Соколенко", "Левченко", "Рибаченко",
    "Кучеренко", "Мосійчук", "Колесник", "Калінін", "Богданов",
    "Макаренко", "Кузьменко", "Василенко", "Кондратенко", "Захаренко",
    "Михайленко", "Осадчук", "Зінченко", "Кравець", "Бєлєнький",
    "Руденко", "Терещенко", "Лихачов", "Гончаренко", "Кушнір",
    "Броваренко", "Купрієнко", "Косенко", "Марків", "Сідлецький"
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
            int index = rand() % NUM_SURNAMES;  // Випадковий індекс масиву
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
        cout << "\n<-------Відмінники-------> \n";

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
                // Виведення зчитаних значень на екран
                cout << "Прізвише: " << surname << endl;
                cout << "Номер групи: " << groupNumber << endl;
                cout << "Оцінки: " << grade1 << ", " << grade2 << ", " << grade3 << endl;
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
            cout << "Відмінників немає :(\n";
        }

        int percentage = calculatePercentage(counter, NUM_SURNAMES);
        cout << "Якість навчання: " << percentage << "%\n";
        file << "Якість навчання: " << percentage << "%\n";
    }
    else {
        cout << "Error while opening file" << outFilename;
    }

    file.close();
    inFile.close();
}

int main()
{
    SetConsoleOutputCP(1251); // необхідно для виводу українською
    const char* inFile = "inputFile.txt";

    generateInputFile(inFile);
    outputEducationQuality(inFile);
}
