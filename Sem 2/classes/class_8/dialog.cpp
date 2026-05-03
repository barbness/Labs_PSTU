#include "Dialog.h"
#include "Print.h"
#include "Book.h"
#include <iostream>

using namespace std;

Dialog::Dialog() : Vector() {endState = 0;}
Dialog::Dialog(int n) : Vector(n) {endState = 0;}
Dialog::~Dialog() {}

void Dialog::GetEvent(TEvent& event) {
    char code;

    cout << endl;
    cout << "Введите команду: ";
    cin >> code;

    event.what = evMessage;
    event.command = 0;
    event.a = 0;

    switch (code) {
    case 'm':
        event.command = cmMake;
        cin >> event.a;
        break;

    case '+':
        event.command = cmAdd;
        break;

    case '-':
        event.command = cmDel;
        break;

    case 's':
        event.command = cmShow;
        break;

    case 'z':
        event.command = cmName;
        cin >> event.a;
        break;

    case 'q':
        event.command = cmQuit;
        break;

    default:
        event.command = 0;
        break;
    }
}

void Dialog::HandleEvent(TEvent& event) {
    if (event.what != evMessage) {
        return;
    }

    switch (event.command) {
    case cmMake:
        if (event.a <= 0) {
            cout << "Размер группы должен быть больше 0" << endl;
        }
        else {
            Make(event.a);
        }
        ClearEvent(event);
        break;

    case cmAdd: {
        int choice;

        cout << "Что добавить?" << endl;
        cout << "1 - Печатное издание" << endl;
        cout << "2 - Книгу" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        Object* obj = nullptr;

        if (choice == 1) {
            obj = new Print;
        }
        else if (choice == 2) {
            obj = new Book;
        }
        else {
            cout << "Неверный выбор" << endl;
            ClearEvent(event);
            return;
        }

        obj->Input();
        Add(obj);

        ClearEvent(event);
        break;
    }

    case cmDel:
        Delete();
        ClearEvent(event);
        break;

    case cmShow:
        Show();
        ClearEvent(event);
        break;

    case cmName:
        ShowName(event.a);
        ClearEvent(event);
        break;

    case cmQuit:
        EndExec();
        ClearEvent(event);
        break;

    default:
        break;
    }
}

void Dialog::ClearEvent(TEvent& event) {
    event.what = evNothing;
}

void Dialog::Execute() {
    TEvent event;

    cout << "Список команд:" << endl;
    cout << "m n  - создать группу на n элементов" << endl;
    cout << "+    - добавить элемент" << endl;
    cout << "-    - удалить последний элемент" << endl;
    cout << "s    - показать все элементы группы" << endl;
    cout << "z k  - показать название элемента с номером k" << endl;
    cout << "q    - конец работы" << endl;

    endState = 0;

    do {
        GetEvent(event);
        HandleEvent(event);

        if (event.what != evNothing) {
            EventError(event);
        }

    } while (!Valid());
}

int Dialog::Valid() const {
    return endState != 0;
}

void Dialog::EndExec() {
    endState = 1;
}

void Dialog::EventError(const TEvent& event) const {
    cout << "Ошибка: команда не обработана" << endl;
}