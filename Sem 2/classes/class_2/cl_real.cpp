#include <string> 
#include "cl_ch.h" 

Chislo::Chislo() : mant(0), por(0), stroka("") {}; 
Chislo::Chislo(float m, int p, string s) : mant(m), por(p), stroka(s) {};
Chislo::Chislo(const Chislo& other) : mant(other.mant), por(other.por), stroka(other.stroka) {}; 

Chislo::~Chislo() {}

void Chislo::setMant(float m){ mant = m; }
void Chislo::setPor(int p){por = p; }
void Chislo::setStr(string str) {stroka = str;}

float Chislo::getMant() const { return mant;}
int Chislo::getPor() const { return por;}
string Chislo::getStroka() const {return stroka;}