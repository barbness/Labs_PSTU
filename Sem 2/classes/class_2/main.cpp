#include <string> 
#include "cl_ch.h"
#include <iostream> 
#include <windows.h> 

using namespace std; 

int main(){
    float mant; 
    int por; 
    string stroka; 


    cin >> mant >> por >> stroka; 

    Chislo chis(mant, por, stroka); 
    cout << chis.getMant() << chis.getPor() << chis.getStroka() << endl; 
    Chislo chis2(chis); 
    cout << chis2.getMant() << chis2.getPor() << chis2.getStroka() << endl; 

    system("pause");
}