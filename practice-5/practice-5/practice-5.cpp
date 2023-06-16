/* Для структури даних, яка наведена на рисунку, необхідно створити масив записів та визначити:
4) всіх постачальників, держава яких – «Україна», рік постачання – 2013, вартість товару більше 2000;
*/

#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

const int COUNTRIES_SIZE = 5;
const int SUPPLIERS_SIZE = 15;
const int GOODS_SIZE = 40;

const char* countries[COUNTRIES_SIZE] = { "Ukraine", "Great Britain", "USA", "Germany", "Japan" };
const char* suppliers[SUPPLIERS_SIZE] = 
{
    "УкрПродукт",
    "Агро-Україна", 
    "УкрАгроСервіс",
    "Агроекспорт",
    "УкрЗерно",
    "ЕкоФерма",
    "Український Загін", 
    "EcoFarms",
    "AgroTech",
    "FarmersUnited",
    "HarvestFields",
    "GreenGlobe",
    "Nature's Best",
    "AgriPro",
    "AgroLink"
};

const char* goodsNames[GOODS_SIZE] = {
    "Молоко", "Хліб", "Яйця", "Мед",
    "Сир", "М'ясо", "Ковбаса", "Риба",
    "Овочі", "Фрукти", "Сік", "Масло",
    "Цукор", "Макарони", "Крупа", "Горох",
    "Рис", "Сіль", "Сода", "Кава",
    "Чай", "Какао", "Солодощі", "Печиво", 
    "Шоколад", "Морозиво", "Халва", "Консерви",
    "Соус", "Олія", "Гриби", "Супи",
    "Сироп", "Соки", "Маринади", "Снеки",
    "Чіпси", "Мука", "Повидло", "Желе"
};

// The structure's members are in the same order as in the task
struct Goods 
{
    string 
        supplier{},
        name{};
    float price{};
    int numberOfUnits{};
    struct 
    {
        int day{},
            month{},
            year{};
    } dateOfSupply{};
    const char* country{};
};

// Takes an array of goods and randomly fills all the parameters
void generateSuppliers(Goods* goods)
{
    srand(time(NULL));

    for (int i = 0; i < GOODS_SIZE; i++)
    {
        // Generate random values for goods
        goods[i].name = goodsNames[rand() % GOODS_SIZE];
        goods[i].supplier = suppliers[rand() % SUPPLIERS_SIZE];
        goods[i].price = (111 * rand() % 900000) / static_cast<float>(100);
        goods[i].numberOfUnits = rand() % 100 + 1;
        goods[i].dateOfSupply.day = rand() % 31 + 1;
        goods[i].dateOfSupply.month = rand() % 12 + 1;
        goods[i].dateOfSupply.year = rand() % 6 + 2010;
        goods[i].country = countries[rand() % COUNTRIES_SIZE];
    }
}

// Searches required suppliers, changes the resultSize according to the number of found suppliers
// and returns new array.
Goods* searchSuppliers(Goods* inputGoods, int& resultSize)
{
    Goods* result = nullptr;
    int count = 0;

    // Count the number of suppliers that match the condition
    for (int i = 0; i < GOODS_SIZE; i++)
    {
        if (inputGoods[i].country == "Ukraine" && inputGoods[i].dateOfSupply.year == 2013 && inputGoods[i].price > 2000)
        {
            count++;
        }
    }
    
    if (count > 0)
    {
        // Allocate memory for the result array
        result = new Goods[count];
        int index = 0;

        // Populate the result array with matching suppliers
        for (int i = 0; i < GOODS_SIZE; i++)
        {
            if (inputGoods[i].country == "Ukraine" && inputGoods[i].dateOfSupply.year == 2013 && inputGoods[i].price > 2000)
            {
                result[index] = inputGoods[i];
                index++;
            }
        }
    }

    // Update the result size and return the result array
    resultSize = count;
    return result;
}

int main()
{
    SetConsoleOutputCP(1251); // необхідно для виводу українською
    
    int resultSize = 0;
    Goods goods[GOODS_SIZE];

    generateSuppliers(goods);
    
    Goods* results = searchSuppliers(goods, resultSize);

    if (resultSize > 0)
    {
        // Display the matching suppliers
        for (int i = 0; i < resultSize; i++)
        {
            cout << "Result " << i << ":\n" << results[i].supplier << " | "
                << results[i].name << " | "
                << results[i].dateOfSupply.year << " | " 
                << results[i].country << endl;
        }
    }
    else 
    {
        cout << "No supplier suits the condition.\n";
    }

    // Deallocate the memory for the result array
    delete[] results;
}
