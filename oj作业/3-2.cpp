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
    // �ڴ˴�������Ĵ���
    Array2D(int a, int b):w(b) {
        data = new int[a*b];
    }
    ~Array2D() {
        delete[] data;
    }
    int* operator[](int a) {
        return &data[a * w];
    }
    //����a[][] ���ڵ�һ��[] �����ȷ���һ��int* ����a�еĵ�ַ Ȼ����ͨ��int*[] ���ʵ�j��   
};

// C++ ������������ɺ����������
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
            // assert�����������������������ʱ����
            assert(a.at(i, j) == a[i][j]);
        }
    }
}