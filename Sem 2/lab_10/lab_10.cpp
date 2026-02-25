//Сформировать одномерный массив. Удалить из него элемент с заданным номером, добавить К элементов, начиная с заданного номера

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 
int main(){
    int N; 
    cin >> N; 
    int* a = new int[N];

    srand(time(0));
    int range_max = 100; 
    int range_min = -100; 

    for (int i = 0; i < N; i++)
    {
        a[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
        cout << a[i] << " ";
    }  
    cout << endl;

    int delel; 
    int K;
    cout << "Введите номер удаляемого элемента от 0 до " << N-1 << " "; 
    cin >> delel; 
    int del = delel-1;
    cout << "Введите K "; 
    cin >> K;
    int* b = new int[N+K-1];
    cout << "Введите новые элементы" << endl;
    for (int i = 0; i < N; i++){
        if(i < del){
            b[i] = a[i];
        }
        else if(i == del){
            for (int j = 0; j < K; j++){
                cin >> b[i+j]; 
            }
        }
        else{
            b[i+K-1] = a[i];
        }
    }
    
    for (int i = 0; i < N+K-1; i++)
    {
        cout << b[i] << " ";
    } 

    delete[] a;
    delete[] b;
    return 0; 
}