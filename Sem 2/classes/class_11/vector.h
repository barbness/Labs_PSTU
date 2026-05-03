#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Vector {
private:
    vector<T> data;

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
    data = values;
}

template <class T>
void Vector<T>::Print() const {
    for (typename vector<T>::const_iterator it = data.begin(); it != data.end(); ++it) {
        cout << *it << " ";
    }

    cout << endl;
}

template <class T>
void Vector<T>::AddMaxToEnd() {
    if (data.empty()) {
        return;
    }

    T maxElement = data[0];

    for (typename vector<T>::iterator it = data.begin(); it != data.end(); ++it) {
        if (*it > maxElement) {
            maxElement = *it;
        }
    }

    data.push_back(maxElement);
}

template <class T>
void Vector<T>::DeleteByKey(T key) {
    for (typename vector<T>::iterator it = data.begin(); it != data.end(); ++it) {
        if (*it == key) {
            data.erase(it);
            return;
        }
    }
}

template <class T>
void Vector<T>::AddAverageToEach() {
    if (data.empty()) {
        return;
    }

    T sum = T();

    for (typename vector<T>::iterator it = data.begin(); it != data.end(); ++it) {
        sum = sum + *it;
    }

    T average = sum / data.size();

    for (typename vector<T>::iterator it = data.begin(); it != data.end(); ++it) {
        *it = *it + average;
    }
}