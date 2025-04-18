#include <iostream>

struct Point {
    int x, y, z;
    // 在此处补充你的代码
    Point& translate(int Point::* p, int x) {
        *this.*p += x;
        return *this;
    }
    //
    void print() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")\n";
    }
};

int main() {
    Point p{};

    char c;
    int x;
    while (std::cin >> c >> x) {
        int Point::* dir = nullptr;
        switch (c) {
        case 'x': dir = &Point::x; break;
        case 'y': dir = &Point::y; break;
        case 'z': dir = &Point::z; break;
        }
        p.translate(dir, x);
        p.print();
    }
}