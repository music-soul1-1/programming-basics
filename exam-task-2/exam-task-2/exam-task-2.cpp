/* Білет №4 завдання №3
3. Прочитати текстовий файл, що зберігає такі рядки: 
Назва_фірми:Прізвище_директора(символ_пробілу)Прізвище_бухгалтера;зарплата 
Вивести на екран та зписати у новий файл прізвище директора та назву фірми, 
якщо в назві фірми є фраза «ЗАО», 
а зарплата бухгалтера більше 1000 та менше 8700.
*/

#define _CRT_SECURE_NO_WARNINGS // вимикає помилку про strtok

#include <iostream>
#include <ctime>
#include <Windows.h>
#include <cstring>
#include <fstream>

using namespace std;

const int ARR_SIZE = 40;

const char* companies[ARR_SIZE] =
{
    "ЗАОЛЕНД", "УкрПродукт", "ЕкоФерма", "МегаКомп",
    "АвтоСервіс", "ФудМайстер", "ЗАОЛОГІСТ", "ЕнергоКом",
    "ГлобальТрейд", "ЕлітБуд", "ЗАОСтрой", "ЕкспертГруп",
    "АртДизайн", "МодаСтиль", "ЗАОФарм", "ФінансГруп",
    "МікроТех", "Професіонал", "ІнтерАгро", "ЗАОБуд",
    "КосмоСтудія", "Автохім", "ЕкоСервіс", "ЗАОЕнергія",
    "Універсаль", "ЕкспресТранс", "ТехноГруп", "АктивПласт",
    "ЗАОМаш", "ЕлектроТехніка", "МеталПрофіль", "БіоКом",
    "ЗемлеМір", "ЕнергоПро", "АртСвіт", "ТехноСервіс",
    "ГеоМаркет", "ЗАОАгро", "УніверсалБуд", "ЕкоЛайф"
};

const char* surnames[ARR_SIZE] = {
    "Іваненко", "Петренко", "Сидоренко", "Коваленко", "Морозенко",
    "Бондаренко", "Грищенко", "Дмитренко", "Павленко", "Мельник",
    "Ковальчук", "Шевченко", "Ткаченко", "Біленький", "Романов",
    "Олійник", "Савченко", "Кравченко", "Лисенко", "Марченко",
    "Поліщук", "Федоренко", "Соколенко", "Левченко", "Рибаченко",
    "Кучеренко", "Мосійчук", "Колесник", "Калінін", "Богданов",
    "Макаренко", "Кузьменко", "Василенко", "Кондратенко", "Захаренко",
    "Михайленко", "Осадчук", "Зінченко", "Кравець", "Бєлєнький",
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

            if (strstr(data.company, "ЗАО") && data.salary > 1000 && data.salary < 8700)
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
