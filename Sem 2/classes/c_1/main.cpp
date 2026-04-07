#include <iostream> 
#include "cl_pr.h"
using namespace std;

int main(){
    double first, second, x; 

    cout << "Введите правую границу: "; 
    cin >> first; 
    cout << endl; 

    cout << "Введите левую границу: ";
    cin >> second; 
    cout << endl; 

    cout << "Введите число для проверки: ";
    cin >> x; 
    cout << endl; 

    fraction fr;
    fr.setFirst(first);
    fr.setSecond(second);
    cout << fr.checking(x) << endl;

    return 0;
}