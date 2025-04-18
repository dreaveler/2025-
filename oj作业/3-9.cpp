#include <iostream>
using std::cout, std::endl;
class A {
public:
    int val;
    A(int x) : val(x) {}
    friend std::ostream& operator<<(std::ostream& os, const A& a) {
        return os << a.val;
    }
};
// 在此处补充你的代码
void f(int& x) {
    std::cout << "lvalue: " << x << std::endl;
} 
void f(int&& y) {
    std::cout << "rvalue: " << y << std::endl;
}
void f(double&& y) {
    std::cout << "rvalue: " << y << std::endl;
}
void f(A& a)
{
    std::cout << "lvalue: " << a << std::endl;
}
void f(A&& b) {
    std::cout << "rvalue: " << b << std::endl;
}

int main() {
    int x = 1;
    int* p = &x;
    int&& y = 2;
    A a(2);
    f(x);
    f(1);
    f(x + 0.5);
    f(x++);
    f(++x);
    f(*p);
    f(y);
    f(a);
    f(A(5));
    f(a.val);
    f(A(x));
    f(x = 5);
    f((x, 2));
    f((2, x));
}