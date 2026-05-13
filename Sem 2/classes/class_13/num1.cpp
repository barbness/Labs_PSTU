#include <iostream>
#include <deque>
#include <algorithm>
#include "time.h"

using namespace std;

typedef deque<Time> TDeque;

TDeque make_deque(int n){
    TDeque d;
    Time t;

    for (int i = 0; i < n; i++){
        cin >> t;
        d.push_back(t);
    }

    return d;
}

void print_deque(const TDeque& d){
    for (int i = 0; i < d.size(); i++){
        cout << d[i] << endl;
    }
}

Time srednee(const TDeque& d){
    Time sum = d[0];

    for (int i = 1; i < d.size(); i++){
        sum = sum + d[i];
    }

    return sum / d.size();
}

struct Equal_s{
    Time key;

    Equal_s(const Time& t){ key = t;}

    bool operator()(const Time& t) const{ return t == key;}
};

struct Add_srednee{
    Time sr;

    Add_srednee(const Time& t){ sr = t;}

    void operator()(Time& t) const{ t = t + sr;}
};

void add_max_to_end(TDeque& d){
    TDeque::iterator max_pos;

    max_pos = max_element(d.begin(), d.end());

    cout << "Max element: " << *max_pos << endl;

    d.push_back(*max_pos);
}

void delete_by_key(TDeque& d, const Time& key)
{
    TDeque::iterator pos;

    pos = find_if(d.begin(), d.end(), Equal_s(key));

    if (pos != d.end()){
        d.erase(pos);
        cout << "Element udalen" << endl;
    } else {
        cout << "Element ne nayden" << endl;
    }
}

void add_average_to_each(TDeque& d){
    Time sr;

    sr = srednee(d);

    cout << "Srednee arifmeticheskoe: " << sr << endl;

    for_each(d.begin(), d.end(), Add_srednee(sr));
}

int main(){
    int n;

    cout << "Введите длину контейнера: ";
    cin >> n;

    TDeque d;

    d = make_deque(n);

    cout << "Konteiner:" << endl;
    print_deque(d);

    if (d.empty()){
        cout << "Konteiner pust!" << endl;
        return 0;
    }
    cout << endl;

    add_max_to_end(d);

    cout << "after 3:" << endl;
    print_deque(d);
    cout << endl;

    Time key;

    cout << "Введите элемент для удаления: " << endl;
    cin >> key;

    delete_by_key(d, key);
    print_deque(d);

    if (d.empty()){
        cout << "Konteiner pust!" << endl;
        return 0;
    }
    cout << endl; 
    
    add_average_to_each(d);
    cout << "after 5:" << endl;
    print_deque(d);

    return 0;
}