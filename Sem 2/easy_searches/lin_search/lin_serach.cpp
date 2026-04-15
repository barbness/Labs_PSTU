#include <iostream> 
using namespace std; 

int linSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i+1;
        }
    }
    return -1;
}

int linSerchAll(int arr[], int size, int target, int v[]) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            v[count] = i+1;
            count++;
        }
    }

    return count;
}

int main(){
    int N; 
    cout << "Введите размер массива: "; 
    cin >> N; 
    int a[N]; 
    cout << endl; 

    cout << "Введите элементы массива: ";
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    cout << endl; 

    int p; 
    cout << "Введите число для поиска в массиве: "; 
    cin >> p; 
    cout << endl; 

    int fidx = linSearch(a, N, p);
    if (fidx != -1){cout << "Первое вхождение: " << fidx << endl; }
    else{ cout << "Вхождений не найдено"<< endl; }
    

    int all[N]; 
    int count = linSerchAll(a, N, p, all); 

    if (count > 1) {
        cout << "Все вхождения находятся на индексах: ";
        for (int i = 0; i < count; i++) {
            cout << all[i] << " ";
        }
        cout << endl;
    }
}