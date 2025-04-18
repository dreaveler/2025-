#include <iostream>

struct Base {
    int value;

    void printBaseValue() {
        std::cout << value << std::endl;
    }
};

struct Derived : Base {
    int value;
};

void setBaseValue(Derived& d, int n) {
    // 在此处补充你的代码
    Base* dd = &d;
    dd->value = n;
}

int main() {
    int n;
    std::cin >> n;
    Derived d;
    setBaseValue(d, n);
    d.printBaseValue();
}