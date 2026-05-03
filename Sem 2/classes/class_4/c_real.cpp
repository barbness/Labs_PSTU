#include "c_4.h"

Pair::Pair() : first(0), second(0) {}
Pair::Pair(int f, int s): first(f), second(s) {}
Pair::Pair(const Pair& other): first(other.first), second(other.second) {}

int Pair::firstGet() const {return first;} 
int Pair::secondGet() const {return second;}

void Pair::firstSet(int f){first = f;}
void Pair::secondSet(int s){second = s;}

Pair Pair::operator+(const Pair& other){ return Pair(this->first+other.first, this->second+other.second);};

Complex::Complex() : real_part(0), image_part(0) {}
Complex::Complex(int r, int i): real_part(r), image_part(i) {}
Complex::Complex(const Complex& other): real_part(other.real_part), image_part(other.image_part) {}

void Complex::setReal(int r) {real_part = r;}
void Complex::setImage(int i){image_part = i;}

int Complex::getReal() const {return real_part;}
int Complex::getImage() const {return image_part;}

Complex Complex::operator*(const Complex& other) {return Complex((this->real_part * other.real_part) - (this->image_part * other.image_part), (this->real_part * other.image_part) - (this->image_part * other.real_part));}
Complex Complex::operator-(const Complex& other) {return Complex(this->real_part - other.real_part, this->image_part - other.image_part);}