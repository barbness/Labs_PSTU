#include <iostream>
#include <cstdarg>
using namespace std;

int sum(int count, ...)
{
    va_list args;              
    va_start(args, count);     

    int result = 0;            

    for (int i = 0; i < count; i += 2)   
    {
        int a = va_arg(args, int);       
        int b = va_arg(args, int);       
        result += a * b;                 
    }

    va_end(args);              

    return result;             
}

int main()
{
    cout << "sum(8):  " << sum(8, 1, 2, 3, 4, 5, 6, 7, 8) << endl;

    cout << "sum(10): " << sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;

    cout << "sum(12): " << sum(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) << endl;

    return 0;
}