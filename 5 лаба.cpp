#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CDcollection
{
protected:
    vector<Disk> disks; // вектор для зберігання дисків

public:
    CDcollection() {}
    string name = "Honest collection";
    double size = 7.52;
    string type = "Gb";
    string date = "14-03-2024";

    // Метод для виведення інформації про всі диски у колекції
    void printAllDisks()
    {
        for (const Disk& disk : disks)
        {
            disk.print();
            cout << endl;
        }
    }

    // Метод для додавання диска до колекції
    void addDisk(const Disk& disk)
    {
        disks.push_back(disk);
    }

    // Метод для видалення диска з колекції за індексом
    void removeDisk(int index)
    {
        if (index >= 0 && index < disks.size())
        {
            disks.erase(disks.begin() + index);
        }
        else
        {
            cout << "Invalid index" << endl;
        }
    }
};

class Disk : public CDcollection
{
protected:
    string author;
    string album;

public:
    // Конструктор класу Disk, який ініціалізує всі поля класу
    Disk(string n, double s, string t, string d, string a, string o) : author(a), album(o)
    {
        name = n;
        size = s;
        type = t;
        date = d;
    }

    // Метод для виведення інформації про диск
    void print()
    {
        cout << "name: " << name << "\nsize: " << size << " " << type << "\ndate: " << date << "\nauthor: " << author << "\nalbum: " << album << endl;
    }
};

int main()
{
    CDcollection myCollection;

    // Додавання диска до колекції
    Disk pr("Honest collection", 7.2, "Gb", "14-03-2024", "Beethoven", "Golden years");
    myCollection.addDisk(pr);

    // Виведення інформації про всі диски у колекції
    myCollection.printAllDisks();

    // Видалення диска з колекції за індексом
    myCollection.removeDisk(0);

    // Повторне виведення інформації про всі диски у колекції (без диска, який ми видалили)
    myCollection.printAllDisks();

    return 0;
}
