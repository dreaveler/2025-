#include <iostream>
#include <cassert>
using std::cout, std::endl;
class A {
private:
    int val;
public:
    static int constructorCount;
    A(int x) {
        constructorCount++;
        val = x;
    }
    // 本题不应调用复制构造函数和复制赋值运算符
    A(A& x) = delete;
    A& operator=(A& x) = delete;
    A(A&& x) {
        val = x.val;
        x.val = 0; // 将x.val赋0模拟"移动"语义
    }
    A& operator=(A&& x) {
        val = x.val;
        x.val = 0; // 将x.val赋0模拟"移动"语义
        return *this;
    }
    int getVal() const {
        return val;
    }
};
int A::constructorCount = 0;
// 在此处补充你的代码
using std::move;
void swap(A& a1, A& a2) {
    A temp{move(a1)};
    a1 = move(a2);
    a2 = move(temp);
}
int main() {
    A a(1), b(2);
    swap(a, b);
    cout << a.getVal() << " " << b.getVal() << endl;
    // 整份代码不应当再额外调用构造函数
    assert(A::constructorCount == 2);
}