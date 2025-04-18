#include <iostream>

class Magic {
public:
    int value;
    // 在此处补充你的代码
    Magic():value(){}
    Magic(int x) :value(x) {}
    Magic(const Magic& m) :value(m.value+2) {}
};

void print(Magic o) {
    std::cout << o.value << std::endl;
}

int main() {
    Magic a(5);
    Magic b = a;
    print(b);

    Magic d;
    d = a;
    std::cout << d.value << std::endl;
    print(d);
}