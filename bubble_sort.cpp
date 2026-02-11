#include <iostream> 
using namespace std; 

int main (){  
    const int N = 5;
    int arr[N]; 
    for (int i = 0; i < N; i++){
        cin >> arr[i]; 
    }
    int tmp;
    for (int i = 0; i < N-1; i++){
        for (int j =0; j < (N - 1)-i; j++){
            if (arr[j] > arr[j+1]){
                tmp = arr[j]; 
                arr[j] = arr[j+1];
                arr[j+1] = tmp; 
            }
        }
    }
    for (int i = 0; i < N; i++){
        cout << arr[i] << " "; 
    }
cout << endl; 
return 0;
}