#include <iostream>
#include <vector>
#include <clocale>
#include "Time.h"
#include "Vector.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    vector<Time> values;

    values.push_back(Time(1, 10));
    values.push_back(Time(3, 20));
    values.push_back(Time(2, 45));
    values.push_back(Time(0, 55));
    values.push_back(Time(3, 20));

    Vector<Time> v(values);

    cout << "Исходный Vector<Time>:" << endl;
    v.Print();

    cout << endl << "1. Найти максимальный элемент и добавить его в конец:" << endl;
    v.AddMaxToEnd();
    v.Print();

    cout << endl << "2. Найти элемент с ключом 3:20 и удалить его:" << endl;
    v.DeleteByKey(Time(3, 20));
    v.Print();

    cout << endl << "3. К каждому элементу добавить среднее арифметическое:" << endl;
    v.AddAverageToEach();
    v.Print();

    return 0;
}