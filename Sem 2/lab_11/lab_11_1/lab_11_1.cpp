#include <iostream> 
using namespace std; 

struct ListElem {
    int data;
    ListElem* next;
};

ListElem* createList(int n){
    if (n <= 0) return nullptr; 
    ListElem* start = new ListElem; 

    cout << "Введите первый элемент списка" << endl; 
    cin >> start->data; 

    start->next = nullptr; 

    ListElem* cur = nullptr; 
    ListElem* prev = start;
    for (int i = 1; i < n; i++){
        cur = new ListElem; 
        cout << "Введите " << i + 1 << " элемент списка: "; 
        cin >> cur->data; 
        cur->next = nullptr; 

        prev->next = cur;
        prev = cur;
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

void pop(ListElem*& start, int number){
    if (start == nullptr || number <= 0) cout << "Удаление невозможно!";

    if (number == 1) {
        ListElem* tmp = start;
        start = start->next;
        delete tmp;
    }

    ListElem* prev = start;
    for (int i = 1; i < number - 1 && prev != nullptr; i++) {
        prev = prev->next;
    }

    if (prev == nullptr || prev->next == nullptr) {
        cout << "Удаление невозможно!";
    }

    ListElem* del = prev->next;
    prev->next = del->next;
    delete del;
}

void push(ListElem*& start, int number, int count){
    if (number <= 0 || count <= 0) cout << "Добавление невозможно!";

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

    if (number == 1){
        lastNew->next = start;
        start = firstNew;
    }

    ListElem* prev = start;
    for (int i = 1; i < number - 1 && prev != nullptr; i++){
        prev = prev->next;
    }

    if (prev == nullptr){
        cout << "Добавление невозможно!";
    }

    lastNew->next = prev->next;
    prev->next = firstNew;
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