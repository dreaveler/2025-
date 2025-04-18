#include <iostream>
#include <cmath>
// 在此处补充你的代码
class Printer {
public:
    Printer() = default;
    Printer& operator() (const int& a){
        std::cout << a;
        return *this;
    }
    Printer& operator()(const double& b){
        std::cout << b;
        return *this;
    }
    Printer& operator()(const char& c) {
        std::cout << c;
        return *this;
    }
    Printer& operator()(const char* str) {
        std::cout << str;
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