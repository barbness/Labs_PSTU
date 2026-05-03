#pragma once
#include <string>

class Object {
public:
    Object();
    virtual ~Object();

    virtual void Show() const = 0;
    virtual void Input() = 0;

    // Нужно для команды z k:
    // вывести название элемента группы с номером k
    virtual std::string GetName() const = 0;
};