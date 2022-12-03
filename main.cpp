#include <iostream>
using namespace std;

#include "ClassFactory.h"
using namespace reflect;

#include "A.h"

int main() {
    Object *a = Singleton<ClassFactory>::instance()->create_class("A");
    string name;
    a->get("m_name", name);
    cout << "default name: " << name << endl;
    a->set("m_name", "hello world");
    a->get("m_name", name);
    cout << "set name: " << name << endl;

    int age;
    a->get("m_age", age);
    cout << "default age: " << age << endl;
    a->set("m_age", 18);
    a->get("m_age", age);
    cout << "set age: " << age << endl;

    a->call("f1");
    int num = a->call<int>("f2", 100);
}