//напечатать все слова, которые содержат по одной цифре

#include <iostream>
#include <bits/stdc++.h>
using namespace std; 

//bool isDig(char a){
//   if (('0' <= a) && (a <= '9')){
   //     return true;
    //}
    //else {return false;}
//}
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