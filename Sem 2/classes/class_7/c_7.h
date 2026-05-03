#include <iostream>

class Time{
    int mins;
    int secs;

    public:
    Time(); 
    Time(int m, int s); 
    Time(const Time& other);

    void setMins(int m); 
    void setSec(int s); 

    int getMins(); 
    int getSecs(); 

    friend std::ostream& operator<<(std::ostream& out, const Time& a);
};

template <typename T>
class Vector;

template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& a);

template <typename T>
std::istream& operator>>(std::istream& in, Vector<T>& a);

template <typename T>
class Vector {
private:
    int size;
    T* data;

public:
    Vector(int s, T k = T());
    Vector(const Vector<T>& other);
    ~Vector();

    Vector<T>& operator=(const Vector<T>& a);

    T& operator[](int index);
    Vector<T> operator*(const int k);
    int operator()();
    Vector<T>& operator=(const Vector<T>& other);

    friend std::ostream& operator<< <T>(std::ostream& out, const Vector<T>& a);
    friend std::istream& operator>> <T>(std::istream& in, Vector<T>& a);
};

template <typename T>
Vector<T>::Vector(int s, T k) {
    size = s;
    data = new T[size];

    for (int i = 0; i < size; i++) {
        data[i] = k;
    }
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other) {
    size = other.size;
    data = new T[size];

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other) {
        delete[] data;

        size = other.size;

        if (size == 0) {
            data = nullptr;
        }
        else {
            data = new T[size];

            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
    }

    return *this;
}

template <typename T>
T& Vector<T>::operator[](int index) {
    return data[index];
}

template <typename T>
Vector<T> Vector<T>::operator*(const int k) {
    Vector<T> result(size);

    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] * k;
    }

    return result;
}

template <typename T>
int Vector<T>::operator()() {
    return size;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& a) {
    for (int i = 0; i < a.size; i++) {
        out << a.data[i] << " ";
    }

    return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, Vector<T>& a) {
    for (int i = 0; i < a.size; i++) {
        in >> a.data[i];
    }

    return in;
}
