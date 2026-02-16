#include <iostream> 
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std; 
int main(){
    srand(time(0));
    int range_min = -1000;
    int range_max = 1000; 
    int N = 6;  
    int j; 
    int a[N] = {1, 2, 3, 4, 5, 6};
    int b[2*N];

    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }

    for (int i = 0; i < N; i++){
        if (a[i]%2 ==0){
            b[j] = -1; 
            j++;
        }
        b[j] = a[i];
        j++;
    }
    for (int i = 0; i < j; i++){
        cout << b[i] << " "; 
        cout << endl;
    }
}