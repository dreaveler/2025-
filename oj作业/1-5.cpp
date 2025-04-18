#include <iostream>
#include <utility>
using std::cin, std::cout, std::endl;
// 在此处补充你的代码
int multiply(int x, int y, int c = 1, int d = 1) {
    return x * y * c * d;
}
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << multiply(a, b) << endl;
    cout << multiply(a, b, c) << endl;
    cout << multiply(a, b, c, d) << endl;
}

// 下一行代码用于确保你未使用函数重载，不用管
static_assert(std::is_function_v<decltype(multiply)>);