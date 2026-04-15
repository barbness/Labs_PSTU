#include <iostream> 
using namespace std; 

int* sort(const int arr[], int size){
    int* sorted = new int[size];

    for (int i = 0; i < size; i++) {
        sorted[i] = arr[i];
    }

    int tmp, min_index;
    for (int i = 0; i < size - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (sorted[j] < sorted[min_index]) {
                min_index = j;
            }
        }

        tmp = sorted[min_index];
        sorted[min_index] = sorted[i];
        sorted[i] = tmp;
    }

    return sorted;
}

int BS(int arr[], int size, int target){
    int l = 0;
    int r = size - 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (arr[mid] == target) {
            return mid+1;
        }
        else if (target > arr[mid]) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return -1;
}

int main(){ 
    int N; 
    cout << "Введите длину массива: "; 
    cin >> N; 
    int a[N]; 
    int p; 

    cout << "Введите элементы массива: " << endl; 
    for (int i = 0; i < N; i++){
        cin >> a[i]; 
    }

    int* b = sort(a, N); 

    cout << "Введите элемент, который хотите найти: "; 
    cin >> p; 

    cout << "Отсортированный массив: ";
    for (int i = 0; i < N; i++){
        cout << b[i] << " ";
    }
    cout << endl; 

    int c = BS(b, N, p); 
    if (c == -1){cout << "Не удалось найти элемент";}
    else{cout << "Позиция элемента в отсортированном массиве: " << c; }

    delete[] b; 
}