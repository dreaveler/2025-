#include <iostream>
#include <random>
#include <cassert>

class Array2D {
    int* data;
    int w;

public:
    int& at(int x, int y) {
        return data[x * w + y];
    }
    // 在此处补充你的代码
    Array2D(int a, int b):w(b) {
        data = new int[a*b];
    }
    ~Array2D() {
        delete[] data;
    }
    int* operator[](int a) {
        return &data[a * w];
    }
    //对于a[][] 对于第一个[] 我们先返回一个int* 即第a行的地址 然后再通过int*[] 访问第j列   
};

// C++ 风格的随机数生成函数，不用深究
int rand() {
    static std::random_device rd;
    static std::default_random_engine e(rd());
    return int(e());
}

int main() {
    int h{ 3 }, w{ 4 };
    Array2D a(h, w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            a.at(i, j) = rand();
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            // assert：如果条件不成立，则运行时错误
            assert(a.at(i, j) == a[i][j]);
        }
    }
}