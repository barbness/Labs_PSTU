#pragma once
#include "Object.h"

class Vector {
protected:
    Object** data;
    int size;
    int capacity;

public:
    Vector();
    Vector(int n);
    virtual ~Vector();

    void Make(int n);
    void Add(Object* obj);
    void Delete();
    void Show() const;
    void ShowName(int k) const;
    void Clear();

    int GetSize() const;
    int GetCapacity() const;
};