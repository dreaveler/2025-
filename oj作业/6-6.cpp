#include <iostream>
// 在此处补充你的代码
class MyCin {
public:
    bool check;
    MyCin() :check{ true } {}
    MyCin& operator>>(int& n) {
        std::cin >> n;
        if (n == -1) {
            check = false;
            return *this;
        }
        return *this;
    }
    explicit operator bool() const {
        return check;
    }
};
//编译通过的原因是添加了类型转换后导致可能的隐式类型转换  然后右移运算符导致编译通过
int main() {
    MyCin m;
    int n1, n2;
    while (m >> n1 >> n2) {
        std::cout << n1 << " " << n2 << std::endl;
    }
    // m << n1; // 编译错误
}

// 检查你是否正确解决了“m << n1 会通过编译”这个问题
template<typename, typename>struct J :std::
true_type {
}; template<typename T>struct J<
    T, std::void_t<decltype(std::declval<int&
    >() = std::declval<T&>())>> :std::false_type
{}; static_assert(J<MyCin, void>::value);