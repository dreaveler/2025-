#include <iostream>
using std::cin, std::cout, std::endl;
class Sample {
public:
    // 在此处补充你的代码
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