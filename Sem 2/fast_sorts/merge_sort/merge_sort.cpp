#include <iostream> 
using namespace std; 

void merge(int arr[], int left, int mid, int right){
    int leftrange = mid - left + 1; 
    int rightrange = right - mid; 

    int* la = new int[leftrange]; 
    int * ra = new int[rightrange]; 

    for (int i = 0; i < leftrange; i++){ la[i] = arr[left + i]; }
    for (int i = 0; i < rightrange; i++){ ra[i] = arr[mid + 1 + i]; }

    int leftidx = 0; 
    int rightidx = 0; 
    int mergeidx = left; 

    while(leftidx < leftrange && rightidx < rightrange){
        if (la[leftidx] <= ra[rightidx]){
            arr[mergeidx] = la[leftidx];
            leftidx++; 
        }
        else{
            arr[mergeidx] = ra[rightidx];
            rightidx++; 
        }
        mergeidx++; 
    }

    while (leftidx < leftrange){
        arr[mergeidx] = la[leftidx]; 
        leftidx++; 
        mergeidx++; 
    }

    while (rightidx < rightrange){
        arr[mergeidx] = ra[rightidx]; 
        rightidx++; 
        mergeidx++; 
    }

    delete[] la; 
    delete[] ra; 
}

void mergeSort(int arr[], int start, int end){
    if (start >= end) return; 
    int mid = start + (end - start)/2; 

    mergeSort(arr, start, mid); 
    mergeSort(arr, mid+1, end); 
    merge(arr, start, mid, end); 
}

int main(){
    int arr[] = {6, 3, 8, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);
    cout << "Sorted massive: " << endl; 

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}