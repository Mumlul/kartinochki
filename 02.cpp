#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

/*Разработать класс Товар(название, код товара, единица измерения, стоимость товара).
Информация должна быть записана в файл.
Пользователь может выбрать структурирование информации по возрастанию или убыванию.
Пользователь может добавлять данные в файл через консоль.*/

class Product {
public:
    int id;
    string name;
    string un;
    double price;

    //Конструктор
    Product(int i, string n, string u, double p)
        : id(i), name(n), un(u), price(p){ }

    //Конструктор для чтения из файла
    Product() = default;

    //Вывод информации
    void print() const {
        cout << "Номер: " << id
            << ", Имя: " << name
            << ", Единица измерения: " << un
            << ", Стоимость: " << price << endl;
    }
};


//Запись в файл
void saveToFile(const vector<Product>& p, const string& ofs) {
    ofstream out(ofs);
    if (!out.is_open()) {
        cerr << "Ошибка открытия файла" << endl;
        return;
    }

    for (const auto& product : p) {
        out << product.id << ";"
            << product.name << ";"
            << product.un << ";"
            << product.price << "\n";
    }

    out.close();
}

//Чтение позиций из файла
vector<Product> readProductsFromFile(const string& filename) {
    vector<Product> products;

    ifstream ifs(filename);
    if (!ifs) return products;

    string line;
    while (getline(ifs, line)) {
        Product p;
        size_t pos = 0;
        size_t next_pos;

        // id
        next_pos = line.find(';', pos);
        if (next_pos == string::npos) continue;
        p.id = stoi(line.substr(pos, next_pos - pos));
        pos = next_pos + 1;

        // name
        next_pos = line.find(';', pos);
        if (next_pos == string::npos) continue;
        p.name = line.substr(pos, next_pos - pos);
        pos = next_pos + 1;

        // un (единица измерения)
        next_pos = line.find(';', pos);
        if (next_pos == string::npos) continue;
        p.un = line.substr(pos, next_pos - pos);
        pos = next_pos + 1;

        // price
        p.price = stod(line.substr(pos)); 

        products.push_back(p);
    }

    return products;
}

void addProduct(vector<Product>& prod) {
    string name, un;
    static int id;
    double price;

    cin.ignore();

    cout << "Название: ";
    getline(cin, name);

    cout << "Единица измерения: ";
    getline(cin, un);

    cout << "Цена: ";
    cin >> price;

    Product newProduct(id++, name, un, price);
    prod.push_back(newProduct);
}


void sortProduct(vector<Product>& products, bool asc) {
    if (asc) {
        sort(products.begin(), products.end(), [](const Product& a, const Product& p) {
            return a.id < p.id;
            });
    }
    else {
        sort(products.begin(), products.end(), [](const Product& a, const Product& p) {
            return a.id > p.id;
            });
    }    
}

int main()
{
    setlocale(LC_ALL, "Russian");
    const string filename = "product.txt";
    vector<Product> prod = readProductsFromFile(filename);
    int choice;

    do {
        cout << "\n Меню: 1. Добавить.\n 2. Сортировать.\n 3. Показать.\n 4. Сохранить и выйти.\n Ваш выбор: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addProduct(prod);
            break;
        case 2:
            int order;
            cout << "Сортировать по возрастанию (1) или по убыванию (иное): ";
            cin >> order;
            sortProduct(prod, (order == 1));
            break;
        case 3:
            for (const auto& prod : prod)
                prod.print();
            break;
        case 4:
            saveToFile(prod, filename);
            cout << "Сохранено" << endl;
            break;

        default:
            cout << "Неверный выбор!" << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}