#pragma once
#include "Object.h"
#include <string>

class Print : public Object {
protected:
    std::string name;
    std::string author;

public:
    Print();
    Print(std::string n, std::string a);
    Print(const Print& other);
    virtual ~Print();

    void Show() const override;
    void Input() override;
    std::string GetName() const override;

    Print& operator=(const Print& other);
};