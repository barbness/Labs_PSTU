#include "Print.h"
#include <iostream>

using namespace std;

Print::Print(): name(""), author("") {}
Print::Print(string n, string a): name(n), author(a) {}
Print::Print(const Print& other): name(other.name), author(other.author){}
Print::~Print() {}

void Print::Show() const {
    cout << "Печатное издание" << endl;
    cout << "Название: " << name << endl;
    cout << "Автор: " << author << endl;
}

void Print::Input() {
    cout << "Введите название: ";
    cin >> ws;
    getline(cin, name);

    cout << "Введите автора: ";
    getline(cin, author);
}

string Print::GetName() const {return name;}

Print& Print::operator=(const Print& other) {
    if (this != &other) {
        name = other.name;
        author = other.author;
    }

    return *this;
}