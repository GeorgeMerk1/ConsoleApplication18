#include <iostream>
using namespace std;



struct DateTime {
    double year;
    int month;
    int day;
    int hour;
    int minute;
};

struct Sheep
{
    int weight = 40;
    int weightWool = 400;
    DateTime birthday = { 1998,4,25,6,30 };

    void print() {

        setlocale(LC_ALL, "Russian");
        cout << weight << " " << weightWool << " " <<
            birthday.year << " " << birthday.month << endl;
    }
};

void addSheep(Sheep*& sheeps, int& size, Sheep sheep) {
    Sheep* temp = new Sheep[size + 1];
    for (int i = 0; i < size; i++) {
        temp[i] = sheeps[i];
    }
    temp[size] = sheep;
    delete[] sheeps;
    sheeps = temp;
    size++;
}

void deliteSheep(Sheep*& sheeps, int& size, int index) {
    Sheep* temp = new Sheep[size - 1];
    if (index <= size) {
        for (int i = 0; i < index; i++) {
            temp[i] = sheeps[i];
        }
        for (int i = index + 1; i < size; i++) {
            temp[i - 1] = sheeps[i];
        }
        delete[] sheeps;
        sheeps = temp;
        size--;
    }
    else {
        cout << "u are bed human" << endl;
    }
}




Sheep createSheep() {
        Sheep sheep;
        sheep.weight = rand() % 100 + 20;
        sheep.weightWool = rand() % 100 + 200;
        return sheep;
    }


int main()
{
        int size = 10;
        Sheep* arrSheeps = new Sheep[size];
         int meat = 0;
         for (int iq = 0; iq <= 30; iq++) {
             setlocale(LC_ALL, "Russian");
             srand(time(0));

             for (int i = 0; i < size; i++) {
                 arrSheeps[i].print();
                 cout << endl;
             }
             cout << endl << endl;



        int index;
        cin >> index;
         int meat = arrSheeps[index].weight;
        deliteSheep(arrSheeps, size, index);


       for (int i = 0; i < size; i++) {
            arrSheeps[i].weight += 1;
            arrSheeps[i].weightWool += 100;

        }


        if (meat < 30) {
            cout << "мяса мало надо забить овцу" << endl;
            deliteSheep(arrSheeps, size, index);
            for (int i = 0; i < size; i++) {
                arrSheeps[i].print();
                cout << endl;
            }
            cout << endl << endl;
        }
        else {
            cout << "Мяса хватает" << endl;
        }
        meat -= 30;
        cout << meat << endl;
        if (iq % 5 == 0) { 
            Sheep NewSheep = createSheep();
            addSheep(arrSheeps, size, NewSheep);
            for (int i = 0; i < size; i++) {
                arrSheeps[i].print();
                cout << endl;
            }
            cout << endl << endl;
        } 

    }


}
