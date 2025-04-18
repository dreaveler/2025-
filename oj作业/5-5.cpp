#include <iostream>
#include <cmath>
// 在此处补充你的代码
class Printer {
public:
    template<typename T>
    Printer& operator()(const T& t) {
        std::cout << t;
        return *this;
    }
    void operator()() {
        std::cout << std::endl;
    }
};
int main() {
    Printer printer;

    int x, y;
    std::cin >> x >> y;

    printer("The sum of ")(x)(" and ")(y)(" is ")(x + y)('!')();

    double root = std::sqrt(x);
    printer("The square root of ")(x)(" is ")(root)('.')();
}