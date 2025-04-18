#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using std::cin, std::cout, std::endl;

int add(int a, int b);
double add(double a, double b);
char* add(const char* a, const char* b);
char* add(const char* a, char b);
// 在此处补充你的代码
int add(int a, int b)
{
    return a + b;
}
double add(double a, double b)
{
    return a + b;
}
char* add(const char* a, const char* b) {
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);
    char* result = new char[len_a + len_b + 1];
    strcpy(result, a);
    strcat(result, b);
    return result;
}

char* add(const char* a, char b) {
    size_t len_a = strlen(a);
    char* result = new char[len_a + 2]; 
    strcpy(result, a);
    result[len_a] = b;
    result[len_a + 1] = '\0';
    return result;
}
char* read_str_from_cin() {
    int len;
    cin >> len;
    char* s = new char[len + 1];
    // c++20后不支持，请暂时调整为c++17
    cin >> s;
    return s;
}

int main() {
    // 整数加法
    int i1, i2;
    cin >> i1 >> i2;
    cout << add(i1, i2) << endl;
    // 浮点数加法
    double d1, d2;
    cin >> d1 >> d2;
    cout << add(d1, d2) << endl;
    // 字符串加法
    char* str_ptr;
    char* s1 = read_str_from_cin();
    char* s2 = read_str_from_cin();
    str_ptr = add(s1, s2);
    cout << str_ptr << endl;
    delete[] str_ptr;
    delete[] s1;
    delete[] s2;
    // 字符串加字符
    char* s3 = read_str_from_cin();
    char c;
    cin >> c;
    str_ptr = add(s3, c);
    cout << str_ptr << endl;
    delete[] str_ptr;
    delete[] s3;
}