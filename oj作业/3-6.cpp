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
// 在此处补充你的代码
//极其美妙的重载 通过添加一个代理类的方式使得重载后的，只能在+=右边生效
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

    // 先将 v 清空，然后检查 v.size() 是否为 0
    if (v = {}, v.size()) {
        std::cout << "Unreachable" << std::endl;
    }
}