#include <iostream>
using namespace std; 

void countSort(int arr[], int size)
{
    if (size <= 1) return;

    int max = arr[0];

    for (int i = 1; i < size; i++){ 
        if (arr[i] > max) max = arr[i]; 
    }

    int* count = new int[max + 1]{0}; 
    int* output = new int[size];

    for (int i = 0; i < size; i++) { 
        count[arr[i]]++; 
    }

    for (int i = 1; i <= max; i++) { 
        count[i] += count[i - 1]; 
    }

    for (int i = size - 1; i >= 0; i--){
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < size; i++){ 
        arr[i] = output[i]; 
    }

    delete[] count;
    delete[] output;
}

int main(){
    int a[] = {4, 2, 2, 8, 3, 3, 1};
    const int N = 7; 

    countSort(a, N);
    cout << "Sorted massive: " << endl; 

    for (int i = 0; i < N; i++)
        cout << a[i] << " ";

    return 0;
}