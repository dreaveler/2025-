#include <iostream>
#include <cmath>
using std::cin, std::cout, std::endl, std::sqrt;
//��ȫaver�����Ķ���
// �ڴ˴�������Ĵ���

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