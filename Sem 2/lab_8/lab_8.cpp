#include <iostream> 
#include <fstream> 
#include <string>
using namespace std; 

struct Human{
    string name; 
    string address; 
    string home_num; 
    int age; 
};

Human* RnW(const string& myfile, const string& newfile){
    string line;
    ifstream f1(myfile.c_str());
    ofstream f2(newfile.c_str());
    int start = 0; 

    if (!f1.is_open() || !f2.is_open()){
        return 0;
    }

    while(getline(f1, line)){
        f2 << line;
        for (int i = 0; i < line.length(); i++){
            if (line [i] == ','){ 
                for (int j = start; j < i; j++){
                    
                }
            } 
            
        }
    }

    f1.close(); 
    f2.close();
}

Human* Add(Human* human, int inx, int& size){
    string name, address, home_num; 
    int age;
    cout << "Введите имя человека: "; 
    getline(cin, name); 
    cout << "Введите адрес проживания: ";
    getline(cin, address);
    cout << "Введите домашний номер телефона: "; 
    getline(cin, home_num); 
    cout << "Введите его возраст: "; 
    cin >> age; 
    Human unknown = {name, address, home_num, age}; 
    cout << "" << endl; 

    Human* s = new Human[size + 1];
    for (int i = 0; i < size; i++){
        if (i < inx) {s[i] = human[i];}
        else if (i > inx){s[i+1] = human[i];}
        else {s[i] = unknown;}
    }
    size++; 
    delete[] human; 
    return s;
}

Human* Delete(Human* human, int age, int& size){
    Human* s = new Human[size - 1]; 
    int count = 0;
    for ( int i =0; i < size; i++){
        if (human[i].age == age){
            count++;
        }
    }
    int j = 0;
    for(int i =0; i < size; i++){
        if (human[i].age != age){
            s[j] = human[i]; 
            j++;
        }
    }
    
    delete[] human; 
    size--; 
    return s;
}

int main(){ 
    int human_count = 5; 
    Human* humans = new Human[human_count]; 
    RnW("test.txt", "test_2.txt");

   int del_age;
   int index; 

   cout << "Введите удаляемый возраст" << endl; 
   cin >> del_age; 
   Delete(humans, del_age, human_count);

   cout << "Введите номер, после которого хотите добавить человека" << endl;
   cin >> index; 
   Add(humans, index, human_count);

   return 0;
}