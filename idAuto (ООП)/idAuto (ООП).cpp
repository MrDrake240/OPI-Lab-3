#include <windows.h>
#include <iostream>
#include <cmath>
#include <string>  
#include <vector>

using namespace std;

class IdAuto
{
public:
    static const int Row = 8;
    const string Mark[Row] = { "Неизвестно", "Mazda", "Honda", "Nissan", "Toyota", "Mitsubishi", "Subaru", "Suzuki" };
    const string Model[Row][Row] =
    {
        {"Неизвестно"},
        {"Неизвестно", "3", "6", "RX-7", "RX-8", "MX-5", "CX-5", "CX-9"},
        {"Неизвестно", "Civic", "Torneo", "CR-Z", "CR-V", "Accord", "S2000", "Integra"},
        {"Неизвестно", "Silvia", "Murano", "Juke", "Skyline GT-R", "Qashqai", "X-Trail", "Micra"},
        {"Неизвестно", "Tundra", "Land Cruiser", "Corolla", "Supra", "Mark II", "Chaser", "Camry"},
        {"Неизвестно", "Lancer Evo", "Outlander", "Eclipse", "Pajero", "Colt", "Galant", "Grandis"},
        {"Неизвестно", "Impreza WRX", "XV", "BRZ", "Outback", "Forester", "Justy", "Levong"},
        {"Неизвестно", "Grand Vitara", "Celerio", "SX4", "XL7", "Alto", "Solio", "Liana"}
    };
    int id = 0, mark = 0, wheel = 0, color = 0, year = 0, drive = 0, transmission = 0, model = 0, comm3 = 0;

    int Getid()
    {
        cout << "Какая марка автомобиля ?\n1." << Mark[1] << "\n2." << Mark[2] << "\n3." << Mark[3] << "\n4." << Mark[4] << "\n5." << Mark[5] << "\n6." << Mark[6] << "\n7." << Mark[7] << endl;
        cin >> mark;
        cout << "Какая модель автомобиля?" << endl;
        switch (mark)
        {
        case 1:
            cout << "1. " << Model[1][1] << "\n2. " << Model[1][2] << "\n3. " << Model[1][3] << "\n4. " << Model[1][4] << "\n5. " << Model[1][5] << "\n6. " << Model[1][6] << "\n7. " << Model[1][7] << endl;
            break;

        case 2:
            cout << "1. " << Model[2][1] << "\n2. " << Model[2][2] << "\n3. " << Model[2][3] << "\n4. " << Model[2][4] << "\n5. " << Model[2][5] << "\n6. " << Model[2][6] << "\n7. " << Model[2][7] << endl;
            break;
        case 3:
            cout << "1. " << Model[3][1] << "\n2. " << Model[3][2] << "\n3. " << Model[3][3] << "\n4. " << Model[3][4] << "\n5. " << Model[3][5] << "\n6. " << Model[3][6] << "\n7. " << Model[3][7] << endl;
            break;
        case 4:
            cout << "1. " << Model[4][1] << "\n2. " << Model[4][2] << "\n3. " << Model[4][3] << "\n4. " << Model[4][4] << "\n5. " << Model[4][5] << "\n6. " << Model[4][6] << "\n7. " << Model[4][7] << endl;
            break;
        case 5:
            cout << "1. " << Model[5][1] << "\n2. " << Model[5][2] << "\n3. " << Model[5][3] << "\n4. " << Model[5][4] << "\n5. " << Model[5][5] << "\n6. " << Model[5][6] << "\n7. " << Model[5][7] << endl;
            break;
        case 6:
            cout << "1. " << Model[6][1] << "\n2. " << Model[6][2] << "\n3. " << Model[6][3] << "\n4. " << Model[6][4] << "\n5. " << Model[6][5] << "\n6. " << Model[6][6] << "\n7. " << Model[6][7] << endl;
            break;
        case 7:
            cout << "1. " << Model[7][1] << "\n2. " << Model[7][2] << "\n3. " << Model[7][3] << "\n4. " << Model[7][4] << "\n5. " << Model[7][5] << "\n6. " << Model[7][6] << "\n7. " << Model[7][7] << endl;
            break;
        }
        cin >> model;
        cout << "Какой привод(ведущее колесо)?\n1. AWD\n2. RWD\n3. FWD\n4. 4WD" << endl;
        cin >> drive;
        cout << "Как расположен руль? \n1. Слева\n2. Справа" << endl;
        cin >> wheel;
        cout << "Какая коробка передач?\n1. Ручная\n2. Автоматическая" << endl;
        cin >> transmission;
        cout << "Какой цвет у автомобиля?\n1. Чёрный\n2. Белый\n3. Серый/Серебристый\n4. Синий\n5. Красный\n6. Иной" << endl;
        cin >> color;
        cout << "Введите год выпуска автоиобиля: ";
        cin >> year;
        id = (mark * 10000000) + (model * 1000000) + (drive * 100000) + (wheel * 10000) + (transmission * 1000) + (color * 100) + (year % 100);
        cout << "\nВаш id: " << id << endl;
        return id;
    }

