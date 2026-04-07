#include <iostream> 
using namespace std; 

struct QueueElem {
    int data;
    QueueElem* next;
};

struct Queue{
    QueueElem* frontNode; 
    QueueElem* backNode; 
    int size; 

    void init(){
        frontNode = nullptr; 
        backNode = nullptr; 
        size = 0;
    }

    void push(int data){
        QueueElem* tmp = new QueueElem; 
        tmp->data = data; 
        tmp->next = nullptr; 

        if(size == 0){
            frontNode = tmp; 
            backNode = tmp;
        }
        else{
            backNode->next = tmp; 
            backNode = tmp; 
        }
        size++;
    }

    int pop(){
        if(size == 0)  return -1; 
        int value = frontNode->data; 
        QueueElem* tmp = frontNode; 
        if (size == 1){backNode = nullptr;}
        frontNode = frontNode->next; 
        size--;
        delete tmp; 
        return value; 
    }

    void clear(){
        while (size > 0){pop();}
    }

    QueueElem* front() {return frontNode;}
    QueueElem* back() {return backNode;}
};

Queue* create(int size){
    Queue* que = new Queue; 
    que->init();
    int data; 
    for (int i = 0; i < size; i++){
        cin >>data; 
        que->push(data); 
    }
    return que;
}

void print(Queue& q){
    Queue tmp; 
    tmp.init(); 

    while(q.size > 0){
        int x = q.pop(); 
        cout << x << " "; 
        tmp.push(x); 
    }
    cout << endl; 

    while (tmp.size > 0) {
        q.push(tmp.pop());
    }
}

void del(Queue& q, int idx){
    if (idx < 1 || idx > q.size) cout << "Невозможно удалить элемент" << endl;
    int s = q.size;
    Queue tmp; 
    tmp.init(); 

    for(int i = 0; i < s; i++){
        int x = q.pop(); 
        if(i == idx){
            continue; 
        }
        q.push(x); 
    }
}

void add(Queue& q, int num, int idx){
    if (idx < 1 || idx > q.size) cout << "Невозможно добавить элемент" << endl;;

    int s = q.size; 

    for (int i = 0; i < idx; i++){
        q.push(q.pop()); 
    }

    for(int i = 0; i < num; i++){
        int N; 
        cout << "Введите новый элемент: "; 
        cin >> N; 
        q.push(N); 
        cout << endl;
    }

    for (int i = 0; i < (s - idx); i++){
        q.push(q.pop());
    }
}

int main(){
    int N; 
    cout << "Введите длину очереди: "; 
    cin >> N; 
    cout << endl; 

    int idx, num; 

    cout << "Введите элементы очереди: "; 
    Queue* q = create(N); 

    print(*q); 

    cout << "Введите номер элемента, который Вы хотите удалить: " << endl;
    cin >> idx; 
    del(*q, idx); 

    cout << "Введите количество элементов, которые вы хотите вставить: " << endl;
    cin >> num; 
    add(*q, num, idx); 

    print(*q);
    q->clear();

    return 0;
}