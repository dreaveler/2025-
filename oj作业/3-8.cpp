#include <cmath>
#include <iostream>
// 在此处补充你的代码
class Complex {
    double real{ 0 };
    double imag{ 0 };
public:
    Complex() = default;
    Complex(int a, int b) :real(a), imag(b) {}
    Complex(int x) :real(x) {}
    Complex(double x) :real(x) {}
    friend std::ostream& operator<<(std::ostream& os,const Complex& c);
    friend std::istream& operator>>(std::istream& is,Complex& c);
    Complex& operator=(const Complex& c) {
        if (this == &c) return *this;
        real = c.real;
        imag = c.imag;
        return *this;
    };
    friend Complex operator+(const Complex& a, const Complex& b) {
        Complex c;
        c.real = a.real + b.real;
        c.imag = a.imag + b.imag;
        return c;
    };
    friend Complex operator-(const Complex& a, const Complex& b) {
        Complex c;
        c.real = a.real - b.real;
        c.imag = a.imag - b.imag;
        return c;
    };
    friend Complex operator*(const Complex& a, const Complex& b) {
        Complex c;
        c.real = a.real * b.real - a.imag * b.imag;
        c.imag = a.real * b.imag + a.imag * b.real;
        return c;
    };
    friend Complex operator/(const Complex& a, const Complex& b) {
        Complex c;
        c.real = (a.real * b.real + a.imag * b.imag) / (b.real * b.real + b.imag * b.imag);
        c.imag = (a.imag * b.real - a.real * b.imag) / (b.real * b.real + b.imag * b.imag);
        return c;
    };
    friend double abs(Complex c);
};
std::ostream& operator<<(std::ostream& os,const Complex& c) {
    os << c.real << "+" << c.imag << "i";
    return os;
}
std::istream& operator>>(std::istream& is, Complex& c) {
    char plus, i;
    is >> c.real >>plus>> c.imag>>i;
    return is;
}
Complex operator""_i(unsigned long long x) {
    Complex c(0,x);
    return c;
}
double abs(Complex c) {
    return std::sqrt(c.real * c.real + c.imag * c.imag);
}


int main() {
    std::cout << 3.0 - 5_i << std::endl;

    Complex a, b= 0;
    int n = 42;
    double x = 3.14;

    std::cin >> a >> b;
    std::cout << a + b << std::endl;
    std::cout << a - b << std::endl;
    std::cout << a * b << std::endl;
    std::cout << a / b << std::endl;

    std::cout << n - a << std::endl;
    std::cout << x - a << std::endl;
    std::cout << n / a << std::endl;
    std::cout << x / a << std::endl;
    std::cout << n * a << std::endl;
    std::cout << x * a << std::endl;


    using std::abs;
    auto r = 1 + 1_i;
    auto deg45 = r / abs(r);
    std::cout << a * deg45 * deg45 << std::endl;
}