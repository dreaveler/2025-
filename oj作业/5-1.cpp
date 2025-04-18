#include <iostream>
// 在此处补充你的代码
using std::cout;
using std::endl;
template<typename T>
void print(const T& t) {
    cout << t << endl;
}
// 一个不允许复制的类
struct MyStruct {
    MyStruct() = default;
    MyStruct(const MyStruct&) = delete;
    MyStruct& operator=(const MyStruct&) = delete;
};
std::ostream& operator<<(std::ostream& os, const MyStruct& s) {
    return os << "MyStruct";
}

int main() {
    print(42);
    print(3.14);
    print('@');
    print("Hello, world");

    MyStruct s;
    print(s);
}