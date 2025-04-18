#include <iostream>
#include <utility>
using std::cout, std::endl;

class MyClass {
public:
    int value;
    // 在此处补充你的代码
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

// 一些黑魔法，避免你写出错误的代码
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