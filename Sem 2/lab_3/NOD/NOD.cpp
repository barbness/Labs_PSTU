#include <iostream>
using namespace std;

int NOD(int a, int b) {
	if (a == b) return a;
	if (a > b){
        return NOD(a - b, b);
    }
	return NOD(a, b - a);
}

int main() {
    int a, b;
	cout << "Введите числа, НОД которых хотите посчитать:" << endl;
    cin >> a >> b;
    cout << "НОД(" << a << ", " << b << ") = " << NOD(a,b);
}