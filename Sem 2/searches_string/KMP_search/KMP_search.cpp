#include <iostream> 
#include <string> 
using namespace std; 

struct shift{
	char letter;
	int shift = 0;
};

string createPrefix(string str, int len){
	string prefix = "";

	for (int i = 0; i < len; i++) {
		prefix += str[i];
	}

	return prefix;
}

string createSuffix(string str, int len, int end_str){
	string suffix = "";
    int st = end_str; 

	for (int i = 0; i < len; i++) {
		suffix = str[st] + suffix;
        st--; 
	}

	return suffix;
}

int KMPSearch(string str, string pattern) {
	int size = pattern.size();

    if (size == 0) return 0;
    if (size > str.size()) return -1;

	string prefix;
	string suffix;

	shift* hops = new shift[size];
	int idx;

	for (int i = 0; i < size; i++) {
	    int best = 0;
        for (int j = i; j >= 1; j--) {
            prefix = createPrefix(pattern, j);
            suffix = createSuffix(pattern, j, i);

            if (prefix == suffix) {
                best = j;
                break;
            }
        }
        hops[i].shift = best;
        hops[i].letter = pattern[i];
    }

	int i = 0;
    int j = 0;

    while (i < str.size()) {
        if (str[i] == pattern[j]) {
            i++;
            j++;

            if (j == size) {
                delete[] hops;
                return i - j;
            }
        }
        else {
            if (j != 0) {
                j = hops[j - 1].shift;
            }
            else {
                i++;
            }
        }
    }

    delete[] hops;
	return -1;
}

int main() {
	string str, pattern; 

    cout << "Введите строку: "; 
    getline(cin, str);

    cout << "Введите подстроку: "; 
    getline(cin, pattern); 

	cout << "Индекс первого вхождения: " << KMPSearch(str, pattern);
}