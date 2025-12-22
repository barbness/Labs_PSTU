//f(x) = 0,25x**3 + x - 1,2502 na otr [0; 2], tochnost E = 0, 000001 
//f'(x) = 
#include <iostream> 
#include <cmath> 
using namespace std;
int main(){ 
     float a, b, c; 
     float fA, fB, fC; 
     double eps = 0.000001; 
     a = 0; 
     b = 2;
     while (b-a > eps){
         c = (a + b) / 2;
         fA = 0.25 * pow(a, 3) + a -1.2502;
         fB = 0.25 * pow(b, 3) + b -1.2502;
         fC = 0.25 * pow(c, 3) + c -1.2502;
         if (fA * fC < 0){ b = c; }
         else if (fC * fB < 0) { a = c; }
         else {
            cout << "Упс!" << endl;
            break;
        }
     } 
     cout << "Корни: " << a << "; " << b << endl;
     return 0; 
 } 
 // 1.00011; 1.00011