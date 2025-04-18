#include <iostream>
// 在此处补充你的代码
template<typename...Ts>
void count(Ts...args) {
    std::cout<<sizeof...(args)<<std::endl;
}
int main() {
    count();
    count(false);
    count("hello", "world");
    count("do not", "dereference", nullptr);
    count(1, '+', 1LL, "=", 2.0);
}