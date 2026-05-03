#include "vector.h"

Vector::Vector(int s, int k) {
    size = s;
    data = new int[size];

    for (int i = 0; i < size; i++) {
        data[i] = k;
    }
}
Vector::Vector(const Vector& other): size(other.size), data(other.data){}

Vector::~Vector(){delete[] data;}

Vector::Iterator::Iterator(int* p): ptr(p) {}
Vector::Iterator Vector::Iterator::operator-(int n) {return Vector::Iterator(ptr - n);}
int& Vector::Iterator::operator*() {return *ptr;}

int& Vector::operator[](int idx){return data[idx];}

Vector Vector::operator* (const int k){
    Vector result(size);

    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] * k;
    }

    return result;
}

int Vector::operator()(){return size;}

std::ostream& operator<<(std::ostream& out, const Vector& a) {
    for (int i = 0; i < a.size; i++) {
        out << a.data[i] << " ";
    }

    return out;
}

std::istream& operator>>(std::istream& in, Vector& a) {
    for (int i = 0; i < a.size; i++) {
        in >> a.data[i];
    }

    return in;
}

Vector::Iterator Vector::begin() {
    return Vector::Iterator(data);
}

Vector::Iterator Vector::end() {
    return Vector::Iterator(data + size);
}