#include <iostream>
using std::cin, std::cout, std::endl;
class Sample {
public:
    // �ڴ˴�������Ĵ���
    mutable int value;
    Sample(int x) :value(x) {}
    int GetValue() const {
        return value;
    }
    void SetValue(int x)const{
        value = x;
    }
};
int main() {
    int x, y;
    cin >> x >> y;
    const Sample s(x);
    cout << s.GetValue() << endl;
    s.SetValue(y);
    cout << s.GetValue() << endl;
}