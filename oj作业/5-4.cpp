#include <iostream>
// �ڴ˴�������Ĵ���
template<typename T>
void call3(T t){
    t();
    t();
    t();
}
void f1() {
    int x = 0;
    std::cout << ++x << std::endl;
}
void f2() {
    static int x = 0;
    std::cout << ++x << std::endl;
}
struct F34 {
    int x{ 0 };
    void operator()() {
        std::cout << ++x << std::endl;
    }
};
F34 f3, f4;
int main() {
    int v = 42;
    auto f5 = [&]() {
        std::cout << ++v << std::endl;
        };
    call3(f1);
    call3(f2);
    call3(f3);
    call3(f4);
    call3(f5);
}