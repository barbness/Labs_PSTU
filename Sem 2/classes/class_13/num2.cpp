#include <iostream>
#include <queue>
#include <algorithm>
#include "time.h"

using namespace std;

typedef queue<Time> TQueue;
typedef TQueue::container_type TContainer;

TQueue make_queue(int n){
    TQueue q;
    Time t;

    for (int i = 0; i < n; i++){
        cin >> t;
        q.push(t);
    }

    return q;
}

void print_queue(TQueue q){
    while (!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}

TContainer queue_to_container(TQueue q)
{
    TContainer c;

    while (!q.empty()){
        c.push_back(q.front());
        q.pop();
    }

    return c;
}

TQueue container_to_queue(const TContainer& c){
    TQueue q;

    for (TContainer::const_iterator i = c.begin(); i != c.end(); i++){
        q.push(*i);
    }

    return q;
}

Time srednee(const TContainer& c){
    Time sum = c[0];

    for (int i = 1; i < c.size(); i++){
        sum = sum + c[i];
    }

    return sum / c.size();
}

struct Equal_s{
    Time key;

    Equal_s(const Time& t){
        key = t;
    }

    bool operator()(const Time& t) const{
        return t == key;
    }
};

struct Add_srednee{
    Time sr;

    Add_srednee(const Time& t){ sr = t;}

    void operator()(Time& t) const{ t = t + sr;}
};

void add_max_to_end(TQueue& q){
    TContainer c;

    c = queue_to_container(q);

    if (c.empty()){ return;}

    TContainer::iterator max_pos;

    max_pos = max_element(c.begin(), c.end());

    cout << "Max element: " << *max_pos << endl;

    c.push_back(*max_pos);

    q = container_to_queue(c);
}

void delete_by_key(TQueue& q, const Time& key){
    TContainer c;

    c = queue_to_container(q);

    TContainer::iterator pos;

    pos = find_if(c.begin(), c.end(), Equal_s(key));

    if (pos != c.end()){
        c.erase(pos);
        cout << "Element udalen" << endl;
    } else {
        cout << "Element ne nayden" << endl;
    }

    q = container_to_queue(c);
}

void add_average_to_each(TQueue& q){
    TContainer c;

    c = queue_to_container(q);

    if (c.empty()){ return;}

    Time sr;

    sr = srednee(c);

    cout << "Srednee arifmeticheskoe: " << sr << endl;

    for_each(c.begin(), c.end(), Add_srednee(sr));

    q = container_to_queue(c);
}

int main(){
    int n;

    cout << "Введите длину очереди: ";
    cin >> n;

    TQueue q;
    q = make_queue(n);

    cout << "Очередь:" << endl;
    print_queue(q);

    if (q.empty()){
        cout << "Очередь пуста!" << endl;
        return 0;
    }
    cout << endl;

    add_max_to_end(q);

    cout << "after 3:" << endl;
    print_queue(q);
    cout << endl; 

    Time key;

    cout << "Введите элемент для удаления:" << endl;
    cin >> key;
    delete_by_key(q, key);

    cout << "after 4:" << endl;
    print_queue(q);

    if (q.empty()){
        cout << "Очередь пуста!" << endl;
        return 0;
    }
    cout << endl;

    add_average_to_each(q);

    cout << "after 5:" << endl;
    print_queue(q);

    return 0;
}