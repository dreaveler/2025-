#include <cstring>
#include <cstdio>
#include <iostream>
#include <utility>
using std::cin, std::cout, std::endl;

int add(const char* a, const char* b, char* dest);
int itoa(int a, char* dest);
//注意细节  对细节的最好诠释
class BigInt {
    char* data{};

public:
    // 在此处补充你的代码
    BigInt(int a) {
        int l = itoa(a, nullptr);
        data = new char[l];
        itoa(a, data);
    }
    BigInt(const char* str) {
        int l = strlen(str);
        data = new char[l + 1];
        memcpy(data, str, l);
        data[l] = '\0';
    }
    BigInt(const BigInt& num) {
        int l = strlen(num.data);
        data = new char[l+1];
        memcpy(data, num.data, l);
        data[l] = '\0';
    }
    BigInt& operator = (const BigInt& other){
        if (this == &other) return *this;
        delete[] data;
        int l = strlen(other.data);
        data = new char[l + 1];
        memcpy(data, other.data, l);
        data[l] = '\0';
        return *this;
    }
    BigInt& operator=(const int& n)
    {
        BigInt temp(n);
        *this = temp;
        return *this;
    }
    friend BigInt operator+(const BigInt& a, const BigInt& b) {
        int l = add(a.data, b.data, nullptr);
        char* str = new char[l];
        add(a.data, b.data, str);
        BigInt ans(str);
        delete[] str;
        return ans;
    };
    friend BigInt operator+(const char* c, const BigInt& a) {
        BigInt ch(c);
        return (ch + a);
    };
    BigInt& operator+=(const int& n) {
        BigInt nn(n);
        *this = *this + nn;
        return *this;
    };
    BigInt& operator+=(const char* c) {
        *this = *this + c;
        return *this;
    };
    BigInt& operator++() {
        BigInt one("1");
        *this = *this + one;
        return *this;
    };
    BigInt operator++(int) {
        BigInt temp(*this);
        ++(*this);
        return temp;
    };
    //
    ~BigInt() {
        delete[] data;
    }

    friend std::istream& operator>>(std::istream& in, BigInt& c);
    friend std::ostream& operator<<(std::ostream& out, const BigInt& c);
};

int main() {
    BigInt a(0), b("0");
    int n;

    cin >> a >> n;
    a = ("0" + a);
    b = n;

    cout << a + b << endl;
    cout << n + a << endl;
    cout << a + n << endl;

    cout << ((b += n) += "10") << endl;
    cout << ++++b << endl;
    cout << b++ << endl;
    cout << b << endl;
}

// 以下是工具函数的实现，不用关心。

#include <algorithm>
#include <iterator>
#include <memory>
#include <string>

int add(const char* a, const char* b, char* d) {
    int
        i = std::strlen(a), j = std::strlen(b), k{}, c{}; auto
        r = std::make_unique<char[]>(std::max(i, j) + 1);
    auto f = [&](auto...a) {int s = (... + a); r[k++] = s %
        10 + 48, c = s / 10; }; while (i && j)f(a[--i] - 48, b[--j]
            - 48, c); while (i)f(a[--i] - 48, c); while (j)f(b[--
                j] - 48, c); if (c)r[k++] = c + 48; if (d)std::copy(&r[
                    0], &r[k], std::reverse_iterator{ d + k }), d[k] = 0;
                    return k + 1;
}int itoa(int a, char* dest) {
    return
        (dest ? sprintf_s(dest,sizeof(dest), "%d", a) : snprintf(nullptr,
            0, "%d", a)) + 1;
}std::istream& operator>>(std::
    istream& i, BigInt& c) {
    std::string s; i >> s; c = BigInt
    (s.c_str()); return i;
}std::ostream& operator
<<(std::ostream& o, const BigInt& c) {
    return o <<
        c.data;
}