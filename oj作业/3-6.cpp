#include <iostream>

class IntVector {
    static constexpr int capacity{ 256 };
    int len{ 0 };
    int data[IntVector::capacity];

public:
    IntVector() = default;
    IntVector(const IntVector&) = default;
    void pushBack(int e) {
        data[len++] = e;
    }
    int at(int i) {
        return data[i];
    }
    int size() {
        return len;
    }
};
// �ڴ˴�������Ĵ���
//������������� ͨ�����һ��������ķ�ʽʹ�����غ�ģ�ֻ����+=�ұ���Ч
class Temp {
    IntVector& v;
public:
    explicit Temp(IntVector& vec) :v(vec) {}
    Temp& operator,(int x) {
        v.pushBack(x);
        return *this;
    }
};
Temp operator+=(IntVector& vec, int x) {
    vec.pushBack(x);
    return Temp(vec);
}
int main() {
    IntVector v;
    v += 1, 2, 3;

    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;

    int x, y;
    std::cin >> x >> y;
    v += x, 5, 6, 7, y;
    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;

    // �Ƚ� v ��գ�Ȼ���� v.size() �Ƿ�Ϊ 0
    if (v = {}, v.size()) {
        std::cout << "Unreachable" << std::endl;
    }
}