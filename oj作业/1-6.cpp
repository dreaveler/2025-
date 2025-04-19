#include <iostream>
#include <cmath>

// ��ȫ funcs �Ķ���
// �ڴ˴�������Ĵ���
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