#include <iostream>
#include <map>
#include "time.h"
using namespace std;

typedef map<int, Time> TMap; 
typedef TMap::iterator it;  


TMap make_map(int n){
    TMap m; 
    Time a;
    cout << "Введите элементы: " << endl; 

    for (int i = 0; i < n; i++){
        cin >> a;

        m.insert(make_pair(i, a));
    }

    return m;
}

void print_map(TMap m){
    it i = m.begin();

    while (i != m.end()){
        cout << (*i).first << " : " << (*i).second << endl;
        i++;
    }
}

int Max(TMap v){
    it i = v.begin();       
    int nom = 0;
    Time m = (*i).second;    

    while (i != v.end()){
        if (m < (*i).second){
            m = (*i).second;
            nom = (*i).first;
        }

        i++; 
    }
    return nom;
}

void AddMax(TMap &v){
    int max = Max(v);

    cout << "max = " << v[max] << " nom = " << max << endl;

    v.insert(make_pair(v.size(), v[max]));
}

void DeleteKey(TMap &v){
    int k;

    cout << "Введите ключ для удаления: ";
    cin >> k;

    it i = v.find(k);

    if (i != v.end()){ v.erase(i);} 
    else {cout << "Element not found" << endl;}
}

Time Srednee(TMap v){
    it i = v.begin();
    Time s = (*i).second;
    i++;

    while (i != v.end()){
        s = s + (*i).second;
        i++;
    }

    int n = v.size();

    return s / n;
}

void AddSrednee(TMap &v){
    Time sr = Srednee(v);

    cout << "srednee = " << sr << endl;

    it i = v.begin();

    while (i != v.end()){
        (*i).second = (*i).second + sr;
        i++;
    }
}

int main(){
    int n;

    cout << "Введите количество элементов: ";
    cin >> n;

    TMap m = make_map(n);
    cout << endl; 

    cout << "Map:" << endl;
    print_map(m);

    AddMax(m);
    print_map(m);
    cout << endl; 

    DeleteKey(m);
    print_map(m);
    cout << endl; 
    
    AddSrednee(m);
    print_map(m);

    return 0;
}