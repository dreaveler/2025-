#include <iostream>
#include <cmath>

int main() {
    auto compose = [](double (*g)(double), double (*f)(double)) {
        // �ڴ˴�������Ĵ���
        return [=](double x) {
            return g(f(x));
            };
        };
    double x;
    std::cin >> x;
    auto id = compose(std::asin, std::sin);
    std::cout << std::fixed << id(x) << std::endl;
}