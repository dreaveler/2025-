#include <iostream>
#include <climits>
using std::cin, std::cout, std::endl;

// minRef
// 在此处补充你的代码
int& minRef(int& a,int& b)
{
    if (a >= b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int a = 0, b = 0;
    for (int i = 0; i < 5; i++) {
        cin >> minRef(a, b);
    }
    minRef(a, b) = INT_MAX;
    cout << minRef(a, b) << endl;
}