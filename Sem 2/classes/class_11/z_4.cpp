#include <iostream>
#include <queue>
#include <clocale>
#include "Time.h"

using namespace std;

typedef queue<Time> QueueTime;

void PrintQueue(QueueTime q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
}

void AddMaxToEnd(QueueTime& q) {
    if (q.empty()) {
        return;
    }

    QueueTime copy = q;
    Time maxElement = copy.front();

    while (!copy.empty()) {
        if (copy.front() > maxElement) {
            maxElement = copy.front();
        }

        copy.pop();
    }

    q.push(maxElement);
}

void DeleteByKey(QueueTime& q, Time key) {
    QueueTime temp;
    bool deleted = false;

    while (!q.empty()) {
        Time current = q.front();
        q.pop();

        if (current == key && deleted == false) {deleted = true;}
        else {temp.push(current);}
    }

    q = temp;
}

void AddAverageToEach(QueueTime& q) {
    if (q.empty()) return;

    QueueTime copy = q;

    Time sum;
    int count = 0;

    while (!copy.empty()) {
        sum = sum + copy.front();
        copy.pop();
        count++;
    }

    Time average = sum / count;

    QueueTime result;

    while (!q.empty()) {
        result.push(q.front() + average);
        q.pop();
    }

    q = result;
}

int main() {
    setlocale(LC_ALL, "Russian");

    QueueTime q;

    q.push(Time(1, 30));
    q.push(Time(2, 10));
    q.push(Time(3, 40));
    q.push(Time(2, 10));
    q.push(Time(0, 50));

    cout << "Исходная очередь Time:" << endl;
    PrintQueue(q);

    cout << endl << "1. Найти максимальный элемент и добавить его в конец:" << endl;
    AddMaxToEnd(q);
    PrintQueue(q);

    cout << endl << "2. Найти элемент с ключом 2:10 и удалить его:" << endl;
    DeleteByKey(q, Time(2, 10));
    PrintQueue(q);

    cout << endl << "3. К каждому элементу добавить среднее арифметическое:" << endl;
    AddAverageToEach(q);
    PrintQueue(q);

    return 0;
}