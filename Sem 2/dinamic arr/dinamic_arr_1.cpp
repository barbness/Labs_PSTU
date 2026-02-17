// первый способ - массив указателей 
#include <iostream>
using namespace std;
int main(){
    int massivi = 2, stroki = 4, stolbci = 3; 


    int *** arr = new int**[massivi];
    for (int i = 0; i < massivi; i++){
        arr[i] = new int*[stroki];
    }

    for (int i = 0; i < massivi; i++){
        for (int j = 0; j < stroki; j++){
            arr[i][j] = new int[stolbci];
        }
    }

    for (int i = 0; i < massivi; i++){
        for (int j = 0; j < stroki; j++){
            delete[] arr[i][j];
        }
    }

    for (int i = 0; i < massivi; i++){
        delete[] arr[i];
    }
    delete[] arr;
    
}
