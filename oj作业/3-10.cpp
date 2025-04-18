#include <cassert>
#include <iostream>

struct A {
    A() = default;
    A(const A& other) {
        std::cout << "Copy A\n";
    }
};
//其实根本意义就是因为构造时是一个右值引用的话会很快死掉 赋值开销很大的话不如直接转移指针 再把右值引用的指针设成nullptr
struct B {
    A* a;
    B() : a{ new A{} } {}
    B(const B& other) : a{ new A(*other.a) } {}
    // 在此处补充你的代码
    B(B&& b) :a{b.a} {
        b.a = nullptr;
    }
    //
    ~B() {
        delete a;
    }
};

struct C {
    B b;
};

int newCount;

int main() {
    newCount = 0;
    {
        B b;
        B b_copied(b);
        assert(b_copied.a != nullptr);
    }
    std::cout << "---\n";
    assert(newCount == 0);

    {
        B b_moved(C{}.b);
        assert(b_moved.a != nullptr);
    }
    std::cout << "---\n";
    assert(newCount == 0);
}

// 以下是内存分配计数实现，不用管
void* operator new(std::size_t size) {
    if (void* ptr = std::malloc(size)) {
        newCount++;
        return ptr;
    }
    throw std::bad_alloc{};
}
void operator delete(void* ptr, std::size_t) noexcept {
    if (ptr) {
        std::free(ptr);
        newCount--;
    }
}