    void GetData(int id)
    {
        mark = id / 10000000;
        model = (id / 1000000) % 10;
        drive = (id / 100000) % 10;
        wheel = (id / 10000) % 10;
        transmission = (id / 1000) % 10;
        color = (id / 100) % 10;
        year = (id % 100);
        if (year > 21)
        {
            year = year + 1900;
        }
        else
        {
            year = year + 2000;
        }
        if ((mark <= Row || mark >= 0) && (model >= 0 || model >= Row))
        {
            cout << "Модель: " << Mark[mark] << " " << Model[mark][model] << endl;
        }
        else
        {
            cout << "Модель: " << Mark[0] << " " << Model[0][0] << endl;
        }
        switch (drive)
        {
        case 1:
            cout << "Привод: AWD" << endl;
            break;
        case 2:
            cout << "Привод: RWD" << endl;
            break;
        case 3:
            cout << "Привод: FWD" << endl;
            break;
        case 4:
            cout << "Привод: 4WD" << endl;
            break;
        default:
            cout << "Привод: Неизвестно" << endl;
            break;
        }
        switch (wheel)
        {
        case 1:
            cout << "Руль: Левый" << endl;
            break;
        case 2:
            cout << "Руль: Правый" << endl;
            break;
        default:
            cout << "Руль: Неизвестно" << endl;
            break;
        }
        switch (transmission)
        {
        case 1:
            cout << "Коробка передач: Ручная" << endl;
            break;
        case 2:
            cout << "Коробка передач: Автоматическа" << endl;
            break;
        default:
            cout << "Коробка передач: Неизвестно" << endl;
            break;
        }
        switch (color)
        {
        case 1:
            cout << "Цвет: Чёрный" << endl;
            break;
        case 2:
            cout << "Цвет: Белый" << endl;
            break;
        case 3:
            cout << "Цвет: Серый/Серебристый" << endl;
            break;
        case 4:
            cout << "Цвет: Синий" << endl;
            break;
        case 5:
            cout << "Цвет: Красный" << endl;
            break;
        default:
            cout << "Цвет: Иной" << endl;
            break;
        }
        cout << "Год: " << year << endl;
    }
};

class IdBase
{
public:
    vector <int> vbase = { -1 };
    

    IdBase()
    {

    }

    void BaseAdd(int id)
    {

        for (int i = 0; i < vbase.size(); i++)
        {
            if (vbase.at(i) <= 0)
            {
                vbase.push_back(id);
                break;
            }
        }
    }

    int BasePrint()
    {
        int comm;
        cout << "Id:" << endl;
        for (int i = 0; i < vbase.size(); i++)
        {
            if (vbase.at(i) > 0)
            {
                cout << i << ". " << vbase.at(i) << endl;
            }
        }
        cin >> comm;
        return vbase.at(comm);
    }

    
};

int main()
{
    setlocale(LC_ALL, "Rus");
    int command, comm2 = 2, id = 0;
    IdBase data;
    while (1)
    {
        IdAuto vid;
        cout << "\nЧто вы хотите сделать?\n" << "1. Получить id\n" << "2. Ввести / расшифровать id\n" << "3. Внести id в базу данных\n" << "4. Выйти" << endl;
        cin >> command;

        if (command == 1)
        {
            id = vid.Getid();
            data.BaseAdd(id);
        }

        else if (command == 2)
        {
            if (id != 0)
            {
                cout << "Использовать предыдущий id? \n1. Да \n2. Нет" << endl;
                cin >> comm2;
                if (comm2 == 1)
                {
                    id = data.BasePrint();
                    vid.GetData(id);
                }
            }
            if (comm2 == 2 || id == 0)
            {
                cout << "Введтие id (8 цифр)" << endl;
                cin >> id;
                vid.GetData(id);
            }
        }

        else if (command == 3)
        {
            cout << "Введтие id (8 цифр)" << endl;
            cin >> id;
            data.BaseAdd(id);
        }

        else if (command == 4)
        {
            return 0;
        }

        else if (command < 1 || command>4)
        {
            cout << "Ошибка ввода команды, введите команду ещё раз." << endl;
        }
    }
}
