#ifndef _A_H_
#define _A_H_

#include <iostream>
#include <string>
using namespace std;

#include "ClassRegister.h"
using namespace reflect;

class A : public Object {
public:
    A() :
        m_name(""), m_age(0) {}
    void f1() {
        cout << "f1" << endl;
    }
    int f2(int a) {
        cout << "f2" << endl;
        return a;
    }

public:
    string m_name;
    int m_age;
};

REGISTER_CLASS(A);
REGISTER_CLASS_FIELD(A, m_name, string);
REGISTER_CLASS_FIELD(A, m_age, int);
REGISTER_CLASS_METHOD(A, f1, void);
REGISTER_CLASS_METHOD(A, f2, int, int);

#endif // _A_H_