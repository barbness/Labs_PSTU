#include <iostream>
#include <cmath> 
using namespace std; 

double f(double x){
    return x * atan(x) - log(sqrt(1 + x * x));
}

double tmp(double x, int n) {
    return pow(-1.0, n + 1) * pow(x, 2 * n) / (2.0 * n * (2.0 * n - 1));
}

double chetN(double x, int n, int i) {
    if (n > i) {
        return 0.0;
    }
    return tmp(x, n) + chetN(x, n + 1, n);
}

double chetEps(double x, int n, double eps) {
    double current = tmp(x, n);

    if (fabs(current) < eps) {
        return current;
    }

    return current + chetEps(x, n + 1, eps);
}

void calculate(double x, double b, double i, int n, double eps) {
    if (x > b + 1e-9) {
        return;
    }

    double y = f(x);
    double sN = chetN(x, 1, n);
    double sE = chetEps(x, 1, eps);

    cout << "x = " << x << endl;
    cout << "SN = " << sN << endl;
    cout << "SE " << sE << endl;
    cout << "Y = " << y << endl;

    calculate(x + i, b, i, n, eps);
}

int main(){
    double a, b;
    int n;
    double eps = 0.0001;
    
    cout << "Enter a and b: ";
    cin >> a >> b;

    cout << "Enter n: ";
    cin >> n;

    double i = (b - a) / 10;
    
    calculate(a, b, i, n, eps);

    return 0;
}