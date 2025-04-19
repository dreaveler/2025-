#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <list>
using std::cout, std::endl;
template <typename Container>
class MultBackInsertIter {
private:
    Container* c;
public:
    // C++17 �涨�ĵ��������붨������ͱ���
    // C++20 ֻ�� value_type �� difference_type
    using value_type = typename Container::value_type;
    using reference = value_type&;
    using pointer = value_type*;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::output_iterator_tag;
    // �ڴ˴�������Ĵ���
    MultBackInsertIter(Container& cc):c(&cc) {}
    MultBackInsertIter<Container>& operator=(const reference value) {
        c->push_back(2*value);
        return *this;
    }
    MultBackInsertIter& operator*() {
        return *this;
    }
    MultBackInsertIter& operator++() {
        return *this;
    }
};
template <typename T>
void print(const T& c) {
    for (auto i : c) { cout << i << ' '; }
    cout << endl;
}
int main() {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    std::deque<int> d{ 8, 9 };
    std::list<int> l{ 10, 11 };
    std::copy(v.begin(), v.end(), MultBackInsertIter(d));
    std::copy(v.begin(), v.end(), MultBackInsertIter(l));
    print(d);
    print(l);
}