#include <iostream>
#include <utility>
using std::cin, std::cout, std::endl;
// �ڴ˴�������Ĵ���
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

// ��һ�д�������ȷ����δʹ�ú������أ����ù�
static_assert(std::is_function_v<decltype(multiply)>);