#include <iostream> 
using namespace std; 

int partition(int arr[], int low, int high){
    int pivot = arr[high]; 
    int i = low - 1; 

    for(int j = low; j <= high-1; j++){
        if (arr[j] <= pivot){
            i++; 
            swap(arr[i], arr[j]); 
        }
    }

    swap(arr[i+1], arr[high]); 
    return (i+1); 
}

void lomuto_sort(int arr[], int low, int high){
    if (low < high){
        int pI = partition(arr, low, high); 
        lomuto_sort(arr, low, pI-1); 
        lomuto_sort(arr, pI+1, high); 
    }
}

int main(){
    const int N = 7; 
    int a[N] = {1, 6, 3, 2, 8, 9, 10}; 

    lomuto_sort(a, 0, N-1);

    cout << "Sorted massive: "; 
    for (int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
}