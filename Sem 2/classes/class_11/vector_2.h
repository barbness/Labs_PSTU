#pragma once
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <class T>
class Vector {
private:
    queue<T> data;

public:
    Vector();
    Vector(const vector<T>& values);

    void Print() const;

    void AddMaxToEnd();
    void DeleteByKey(T key);
    void AddAverageToEach();
};

template <class T>
Vector<T>::Vector() {}

template <class T>
Vector<T>::Vector(const vector<T>& values) {
    for (typename vector<T>::const_iterator it = values.begin(); it != values.end(); ++it) {
        data.push(*it);
    }
}

template <class T>
void Vector<T>::Print() const {
    queue<T> copy = data;

    while (!copy.empty()) {
        cout << copy.front() << " ";
        copy.pop();
    }

    cout << endl;
}

template <class T>
void Vector<T>::AddMaxToEnd() {
    if (data.empty()) {
        return;
    }

    queue<T> copy = data;

    T maxElement = copy.front();

    while (!copy.empty()) {
        if (copy.front() > maxElement) {
            maxElement = copy.front();
        }

        copy.pop();
    }

    data.push(maxElement);
}

template <class T>
void Vector<T>::DeleteByKey(T key) {
    queue<T> temp;
    bool deleted = false;

    while (!data.empty()) {
        T current = data.front();
        data.pop();

        if (current == key && deleted == false) {
            deleted = true;
        }
        else {
            temp.push(current);
        }
    }

    data = temp;
}

template <class T>
void Vector<T>::AddAverageToEach() {
    if (data.empty()) {
        return;
    }

    queue<T> copy = data;

    T sum = T();
    int count = 0;

    while (!copy.empty()) {
        sum = sum + copy.front();
        copy.pop();
        count++;
    }

    T average = sum / count;

    queue<T> result;

    while (!data.empty()) {
        result.push(data.front() + average);
        data.pop();
    }

    data = result;
}