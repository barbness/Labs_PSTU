#include "c_3.h" 
#include <iostream>
#include <windows.h>
using namespace std; 

int main(){
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int m, s, as; 
    cout << "Введите минуты: "; 
    cin >> m; 
    cout << "Введите секунды: "; 
    cin >> s; 

    Time timer(m, s); 
    
    cout << "Текущее время: " << timer.getMin() << ":" << timer.getSec();


    cout << "Введите количество секунд, которое необходимо добавить: "; 
    cin >> as; 
    timer.addSec(as);
    cout << "Измененное время: " << timer.getMin() << ":" << timer.getSec(); 

    Time timer2(timer); 
    if (timer == timer2){cout << "Работает!";}

    return 0; 
}