#include <iostream>
#include <cmath>
// �ڴ˴�������Ĵ���
template<typename T , int n>
class Array {
public:
    T arr[n];
    Array(){
        for (int i = 0; i < n; i++) {
            arr[i] = 0;
        }
    }
    Array(const Array& A){
        for (int i = 0; i < n; i++) {
            arr[i] = A.arr[i];
        }
    }
    T& operator[](int i) {
        return arr[i];
    }
    const T& operator[](int i) const {
        return arr[i];
    }
};
int main() {
    Array<int, 10> arrInt;
    static_assert(sizeof(arrInt) == sizeof(int) * 10);

    Array<double, 4> arrDbl;
    static_assert(sizeof(arrDbl) == sizeof(double) * 4);

    for (int i = 0; i < 4; i++) {
        arrInt[i] = i;
        arrDbl[i] = std::sqrt(i);
    }
    const auto arrInt2 = arrInt;
    for (int i = 0; i < 10; i++) {
        std::cout << arrInt2[i] << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << arrDbl[i] << ' ';
    }
}