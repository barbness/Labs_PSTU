#pragma once
#include "Print.h"
#include <string>

class Book : public Print {
private:
    int pages;
    std::string publisher;

public:
    Book();
    Book(std::string n, std::string a, int p, std::string pub);
    Book(const Book& other);
    ~Book();

    void Show() const override;
    void Input() override;

    Book& operator=(const Book& other);
};