#include "Vector.h"
#include <iostream>

using namespace std;

Vector::Vector(): data(nullptr), size(0), capacity(0){}
Vector::Vector(int n) {
    size = 0;
    capacity = n;
    data = new Object*[capacity];

    for (int i = 0; i < capacity; i++) {
        data[i] = nullptr;
    }
}
Vector::~Vector() {
    Clear();
    delete[] data;
}

void Vector::Make(int n) {
    Clear();
    delete[] data;

    size = 0;
    capacity = n;
    data = new Object*[capacity];

    for (int i = 0; i < capacity; i++) {
        data[i] = nullptr;
    }

    cout << "Группа создана. Максимальное количество элементов: " << capacity << endl;
}

void Vector::Add(Object* obj) {
    if (capacity == 0) {
        cout << "Сначала создайте группу командой m n" << endl;
        delete obj;
        return;
    }

    if (size >= capacity) {
        cout << "Группа заполнена" << endl;
        delete obj;
        return;
    }

    data[size] = obj;
    size++;

    cout << "Элемент добавлен" << endl;
}

void Vector::Delete() {
    if (size == 0) {
        cout << "Группа пустая" << endl;
        return;
    }

    delete data[size - 1];
    data[size - 1] = nullptr;
    size--;

    cout << "Последний элемент удален" << endl;
}

void Vector::Show() const {
    if (size == 0) {
        cout << "Группа пустая" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << endl;
        cout << "Элемент №" << i + 1 << endl;
        data[i]->Show();
    }
}

void Vector::ShowName(int k) const {
    if (k < 1 || k > size) {
        cout << "Элемента с таким номером нет" << endl;
        return;
    }

    cout << "Название элемента №" << k << ": " << data[k - 1]->GetName() << endl;
}

void Vector::Clear() {
    for (int i = 0; i < size; i++) {
        delete data[i];
        data[i] = nullptr;
    }

    size = 0;
}

int Vector::GetSize() const {return size;}
int Vector::GetCapacity() const {return capacity;}