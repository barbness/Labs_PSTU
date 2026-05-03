#include <iostream>
#include <deque>
#include <clocale>
#include "time.h"

using namespace std;

typedef deque<Time> DequeTime;

void PrintDeque(const DequeTime& d) {
    for (DequeTime::const_iterator it = d.begin(); it != d.end(); ++it) {
        cout << *it << " ";
    }

    cout << endl;
}

void AddMaxToEnd(DequeTime& d) {
    if (d.empty()) {
        return;
    }

    Time maxElement = d[0];

    for (DequeTime::iterator it = d.begin(); it != d.end(); ++it) {
        if (*it > maxElement) {
            maxElement = *it;
        }
    }

    d.push_back(maxElement);
}

void DeleteByKey(DequeTime& d, Time key) {
    for (DequeTime::iterator it = d.begin(); it != d.end(); ++it) {
        if (*it == key) {
            d.erase(it);
            return;
        }
    }
}

void AddAverageToEach(DequeTime& d) {
    if (d.empty()) return;

    Time sum;

    for (DequeTime::iterator it = d.begin(); it != d.end(); ++it) {sum = sum + *it;}

    Time average = sum / d.size();

    for (DequeTime::iterator it = d.begin(); it != d.end(); ++it) {*it = *it + average;}
}

int main() {
    setlocale(LC_ALL, "Russian");

    DequeTime d;

    d.push_back(Time(1, 20));
    d.push_back(Time(2, 40));
    d.push_back(Time(0, 50));
    d.push_back(Time(3, 10));
    d.push_back(Time(2, 40));

    cout << "Исходная двунаправленная очередь:" << endl;
    PrintDeque(d);

    cout << endl << "1. Найти максимальный элемент и добавить его в конец:" << endl;
    AddMaxToEnd(d);
    PrintDeque(d);

    cout << endl << "2. Найти элемент с ключом 4 и удалить его:" << endl;
    DeleteByKey(d, Time(2, 40));
    PrintDeque(d);

    cout << endl << "3. К каждому элементу добавить среднее арифметическое:" << endl;
    AddAverageToEach(d);
    PrintDeque(d);

    return 0;
}