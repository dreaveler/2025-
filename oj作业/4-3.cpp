#include <iostream>

class Base {
    // 在此处补充你的代码
public:
    void f() const {
        std::cout << "Base::f" << std::endl;
    }
    virtual void g()const {
        std::cout << "Base::g" << std::endl;
    }
};

class Derived : public Base {
public:
    void f() const {
        std::cout << "Derived::f" << std::endl;
    }
    void g() const {
        std::cout << "Derived::g" << std::endl;
    }
};

int main() {
    Base* ptr1 = new Base{};
    ptr1->f();
    ptr1->g();
    delete ptr1;

    Base* ptr2 = new Derived{};
    ptr2->f();
    ptr2->g();
    delete ptr2;

    auto obj3 = Derived{};
    obj3.f();
    obj3.g();
}