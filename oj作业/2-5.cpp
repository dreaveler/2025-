#include <iostream>
#include <utility>

class MyClass {
public:
    int value;
    // �ڴ˴�������Ĵ���
    MyClass(){}
    explicit MyClass(int x) :value(x) {}
};

// ����һЩ��ħ�����룬�㲻�ù�
template<typename, typename>struct J :
    std::true_type {
}; template<typename T>
struct J<T, std::void_t<decltype(std::
    declval<T&>() = 0)>> :std::false_type{};
static_assert(J<MyClass, void>::value);

int main() {
    MyClass a;
    a = MyClass(42);
    // a = 42; // ����
    std::cout << a.value << std::endl;
}