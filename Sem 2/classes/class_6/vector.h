#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector{
    public:
    class Iterator{
        private: 
        int* ptr; 
        public: 
        Iterator(int* p = nullptr);
        Iterator operator-(int n);     
        int& operator*();

    };
    Vector(int s, int k = 0);
    Vector(const Vector& other); 
    ~Vector(); 

    Vector& operator=(const Vector& a);
    int& operator[](int index);
    Vector operator* (const int k);
    int operator()();

    friend std::ostream& operator<<(std::ostream& out, const Vector& a);
    friend std::istream& operator>>(std::istream& in, Vector& a);

    Iterator begin();
    Iterator end();

    private: 
    int size; 
    int* data; 
};

#endif