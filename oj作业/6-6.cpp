#include <iostream>
// �ڴ˴�������Ĵ���
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
//����ͨ����ԭ�������������ת�����¿��ܵ���ʽ����ת��  Ȼ��������������±���ͨ��
int main() {
    MyCin m;
    int n1, n2;
    while (m >> n1 >> n2) {
        std::cout << n1 << " " << n2 << std::endl;
    }
    // m << n1; // �������
}

// ������Ƿ���ȷ����ˡ�m << n1 ��ͨ�����롱�������
template<typename, typename>struct J :std::
true_type {
}; template<typename T>struct J<
    T, std::void_t<decltype(std::declval<int&
    >() = std::declval<T&>())>> :std::false_type
{}; static_assert(J<MyCin, void>::value);