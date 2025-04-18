#include <iostream>
using std::cin, std::cout, std::endl;
int main() {
    int n, x, y, z;
    cin >> n;
    cin >> x >> y >> z;
    int* a = new int[n];
    int* b = new int[n];
    int* c = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    auto f = [x, y, z](int& a, int& b, int& c) {
        if (a < 60) a = 0;
        if (b < 60) b = 0;
        if (c < 60) c = 0;
        int sum{ x * a + y * b + z * c };
        double average{ sum / double(x + y + z) };
        int ans;
        if (average - int(average) >= 0.5) ans = int(average) + 1;
        else ans = int(average);
        return ans;
        };
        // 在此处补充你的代码
        //
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " << b[i] << " " << c[i] << " ";
        int tot = f(a[i], b[i], c[i]);
        cout << a[i] << " " << b[i] << " " << c[i] << " " << tot << endl;
    }
    delete[] a;
    delete[] b;
    delete[] c;
}