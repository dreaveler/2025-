#include <cassert>
#include <iostream>

struct A {
    A() = default;
    A(const A& other) {
        std::cout << "Copy A\n";
    }
};
//��ʵ�������������Ϊ����ʱ��һ����ֵ���õĻ���ܿ����� ��ֵ�����ܴ�Ļ�����ֱ��ת��ָ�� �ٰ���ֵ���õ�ָ�����nullptr
struct B {
    A* a;
    B() : a{ new A{} } {}
    B(const B& other) : a{ new A(*other.a) } {}
    // �ڴ˴�������Ĵ���
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

// �������ڴ�������ʵ�֣����ù�
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