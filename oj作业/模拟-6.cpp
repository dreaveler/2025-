#include <iostream>
using std::cin, std::cout, std::endl;

class QTwoNumber {
private:
    int a, b;
public:
    QTwoNumber(int a, int b) :a(a), b(b) {}
    QTwoNumber(int a) :a(a), b(0) {}
    friend QTwoNumber operator+(const QTwoNumber& a, const QTwoNumber& b) {
        int c = a.a + b.a;
        int d = a.b + b.b;
        QTwoNumber  ans(c, d);
        return ans;
    }
    friend QTwoNumber operator-(const QTwoNumber& a, const QTwoNumber& b) {
        int c = a.a - b.a;
        int d = a.b - b.b;
        QTwoNumber  ans(c, d);
        return ans;
    }
    friend QTwoNumber operator*(const QTwoNumber& a, const QTwoNumber& b) {
        int c = a.a * b.a + 2 * a.b * b.b;
        int d = a.a * b.b + a.b * b.a;
        QTwoNumber  ans(c, d);
        return ans;
    }
    friend QTwoNumber operator-(const QTwoNumber& a) {
        int c = -a.a;
        int d = -a.b;
        QTwoNumber  ans(c, d);
        return ans;
    }
    friend std::ostream& operator<<(std::ostream& os, const QTwoNumber& a) {
        os << "(" << a.a << " + " << a.b << "V2)";
        return os;
    }
};
int main() {
    int n, q;
    cin >> n >> q;
    const QTwoNumber a(3, 4);
    const QTwoNumber b(2, -1);
    const QTwoNumber c(n, q);

    cout << a << " + " << 2 << " = " << a + 2 << endl;
    cout << 3 << " + " << b << " = " << 3 + b << endl;
    cout << a << " - " << c << " = " << a - c << endl;
    cout << " - " << b << " = " << -b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << b << " * " << c << " = " << b * c << endl;
}