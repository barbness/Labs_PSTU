#include <iostream>
#include "c_4.h"
using namespace std; 

void printPair(const Pair& p) {
    cout << "(" << p.firstGet() << ", " << p.secondGet() << ")";
}

void printComplex(const Complex& c) {
    cout << c.getReal();

    if (c.getImage() >= 0) {
        cout << " , " << c.getImage();
    } else {
        cout << " , " << -c.getImage();
    }
}

int main(){
    Pair p1;
    Pair p2(3, 5);
    p1.firstSet(10);
    p1.secondSet(20);
    Pair p3(p1);

    Pair p4 = p3 + p2;
    printPair(p3);

    Complex c1;
    Complex c2(4, 7);
    c1.setReal(6);
    c1.setImage(2);
    Complex c3(c1);

    Complex c4 = c3 - c2;
    printComplex(c4);
    cout << endl;

    Complex c5 = c1 * c2;
    printComplex(c5);
}