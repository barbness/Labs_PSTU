#include <iostream> 
#include <string> 
using namespace std; 

struct Shift {
	char letter;
	int shift = 0;
};

/*
я не понимаю что не так. надо разобраться 

int BMSearch(string str, string substr) {
	int size = substr.size();
	Shift* tsh = new Shift[size];

	for (int i = 0; i < size-1; i++) {
		tsh[i].letter = substr[i];
		tsh[i].shift = size - 1 - i;
	}
	tsh[size - 1].letter = substr[size-1];
	tsh[size - 1].shift = size;
	
	int idx = 0;

	while (idx + size-1 < str.size()) {
		for (int i = size - 1; i >= 0; i--) {
			if (substr[i] == str[i+idx]) {
				if (i == 0) {
					delete[] tsh;
					return idx;
				}
			}
			else {
				for (int j = size-1; j >= 0 ; j--) {
					if (substr[i] == tsh[j].letter) {
						idx += tsh[j].shift;
						break;
					}
				}
				break;
			}
		}
	}

	delete[] tsh;
	return -1;
}
*/ 

int main() {
	string str, pattern; 

    cout << "Введите строку: "; 
    getline(cin, str);

    cout << "Введите подстроку: "; 
    getline(cin, pattern); 

	cout << "Индекс первого вхождения: " << BMSearch(str, pattern);
}