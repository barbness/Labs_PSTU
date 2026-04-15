#include <iostream> 
using namespace std; 

void shell_sort(int arr[], int size){
    for (int h = size / 2; h > 0; h /= 2){
        for (int i = h; i < size; i++){
            int tmp = arr[i];
            int j;

            for (j = i; j >= h; j -= h){
                if (tmp < arr[j - h]){
                    arr[j] = arr[j - h];
                }
                else {
                    break;
                }
            }

            arr[j] = tmp;
        }
    }
}

int main(){ 
    const int N = 7; 
    int a[N] = {6, 1, 4, 8, 3, 9, 0}; 

    shell_sort(a, N); 

    cout << "Sorted massive: "; 

    for (int i = 0; i < N; i++){
        cout << a[i] << " "; 
    }
}