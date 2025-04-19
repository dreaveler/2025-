#include <iostream>
#include <vector>
#include <cmath>
// �ڴ˴�������Ĵ���
template<typename...Ts>
std::vector<double>makeSqrtVec(Ts...args) {
    std::vector<double>vec {std::sqrt(args)...};
    return vec;
}
int main() {
    for (auto i : makeSqrtVec(1, 4, 9, 16, 25)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (auto i : makeSqrtVec(8, 7, 6)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (auto i : makeSqrtVec()) {
        std::cout << i << " ";
    }
}