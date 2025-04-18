#include <iostream>
#include <cstring>

class String {
    char* _data;
    int _size;

public:
    int size() const;
    String();
    String(const char* str);
    // 本题不涉及拷贝和赋值
    String(const String& str) = delete;
    String& operator=(const String& str) = delete;
    ~String() {
        delete[] _data;
    }

    friend bool operator==(const String& lhs, const String& rhs);
};
// 在此处补充你的代码
int String::size() const {
    return _size;
}
String::String() :_size{ 0 } {
    _data = new char[1];
    _data[0] = '\0';
}
//""的生成方式
String::String(const char* str) {
    int l = std::strlen(str);
    _size = l;
    _data = new char[l+1];
    memcpy(_data, str, l);
    _data[l] = '\0';
}
bool operator==(const String& lhs, const String& rhs) {
    return strcmp(lhs._data,rhs._data)==0;
}
//注意string库中相关函数的使用
bool operator!=(const String& lhs, const String& rhs)
{
    if (lhs == rhs) return false;
    else return true;
}

int main() {
    char origin[200], copy[200], other[200];
    std::cin >> origin >> other;
    strcpy_s(copy, origin);

    String s1(origin), s3(other);
    const String s2(copy), empty, fixed("string");

    std::cout << std::boolalpha;
    std::cout << (s1 == s2) << " " << (s1.size() == s2.size()) << std::endl;
    std::cout << (s1 == s3) << " " << (s1.size() == s3.size()) << std::endl;
    std::cout << (s1 != empty) << " " << (s1.size() != 0) << std::endl;
    std::cout << (s1 == fixed) << std::endl;
    std::cout << (empty == "") << " " << (empty.size() == 0) << std::endl;
    std::cout << (fixed == "string") << " " << (fixed.size() == 6) << std::endl;
    std::cout << ("" != empty) << " " << ("" == fixed) << std::endl;
}