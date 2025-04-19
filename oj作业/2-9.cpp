#include <iostream>
#include <cstring>
#include <cassert>
using std::cout, std::endl;
class String {
public:
    char* str;
    int len;
    // �ڴ˴�������Ĵ���
    String(const char* p) {
        len = strlen(p);
        str = new char[len+1];
        memcpy(str, p,len);
        str[len] = '\0';
    }
    String(const String& s) {
        len = s.len;
        str = new char[len+1];
        memcpy(str, s.str,len);
        str[len] = '\0';
    }
    ~String() {
        delete[] str;
    }
};

void pass_by_ref(String& s) {
    s.str[0] = 'B';
}
void pass_by_val(String s) {
    s.str[0] = 'B';
}
// �ڴ���������
int allocCount{ 0 };
int main() {
    {
        String str1("Dog");
        const String str2("Dog");
        pass_by_ref(str1);
        pass_by_val(str2);
        cout << str1.len << " " << str1.str << endl;
        cout << str2.len << " " << str2.str << endl;
    }
    assert(allocCount == 0);
}

// ���д�������ȷ����Ĵ���δ�����ڴ�й©�������
void* operator new[](std::size_t size) {
    if (void* ptr = std::malloc(size)) { allocCount++; return ptr; }
    throw std::bad_alloc{};
}
void operator delete[](void* ptr) {
    allocCount--;
    std::free(ptr);
}