#include <iostream>
using namespace std;

int fib(int n) {
	if (n <= 1) return 0;
	else if (n == 2) return 1;
	return fib(n - 2) + fib(n - 1);
}

int main() {
    int N;
	cout << "Введите номер числа Фибоначчи, которое вы хотите узнать:" << endl;
    cin >> N; 
    cout << "Число Фибоначчи с номером " << N << " = " << fib(N);
}