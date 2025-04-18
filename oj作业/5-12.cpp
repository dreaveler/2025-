#include <iostream>
#include <string>
// 在此处补充你的代码
template<typename...Ts>
void print(Ts...args) {
    if (sizeof...(args) == 0) {
        std::cout << std::endl;
        return;
    }
    print(args...);
}
template<typename T,typename...Ts>
void print(T t, Ts...args) {
    std::cout << t;
    print(args...);
}
int main() {
    std::string n("nullptr");
    print(false);
    print();
    print("hello", " world");
    print("do not ", "dereference ", n);
    print(1, '+', 1LL, "=", 2.0);
}