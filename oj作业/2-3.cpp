#include <iostream>
#include <utility>
using std::cout, std::endl;

class MyClass {
public:
    int value;
    // �ڴ˴�������Ĵ���
    MyClass() {
        value = 42;
    }
    MyClass(int m) {
        value = m;
    }
    const MyClass& getObj() const {
        return *this;
  }
    MyClass& getObj() {
        return *this;
    }
};

// һЩ��ħ����������д������Ĵ���
static_assert(std::is_const_v<std::
    remove_reference_t<decltype(std::
        declval<const MyClass&>().getObj())>>);

void print(const MyClass& a) {
    cout << a.getObj().value << endl;
}

int main() {
    int m, n;
    MyClass a;
    cout << a.value << endl;
    while (std::cin >> m >> n) {
        a.getObj() = m;
        cout << a.value << " ";
        a.getObj() = MyClass(n);
        print(a);
    }
}