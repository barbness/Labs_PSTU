#include <iostream>
using namespace std;
int main(){
    int massivi = 2, stroki = 4, stolbci = 3; 

    int* data = new int[massivi * stroki * stolbci];
    int*** arr = new int**[massivi];

    for (int i = 0; i < massivi; i++){
        arr[i] = new int*[stroki];
        for (int j = 0; j < stroki; j++){
            arr[i][j] = data + (i*stroki + j) * stolbci; 
        }
    }

    for (int i = 0; i < massivi; i++){
        for (int j = 0; j < stroki; j++){
            for (int k = 0; k < stolbci; k++){
                arr[i][j][k] = 2*i + 3*j + 5*k + 5;
            }
        }
    }

    for (int i = 0; i < massivi; i++){
        for (int j =0; j< stroki; j++){
            for (int k =0; k < stolbci; k++){
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    for (int i = 0; i < massivi; i++){
        delete[] arr[i];
    }
    delete[] arr;
    delete[] data;
    return 0;
}