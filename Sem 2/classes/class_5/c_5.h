class Pair{
    int first; 
    int second; 

    public: 
    Pair();
    Pair(int f, int s); 
    Pair(const Pair& other);

    virtual ~Pair();

    int firstGet() const; 
    int secondGet() const; 

    void firstSet(int f);
    void secondSet(int s); 

    virtual Pair* operator+(const Pair& other) const = 0;
};

class Complex:public Pair{
    int real_part; 
    int image_part; 

public: 
    Complex();
    Complex(int r, int i); 
    Complex(const Complex& other);

    void setReal(int r);
    void setImage(int i); 

    int getReal() const;
    int getImage() const;

    Pair* operator+(const Pair& other) const override;
    Complex operator*(const Complex& other); 
    Complex operator-(const Complex& other);
};