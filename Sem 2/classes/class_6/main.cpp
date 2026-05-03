#include <iostream>
#include "vector.h"

int main(){
    Vector v1(5); 
    std::cout << v1 << std::endl; 

    std::cout << "Введите 5 элементов массива v1: "<< std::endl;
    std::cin >> v1; 
    std::cout << v1 << std::endl;

    v1[0] = 100;
    std::cout << v1 << std::endl; 

    Vector v2(v1); 
    std::cout << v2() << std::endl;

    Vector v2 = v1*3;
    std::cout << v2 << std::endl; 

    Vector::Iterator left = v1.end() - 2;
    std::cout << *left << std::endl; 

    return 0;
}