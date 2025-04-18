#include <iostream>
#include <cmath>
using std::cin, std::cout, std::endl, std::sqrt;
//补全aver函数的定义
// 在此处补充你的代码

 void aver(int a,int b,float &c,float &d)
{
    c = (a + b) / 2.0;
    d = sqrt(a * b);
    return;
}
int main() {
    int a, b;
    float c, d;
    cin >> a >> b;
    aver(a, b, c, d);
    cout << c << " " << d << endl;
}