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
    // ���ⲻӦ���ø��ƹ��캯���͸��Ƹ�ֵ�����
    A(A& x) = delete;
    A& operator=(A& x) = delete;
    A(A&& x) {
        val = x.val;
        x.val = 0; // ��x.val��0ģ��"�ƶ�"����
    }
    A& operator=(A&& x) {
        val = x.val;
        x.val = 0; // ��x.val��0ģ��"�ƶ�"����
        return *this;
    }
    int getVal() const {
        return val;
    }
};
int A::constructorCount = 0;
// �ڴ˴�������Ĵ���
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
    // ���ݴ��벻Ӧ���ٶ�����ù��캯��
    assert(A::constructorCount == 2);
}