#include <iostream>
using namespace std;
int main(){
    int N, firstmax, number; 
    cin >> N;
    if (N <= 0) {
        cout << "Последовательность пустая" << endl; 
        return 0;
    } 
    cin >> firstmax; 
    for(int i = 2; i <= N; i++){
        cin >> number; 
        if(number > firstmax) { firstmax = number; }
    }
    cout << "Первый максимальный элемент: " << firstmax << endl; 
    return 0;
}