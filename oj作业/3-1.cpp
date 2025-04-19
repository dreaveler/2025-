#include <iostream>

class Point {
    int x, y;

public:
    Point() = default;
    // �ڴ˴�������Ĵ���
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << p.x << " " << p.y;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }
};

int main() {
    Point p;
    while (std::cin >> p) {
        std::cout << p << std::endl;
    }
}