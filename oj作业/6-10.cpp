#include <iostream>
#include <string>
// �ڴ˴�������Ĵ���
template<typename...Ts>
auto sum(Ts...args) {
    return (... + args);
}
template<typename...Ts>
auto sumOfSquare(Ts...args) {
    return (... + (args * args));
}
template<int...Ns>
class Sum{
public:
    static constexpr int value = (... + Ns);
};
int main() {
    std::cout << sum(6, 6, 6) << std::endl;
    std::cout << Sum<1, 2, 3, 4, 5>::value << std::endl;
    std::cout << sum(1, 4, 2, 8, 5, 7) << std::endl;
    std::cout << Sum<4, 3, 9, 9>::value << std::endl;
    std::cout << sum(std::string{}, "Hello", ", ", "world", '!') << std::endl;
    std::cout << sumOfSquare(3, 4, 12, 13) << std::endl;
}