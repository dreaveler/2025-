#include <iostream>

class Base {
public:
    int baseValue;
    Base(int value) : baseValue{ value } {}
};

class Derived : public Base {
    int derivedValue;

public:
    // 在此处补充你的代码
    Derived() : Base(3378), derivedValue(45818) {}
    Derived(int a) : Base(a), derivedValue(a) {}
    //
    void print() {
        std::cout << baseValue << ' ' << derivedValue << std::endl;
    }
};

int main() {
    Derived a;
    a.print();

    int n;
    std::cin >> n;
    a = n;
    a.print();
}