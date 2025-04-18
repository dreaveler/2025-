#include <iostream>
#include <list>
#include <vector>
// 在此处补充你的代码
template<typename T, typename U>
int sumIf(const T& t, U u) {
    int sum = 0;
    int index = 1;
    for (auto num : t) {
        if (u(index)) sum += num;
        index++;
    }
    return sum;
}
int main() {
    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    auto x = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int a[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::list<int> l{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::cout << sumIf(v, [](int i) { return i % 3 == 1; }) << std::endl;
    std::cout << sumIf(x, [](int i) { return i % 3 == 0; }) << std::endl;
    std::cout << sumIf(a, [](int i) { return i % 2 == 0; }) << std::endl;
    std::cout << sumIf(l, [](int i) { return i % 2 == 1; }) << std::endl;
}