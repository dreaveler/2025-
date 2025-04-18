#include <iostream>
#include <cmath>

// 补全 funcs 的定义
// 在此处补充你的代码
using FucPtr = double(*)(double);
FucPtr funcs[] = {
    [](double x) {return -x; },
    [](double x) {return x * x; },
    [](double x) {return std::sqrt(x); },
    [](double x) {return std::log10(x); },
    [](double x) {return std::sin(x); }
};

int main() {
    double src;
    int n;
    std::cin >> src >> n;
    for (int i = 0; i < n; i++) {
        int op;
        std::cin >> op;
        src = funcs[op](src);
    }
    std::cout << std::fixed << src << std::endl;
}