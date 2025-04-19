#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>

template <typename T>
class OstreamIterator {
public:
    // C++17 �涨�ĵ��������붨������ͱ���
    // C++20 ֻ�� value_type �� difference_type
    using value_type = T;
    using reference = T&;
    using pointer = T*;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::output_iterator_tag;
    OstreamIterator(const OstreamIterator&) = default;
    OstreamIterator& operator=(const OstreamIterator&) = default;

private:
    // �ڴ˴�������Ĵ���
    std::ostream* os;
public:
    OstreamIterator(std::ostream& stream) : os(&stream) {}

    OstreamIterator& operator*() { return *this; }
    OstreamIterator& operator++() { return *this; }
    OstreamIterator operator++(int) { return *this; }

    OstreamIterator& operator=(const T& value) {
        *os << value;
        return *this;
    }
};

int main() {
    std::string strArr[]{ "Creeper", "? ", "Aw", " ", "man" };
    std::copy(std::begin(strArr), std::end(strArr), OstreamIterator<std::string>(std::cout));

    // ����� std::string ����
    std::stringstream ss;
    std::vector<int> intVec{ 1, 2, 3, 4, 5 };
    std::copy(intVec.begin(), intVec.end(), OstreamIterator<int>(ss));
    assert(ss.str() == "12345");
}