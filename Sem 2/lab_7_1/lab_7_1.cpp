//вычитание для целых и комплексных чисел 
#include <iostream> 
using namespace std; 

int difr(int a, int b){
    return a-b; 
}
float difr(float a, float b){
    return a-b;
}
double difr(double a, double b){
    return a-b;
}

int main(){
    int a = 7, b = 4;
    cout << "Разность: " << difr(a, b) << endl; 

    float c = 6.4, d = 3.6;
    cout << "Разность: " << difr(c, d) << endl; 

    double e = 7.37896, f = 2.85496842;
    cout << "Разность: " << difr(e, f) << endl; 
}