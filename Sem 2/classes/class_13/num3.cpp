#include <iostream>
#include <map>
#include <algorithm>
#include "time.h"

using namespace std;

typedef multimap<int, Time> TMultiMap;

TMultiMap make_multimap(int n){
    TMultiMap m;
    Time t;
    int key;

    for (int i = 0; i < n; i++){
        cout << "Ddtlbnt rk.x^ ";
        cin >> key;

        cout << "Ddtlbnt dhtvz^ " << endl;
        cin >> t;

        m.insert(TMultiMap::value_type(key, t));
    }

    return m;
}

void print_multimap(const TMultiMap& m){
    TMultiMap::const_iterator i;

    for (i = m.begin(); i != m.end(); i++){
        cout << "key = " << i->first << "  value = " << i->second << endl;
    }
}

Time srednee(const TMultiMap& m){
    TMultiMap::const_iterator i;

    i = m.begin();

    Time sum = i->second;
    i++;

    for (; i != m.end(); i++){
        sum = sum + i->second;
    }

    return sum / m.size();
}

struct Compare_by_time
{
    bool operator()(const TMultiMap::value_type& a, const TMultiMap::value_type& b) const{
        return a.second < b.second;
    }
};

struct Equal_key{
    int key;

    Equal_key(int k){
        key = k;
    }

    bool operator()(const TMultiMap::value_type& elem) const{
        return elem.first == key;
    }
};

struct Add_srednee{
    Time sr;

    Add_srednee(const Time& t){ sr = t;}

    void operator()(TMultiMap::value_type& elem) const { elem.second = elem.second + sr;}
};

void add_max_to_end(TMultiMap& m){
    TMultiMap::iterator max_pos;

    max_pos = max_element(m.begin(), m.end(), Compare_by_time());

    cout << "Max element: " << max_pos->second << endl;

    int new_key;

    new_key = m.rbegin()->first + 1;

    m.insert(TMultiMap::value_type(new_key, max_pos->second));
}

void delete_by_key(TMultiMap& m, int key){
    TMultiMap::iterator pos;

    pos = find_if(m.begin(), m.end(), Equal_key(key));

    if (pos != m.end()){
        m.erase(pos);
        cout << "Element udalen" << endl;
    } else {
        cout << "Element ne nayden" << endl;
    }
}

void add_average_to_each(TMultiMap& m){
    Time sr;

    sr = srednee(m);

    cout << "Srednee arifmeticheskoe: " << sr << endl;

    for_each(m.begin(), m.end(), Add_srednee(sr));
}

int main(){
    int n;

    cout << "Введите длину контейнера: ";
    cin >> n;

    TMultiMap m;

    m = make_multimap(n);
    cout << "Associativnyy konteiner:";
    print_multimap(m);

    if (m.empty()){
        cout << "Konteiner pust!" << endl;
        return 0;
    }
    cout << endl;

    add_max_to_end(m);

    cout << "after 3:";
    print_multimap(m);
    cout << endl;

    int key;

    cout << "Введите ключ для удаления: ";
    cin >> key;

    delete_by_key(m, key);

    cout << "after 4:" << endl;
    print_multimap(m);

    if (m.empty()){
        cout << "Konteiner pust!" << endl;
        return 0;
    }
    cout << endl;

    add_average_to_each(m);

    cout << "after 5:" << endl;
    print_multimap(m);

    return 0;
}