#include <iostream> 

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
    Vector();

    Vector(int s, T k = T());
    Vector(const Vector<T>& other);
    ~Vector();

    T& operator[](int index);
    Vector<T> operator*(const int k);
    int operator()();
    Vector<T>& operator=(const Vector<T>& other);
    Vector<T> operator+(const Vector<T>& other);
    Vector<T> operator/(const int k);
    Vector<T> operator/(const Vector<T>& other);
    bool operator<(const Vector<T>& other);

    friend std::ostream& operator<< <T>(std::ostream& out, const Vector<T>& a);
    friend std::istream& operator>> <T>(std::istream& in, Vector<T>& a);
};

template <typename T>
Vector<T>::Vector(): size(0), data(0) {}

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
            data = 0;
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
T& Vector<T>::operator[](int index) {return data[index];}

template <typename T>
Vector<T> Vector<T>::operator*(const int k) {
    Vector<T> result(size);

    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] * k;
    }

    return result;
}

template <typename T>
int Vector<T>::operator()() {return size;}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) {
    Vector<T> result(size);
    int n = size;

    if (other.size < n) {
        n = other.size;
    }

    for (int i = 0; i < size; i++) {
        result.data[i] = data[i];
    }

    for (int i = 0; i < n; i++) {
        result.data[i] = data[i] + other.data[i];
    }

    return result;
}

template <typename T>
Vector<T> Vector<T>::operator/(const int k) {
    Vector<T> result(size);

    if (k == 0) {
        std::cout << "Delit na 0 nelzya" << std::endl;
        return result;
    }

    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] / k;
    }

    return result;
}

template <typename T>
Vector<T> Vector<T>::operator/(const Vector<T>& other) {
    Vector<T> result(size);
    int n = size;

    if (other.size < n) {
        n = other.size;
    }

    for (int i = 0; i < size; i++) {
        result.data[i] = data[i];
    }

    for (int i = 0; i < n; i++) {
        if (other.data[i] == T()) {
            result.data[i] = T();
        }
        else {
            result.data[i] = data[i] / other.data[i];
        }
    }

    return result;
}

template <typename T>
bool Vector<T>::operator<(const Vector<T>& other) {
    T s1 = T();
    T s2 = T();

    for (int i = 0; i < size; i++) {
        s1 = s1 + data[i];
    }

    for (int i = 0; i < other.size; i++) {
        s2 = s2 + other.data[i];
    }

    return s1 < s2;
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

template <typename T>
bool is_zero(Vector<T> v) {
    for (int i = 0; i < v(); i++) {
        if (v[i] == T()) {
            return true;
        }
    }

    return false;
}

