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
    // �ڴ˴�������Ĵ���
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