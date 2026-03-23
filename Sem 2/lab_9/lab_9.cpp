#include <iostream> 
#include <fstream> 
#include <string>
using namespace std; 

void creating(const string& filename, int N){
    ofstream f1(filename, ios::out | ios::trunc); 
    if (!f1.is_open()){
        return;
    }

    for (int i = 1; i <= N; i++){
        f1 << "String number " << i << endl; 
    }

    f1.close();
}
void copying(const string& F1, const string& F2){ 
    ifstream f1(F1.c_str());
    ofstream f2(F2.c_str());

    if (!f1.is_open() || !f2.is_open()){
        return;
    }

    string line; 
    int LineNum = 0;

    while(getline(f1, line)){
        LineNum ++; 
        if (LineNum >= 4){
            f2 << line; 
        }
    }

    f1.close(); 
    f2.close();
}

int lastword(const string& filename){
    ifstream f(filename.c_str());

    if (!f.is_open()){
        return -1;
    } 

    string line;
    int lastLength = 0;

    while (getline(f, line)){
        int i = (int)line.length() - 1;

        while (i >= 0 && (line[i] == ' ' || line[i] == '\t')){
            i--;
        }

        int curLength = 0;
        while (i >= 0 && line[i] != ' ' && line[i] != '\t'){
            curLength++;
            i--;
        }

        if (curLength > 0){
            lastLength = curLength;
        }
    }

    f.close();
    return lastLength;
}
int main(){
    int N;
    cout << "Введите количество строк в файле" << endl;
    cin >> N;

    creating("F1.txt", N);
    copying("F1.txt", "F2.txt");

    int len = lastword("F2.txt");
    
    cout << "Длина последнего слова: " << len << endl; 
    return 0;
}