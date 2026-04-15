#include <iostream> 
using namespace std; 

int partition(int arr[], int low, int high){
    int pivot = arr[low + (high - low) / 2]; 
    int i = low - 1; 
    int j = high + 1; 

    while(true){
        do {i++;} while (arr[i] < pivot); 
        do {j--;} while (arr[j] > pivot);

        if ( i >= j ) return j; 

        swap(arr[i], arr[j]); 
    }
}

void hoareSort(int arr[], int low, int high){
    if (low < high){
        int pI = partition(arr, low, high); 

        hoareSort(arr, low, pI);
        hoareSort(arr, pI + 1, high); 
    }
}

int main(){
    const int N = 8; 
    int a[N] = {9, 6, 3, 5, 4, 2, 7, 1}; 

    hoareSort(a, 0, N-1); 
    cout << "sorted massive: "; 

    for ( int i = 0; i < N; i++){
        cout << a[i] << " "; 
    }
}