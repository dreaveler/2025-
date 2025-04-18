#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
// 在此处补充你的代码
//经验教训是什么呢  可以看看下面定好的格式
#include<type_traits>
template<typename Container,typename Value>
bool includes(const Container& c,const Value& v) {
    if constexpr (std::is_same<Container, std::unordered_map<std::string, int>>::value) {
        return c.find(v) != c.end();
    }
    else {
        return std::find(c.begin(), c.end(), v) != c.end();
    }
}
int main() {
    std::string k;
    int v;
    std::unordered_map<std::string, int> map;
    for (int i{ 0 }; i < 3; i++) {
        std::cin >> k >> v;
        map.insert({ k, v });
    }

    std::vector<int> vec;
    for (int i{ 0 }; i < 5; i++) {
        std::cin >> v;
        vec.push_back(v);
    }

    std::array<int, 5> arr;
    for (int i{ 0 }; i < 5; i++) {
        std::cin >> v;
        arr[i] = v;
    }

    std::cin >> k;
    if (includes(map, k)) {
        std::cout << map[k] << std::endl;
    }
    else {
        std::cout << "None" << std::endl;
    }
    std::cin >> v;
    std::cout << std::boolalpha << includes(vec, v) << std::endl;
    std::cin >> v;
    std::cout << std::boolalpha << includes(arr, v) << std::endl;
}