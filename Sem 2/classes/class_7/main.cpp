#include <iostream>
#include "c_7.h"

int main(){
    Time t1(3, 50);
    Time t2(4, 35); 
    Time t3(2, 40); 
    Time t4(6, 21); 

    int n = 8, m = 9, k = 4, g = 3; 
    double x = 5.67, y = 4.32, z = 0.56, w = 1.67;

    Vector<Time> v1(2), v2(2);
    v1[0] = t1, 
    v1[1] = t2; 
    v2[0] = t3; 
    v2[1] = t4; 

    std::cout << v1 << "; " << v2 << std::endl; 

    Vector<int> v3(2), v4(2); 
    v3[0] = n;
    v3[1] = m;
    v4[0] = k; 
    v4[1] = g; 

    std::cout << v3 << "; " << v4 << std::endl; 

    Vector<double> v5(2), v6(2); 
    v5[0] = x; 
    v5[1] = y;
    v6[0] = z; 
    v6[1] = w; 

    std::cout << v5 << "; " << v6 << std::endl;

    return 0;
}