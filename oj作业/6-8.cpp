#include <iostream>
// 在此处补充你的代码
class range {
public:
    range(int start, int end, int step = 1):
        start(start)
        ,ending(end)
        ,step(step){
        int current = start;
        while (current< ending && step > 0 || current > ending && step < 0) {
            len++;
            current += step;
        }
        arr = new int[len];
        current = start;
        int ptr = 0;
        while (ptr<len) {
            arr[ptr] = current;
            current += step;
            ptr++;
        }
    }
    ~range() {
        delete[] arr;
    }
    int* begin() {
        return arr;
    }
    int* end() {
        return arr + len;
    }
private:
    int ending;
    int step;
    int start;
    int len = 0;
    int* arr;
};
int main() {
    for (int i : range(0, 10)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int i : range(1, 20, 2)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int i : range(10, 0, -3)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int i : range(10, 0)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// 请不要使用任何标准库容器。
#if defined(_GLIBCXX_VECTOR) || defined(_GLIBCXX_DEQUE) || defined(_GLIBCXX_FORWARD_LIST) || \
    defined(_GLIBCXX_LIST)
#error Do not use standard library containers.
#endif