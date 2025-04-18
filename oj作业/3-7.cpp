#include <iostream>

struct Complex {
    double real;
    double imag;
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    return os << c.real << '+' << c.imag << 'i';
}
// 在此处补充你的代码
Complex operator""_i(unsigned long long x) {
    Complex c;
    c.real = 0;
    c.imag = x;
    return c;
}
Complex operator""_i(long double x) {
    Complex c;
    c.real = 0;
    c.imag = x;
    return c;
}


int main() {
    std::cout << 5_i << std::endl;
    std::cout << 3.14_i << std::endl;
}