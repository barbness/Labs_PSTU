//напечатать все слова, которые содержат по одной цифрe 
#include <iostream>
using namespace std; 

bool isdigit(char c) {
    return c >= '0' && c <= '9';
}

main(){
    string str; 
    getline(cin, str); 
    int counter = 0; 
    int start = 0;

    for (int i = 0; i <= str.length(); i++){
        if (i == str.length()){
            str[i] = ' ';
        }
        
        if (str[i] == ' '){
            if (counter == 1){
                for (int j = start; j < i; j++){
                    cout << str[j];
                }
                cout << " ";
            }
            counter = 0;
            start = i+1;
        }
        
        if (isdigit(str[i])){
            counter++;
        }
    }
}