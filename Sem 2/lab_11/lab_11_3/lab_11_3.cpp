#include <iostream> 
using namespace std; 

struct StElem {
    int data;
    StElem* next;
};

struct Stack{
    StElem* topNode; 
    int size; 

    void init(){
        topNode = nullptr; 
        size = 0;
    }

    void push(int data){ 
        StElem* cur = new StElem; 
        cur->data = data; 
        cur->next = topNode; 
        topNode = cur; 
        size++;
    }

    int pop(){
        if (size == 0) return -1;
        int value = topNode->data; 
        StElem* tmp = topNode; 
        topNode = topNode->next; 
        size--; 
        delete tmp; 
        return value;
    }

    void clear(){
        while (size >0) pop();
    }
    
    StElem* top() {return topNode;}
};

void createStack(Stack& s, int size){
    Stack tmp;
    tmp.init();

    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        tmp.push(x);
    }

    while (tmp.size > 0) {
        s.push(tmp.pop());
    }
}

void printStack(Stack& s) {
    Stack tmp;
    tmp.init();

    while (s.size > 0) {
        int x = s.pop();
        cout << x << " ";
        tmp.push(x);
    }
    cout << endl;

    while (tmp.size > 0) {
        s.push(tmp.pop());
    }
}

void del(Stack& s, int num) {
    if (num < 1 || num > s.size) cout << "Невозможно удалить элемент" << endl;

    Stack tmp;
    tmp.init();

    for (int i = 1; i < num; i++) {
        tmp.push(s.pop());
    }

    s.pop();

    while (tmp.size > 0) {
        s.push(tmp.pop());
    }
}

void pushnum(Stack& s, int num, int k){
    if (num < 1 || num > s.size) cout << "Невозможно добавить элемент" << endl;

    Stack tmp, added;
    tmp.init();
    added.init();

    for (int i = 1; i < num; i++) {
        tmp.push(s.pop());
    }

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        added.push(x);
    }

    while (added.size > 0) {
        s.push(added.pop());
    }

    while (tmp.size > 0) {
        s.push(tmp.pop());
    }

}
int main(){
    int N; 
    cout << "Введите длину стека: "; 
    cin >> N; 
    int K;
    int num;

    Stack s; 
    s.init(); 
    cout << "Введите элементы стека: " << endl;;
    createStack(s, N); 

    printStack(s);

    cout << "Введите номер элемента, который Вы хотите удалить: " << endl;
    cin >> K;
    del(s, K); 
    cout << "Введите количество элементов, которые вы хотите вставить: " << endl; 
    cin >> num; 
    cout << "Введите элементы " << endl;
    pushnum(s, K, num); 

    printStack(s);

    s.clear();
    return 0;
}