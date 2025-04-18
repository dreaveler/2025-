#include <iostream>

template <typename T>
struct IsInt {
    constexpr static bool value{ false };
};
// 在此处补充你的代码
template<>
struct IsInt<int> {
    constexpr static bool value{ true };
};
int main() {
    IsInt<int> obj1;
    IsInt<double> obj2;
    std::cout << std::boolalpha << obj1.value << " " << obj2.value << std::endl;

    using AlsoInt = int;
    std::cout << IsInt<AlsoInt>::value << " " << IsInt<bool>::value << std::endl;
}