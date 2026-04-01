#include <iostream>
using namespace std; 

struct ListElem{
    int data;
    ListElem* next;
    ListElem* prev;
};

ListElem* createList(int n){

    if (n <= 0) return nullptr;

    ListElem* start = new ListElem;
    cout << "Введите первый элемент списка: ";
    cin >> start->data;
    start->next = nullptr;
    start->prev = nullptr;

    ListElem* previ = start; 
    ListElem* cur = nullptr; 

    for (int i = 1; i < n; i++){
        cur = new ListElem; 
        cout << "Введите " << i + 1 << " элемент:"; 
        cin >> cur->data; 
        cur->next = nullptr; 

        cur->prev = previ; 
        previ->next = cur; 

        previ = cur;
    }

    return start;
}

void printList(ListElem* start) {
    if (start == nullptr) {
        cout << "Список пуст" << endl;
        return;
    }

    ListElem* cur = start;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void pop(ListElem*& start, int num){
    if (start == nullptr || num <= 0){
        cout << "Удаление невозможно!";
        return;
    } 

    if (num == 1) {
        ListElem* tmp = start;
        start = start->next;
        delete tmp;
    }

    ListElem* del = start;

    for (int i = 0; i < num - 1 && del != nullptr; i++) {
        del = del->next;
    }

    if (del == nullptr) {
        cout << "Удаление невозможно!";
        return;
    }

    if (del->prev != nullptr) {
        del->prev->next = del->next;
    } else {
        start = del->next;
    }

    if (del->next != nullptr) {
        del->next->prev = del->prev;
    }

    delete del;
}

void push(ListElem*& start, int number, int count){
    if (number <= 0 || count <= 0){
    cout << "Добавление невозможно!";
    return;
    }

    ListElem* firstNew = nullptr;
    ListElem* lastNew = nullptr;

    for (int i = 0; i < count; i++){
        ListElem* cur = new ListElem;
        cout << "Введите новый элемент " << i + 1 << ": ";
        cin >> cur->data;
        cur->next = nullptr;

        if (firstNew == nullptr) {
            firstNew = cur;
            lastNew = cur;
        } else {
            lastNew->next = cur;
            lastNew = cur;
        }
    }

    if (number == 1) {
        firstNew->prev = nullptr;
        lastNew->next = start;

        if (start != nullptr) {
            start->prev = lastNew;
        }

        start = firstNew;
        return;
    }

    ListElem* prev = start;
    for (int i = 1; i < number - 1 && prev != nullptr; i++){
        prev = prev->next;
    }

    if (prev == nullptr){
        cout << "Добавление невозможно!";
        return;
    }

    ListElem* nextElem = prev->next;
    
    prev->next = firstNew;
    firstNew->prev = prev;
    lastNew->next = nextElem;

    if (nextElem != nullptr) {
        nextElem->prev = lastNew;
    }
}

int main(){
    int N; 
    cout << "Введите длину списка: "; 
    cin >> N; 
    int K;
    int num;

    ListElem* cr = createList(N); 
    printList(cr); 

    cout << "Введите номер элемента, который Вы хотите удалить: " << endl;
    cin >> K;
    pop(cr, K); 
    cout << "Введите количество элементов, которые вы хотите вставить: " << endl; 
    cin >> num; 
    push(cr, K, num); 

    printList(cr); 
}