#include <iostream>
#include "c_5.h"
using namespace std;

void printComplex(const Complex& c) {
    cout << c.getReal();

    if (c.getImage() >= 0) {
        cout << " , " << c.getImage();
    } else {
        cout << " , " << -c.getImage();
    }
}

int main(){
    Complex c1;
    Complex c2(4, 7);
    c1.setReal(6);
    c1.setImage(2);
    Complex c3(c1);

    Pair* c6 = c3 + c2;
    cout << c6->firstGet() << "," <<c6->secondGet() << endl;
    Complex c4 = c3 - c2;
    printComplex(c4);
    cout << endl;

    Complex c5 = c1 * c2;
    printComplex(c5);
}