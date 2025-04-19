#include <cassert>
#include <iostream>
#include <cstring>
using std::cout, std::endl;
class String {
public:
    int len;
    char* str;
    String(const char* x) {
        len = strlen(x);
        str = new char[len + 1];
        memcpy(str, x, len);
        str[len] = '\0';
    }
    // �ڴ˴�������Ĵ���
    String(const String& s) {
        len = s.len;
        str = new char[len + 1];
        memcpy(str, s.str, len);
        str[len] = '\0';
    }
    String& operator=(const String& s) {
        if (this == &s) return *this;
        delete[] str;
        len = s.len;
        str = new char[s.len + 1];
        memcpy(str, s.str, len);
        str[len] = '\0';
        return *this;
    }
    String(String&& s) :len(s.len) {
        str = s.str;
        s.str = nullptr;
    }
    String& operator=(String&& s) {
        if (this == &s) return *this;
        delete[] str;
        len = s.len;
        str = s.str;
        s.str = nullptr;
        return *this;
    }
    //
    ~String() {
        delete[] str;
    }
};

int newCount{ 0 };
int nowUsed{ 0 };
//���д������ڴ�����������ʵ�֣����ù�
void* operator new[](std::size_t size) {
    if (void* ptr = std::malloc(size)) {
        newCount++;
        nowUsed++;
        return ptr;
    }
    throw std::bad_alloc();
}
void operator delete[](void* ptr) noexcept {
    std::free(ptr);
    nowUsed--;
}

int main() {
    {
        String a("Hello");
        String b("World");
        String c("");
        c = String("Hi");
        cout << c.str << endl;
        c = a;
        cout << c.str << endl;
        cout << a.str << endl;
        (c = a) = b;
        cout << c.str << endl;
        cout << b.str << endl;
        (c = "Hi") = a;
        cout << c.str << endl;
    }
    // assert: �����������㣬������ʱ����
    // ���ݴ���Ӧ������ 9 ���ڴ棬�Ҳ�Ӧ�ڴ�й©
    assert(newCount == 9);
    assert(nowUsed == 0);
    return 0;
}