#include "Book.h"
#include <iostream>

using namespace std;

Book::Book() : Print() {
    pages = 0;
    publisher = "";
}

Book::Book(string n, string a, int p, string pub) : Print(n, a) {
    pages = p;
    publisher = pub;
}

Book::Book(const Book& other) : Print(other) {
    pages = other.pages;
    publisher = other.publisher;
}

Book::~Book() {}

void Book::Show() const {
    cout << "Книга" << endl;
    cout << "Название: " << name << endl;
    cout << "Автор: " << author << endl;
    cout << "Количество страниц: " << pages << endl;
    cout << "Издательство: " << publisher << endl;
}

void Book::Input() {
    Print::Input();

    cout << "Введите количество страниц: ";
    cin >> pages;

    cout << "Введите издательство: ";
    cin >> ws;
    getline(cin, publisher);
}

Book& Book::operator=(const Book& other) {
    if (this != &other) {
        Print::operator=(other);
        pages = other.pages;
        publisher = other.publisher;
    }

    return *this;
}