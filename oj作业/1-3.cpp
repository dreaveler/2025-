#include <iostream>
using std::cin, std::cout, std::endl;
int n;
int m;
const int x1 = 1;
const int x2 = 2;
const int& r{ n };
const int* v1 = &x1;
int* const v2 = &m;
int main() {
    cin >> n >> m;
    // 在此处补充你的代码
    //
    n *= 2;
    v1 = &x2;
    m += 1;
    cout << r << " " << (*v1) << " " << (*v2) << endl;
}