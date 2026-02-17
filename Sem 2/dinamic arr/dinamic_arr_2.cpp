#include <iostream>
using namespace std;
int main(){
    int massivi = 2, stroki = 4, stolbci = 3; 

    int *arr = new int[massivi*stroki*stolbci];

    //допустим заполним массив значениями 2i+3j+5k 
    for (int i = 0; i < massivi; i++){
        for (int j = 0; j < stroki; j++){
            for (int k =0; k < stolbci; k++){
                int index = (i * stroki + j) * stolbci + k;
                arr[index] = 2*i + 3*j + 5*k;
            } 
        }
    }
    for (int i = 0; i < massivi; i++){
        for (int j =0; j< stroki; j++){
            for (int k =0; k < stolbci; k++){
                int index = (i * stroki + j) * stolbci + k;
                cout << arr[index] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    delete[] arr; 
    return 0;
}