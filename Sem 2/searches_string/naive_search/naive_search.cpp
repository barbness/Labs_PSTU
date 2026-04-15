#include <iostream> 
#include <string> 
using namespace std; 

int naiveSearchF(const string& str, const string& pattern){
    int n = str.length(); 
    int m = pattern.length(); 

    for (int i = 0; i <= n - m; i++){
        int j;
        for(j = 0; j < m; j++){
            if (str[i+j] != pattern[j]){
                break; 
            }
        }
    
        if (j == m){
            return i+1; 
        }
    }

    return -1;
}

void naiveSearchA(const string& str, const string& pattern){
    int n = str.length(); 
    int m = pattern.length(); 
    bool found = false; 

    cout << "Позиции: "; 

    for (int i = 0; i <= n - m; i++){
        int j; 
        for (int j = 0; j < m; j++){
            if (str[i+j] != pattern[j]){
                break; 
            }
        }

        if (j == m){
            cout << i+1 << " "; 
            found = true; 
        }
    }

    if (found == false) { cout << "не найдено!";}
}

int main(){
    string text, pattern; 

    cout << "Введите строку: " << endl; 
    getline(cin, text); 

    cout << "Введите паттерн: " << endl; 
    getline(cin, pattern); 

    cout << "Первое вхождение: " << naiveSearchF(text, pattern) << endl; 
    cout << "Все вхождения: "; 
    naiveSearchA(text, pattern); 
    cout << endl;  

    return 0;
}