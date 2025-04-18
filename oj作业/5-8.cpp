#include <iostream>
// 在此处补充你的代码

class Callable {
public:
    virtual void call() = 0;
};
template<typename F>
class FuncWrapper : public Callable {
public:
    F f;
    FuncWrapper(F f) :f{ f } {}
    void call() {
        f();
    }
};
class Function {
public:
    Callable* ptr;
    Function() = default;
    template<typename T>
    Function(T t) :ptr { new FuncWrapper<T>(t) } {}
    ~Function() {
        delete ptr;
    }
    void operator()() {
        ptr->call();
    }
};
void f1() {
    std::cout << "f1" << std::endl;
}
struct F2 {
    void operator()() {
        std::cout << "f2" << std::endl;
    }
};
F2 f2;
int main() {
    int v = 3;
    auto f3 = [&]() {
        std::cout << "f" << v << std::endl;
        };

    Function funcs[]{ f1, f2, f3 };

    for (int i = 0; i < 3; i++) {
        funcs[i]();
    }
}