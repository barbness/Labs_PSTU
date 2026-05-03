#include <iostream>
#include <deque>
#include <clocale>

using namespace std;

typedef deque<int> DequeInt;

void PrintDeque(const DequeInt& d) {
    for (DequeInt::const_iterator it = d.begin(); it != d.end(); ++it) {
        cout << *it << " ";
    }

    cout << endl;
}

void AddMaxToEnd(DequeInt& d) {
    if (d.empty()) {
        return;
    }

    int maxElement = d[0];

    for (DequeInt::iterator it = d.begin(); it != d.end(); ++it) {
        if (*it > maxElement) {
            maxElement = *it;
        }
    }

    d.push_back(maxElement);
}

void DeleteByKey(DequeInt& d, int key) {
    for (DequeInt::iterator it = d.begin(); it != d.end(); ++it) {
        if (*it == key) {
            d.erase(it);
            return;
        }
    }
}

void AddAverageToEach(DequeInt& d) {
    if (d.empty()) return;

    int sum = 0;

    for (DequeInt::iterator it = d.begin(); it != d.end(); ++it) {sum += *it;}

    int average = sum / d.size();

    for (DequeInt::iterator it = d.begin(); it != d.end(); ++it) {*it += average;}
}

int main() {
    setlocale(LC_ALL, "Russian");

    DequeInt d;

    d.push_back(10);
    d.push_back(4);
    d.push_back(25);
    d.push_back(8);
    d.push_front(3);

    cout << "Исходная двунаправленная очередь:" << endl;
    PrintDeque(d);

    cout << endl << "1. Найти максимальный элемент и добавить его в конец:" << endl;
    AddMaxToEnd(d);
    PrintDeque(d);

    cout << endl << "2. Найти элемент с ключом 4 и удалить его:" << endl;
    DeleteByKey(d, 4);
    PrintDeque(d);

    cout << endl << "3. К каждому элементу добавить среднее арифметическое:" << endl;
    AddAverageToEach(d);
    PrintDeque(d);

    return 0;
}