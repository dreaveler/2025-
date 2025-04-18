#include <iostream>
#include <algorithm>
using std::cin, std::cout, std::endl;
class Point {
private:
    int x, y;
public:
    Point() : x{ 0 }, y{ 0 } {}
    friend std::istream& operator>>(std::istream& is, Point& p) {
        return is >> p.x >> p.y;
    }
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        return os << p.x << ' ' << p.y;
    }
    // 在此处补充你的代码
    friend bool operator<(const Point& p1, const Point& p2) {
        if (p1.x * p1.x + p1.y * p1.y != p2.x * p2.x + p2.y * p2.y)
            return p1.x * p1.x + p1.y * p1.y < p2.x * p2.x + p2.y * p2.y;
        else if (p1.x != p2.x)
            return p1.x < p2.x;
        else
            return p1.y < p2.y;
    }
    friend bool operator>(const Point& p1, const Point& p2) {
        return p2 < p1;
    }
};
int main() {
    int n;
    cin >> n;
    Point* points = new Point[n];
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }
    std::sort(points, points + n);
    for (int i = 0; i < n; i++) {
        cout << points[i] << endl;
    }
    std::sort(points, points + n, std::greater<Point>());
    for (int i = 0; i < n; i++) {
        cout << points[i] << endl;
    }
    delete[] points;
}