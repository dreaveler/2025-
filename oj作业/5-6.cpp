#include <iostream>
#include <iomanip>
#include <cmath>

constexpr double DX = 1e-6;
// 在此处补充你的代码
template<typename T>
auto d(T t) {
    return [=](double x) {
        return (t(x + DX) - t(x)) / DX;
        };
}
int main() {
    auto f = [&](double x) { return x * x; };
    auto g = [=](double x) { return std::sin(x); };

    double x;
    std::cout << std::fixed << std::setprecision(2);
    while (std::cin >> x) {
        std::cout << d(f)(x) << ' ';
        std::cout << d(g)(x) << std::endl;
    }
}