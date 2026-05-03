#include <string>
using namespace std;

class Chislo{
    float mant; 
    int por; 
    string stroka; 

    public:
    Chislo();
    Chislo(float m, int p, string s);
    Chislo(const Chislo& other);

    void setMant(float mant); 
    void setPor(int por); 
    void setStr(string stroka); 

    float getMant() const;
    int getPor() const;
    string getStroka() const;

    ~Chislo();
};