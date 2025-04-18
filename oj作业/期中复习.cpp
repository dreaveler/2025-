//一：1C 1D(可以再看看) 1F(gpt一次）1H
//1C：const int*是可以修改指针指向不可修改值   int* const是可以修改值不可换绑
//1F：注意给函数指针起别名后  定义函数数组时直接F funcs[]即可 因为已经是指针了   好吧WA了一次  看见浮点直接上double
//二：2B(时刻注意增减要在复制构造函数里改) 2C(再思考一下) 2D(标注可修改mutable在成员前加)  
//三：3B（可以学习一下代理类的使用，以及大括号可以进行聚合初始化）3D  
//期中模拟：9 带有捕获列表的lambda表达式不能被函数指针指向  functional库中的函数可以用  但考试时允不允许加库呢？？

#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
// 在此处补充你的代码
template<typename T>
class MemberFactory{
private:
    std::vector<std::function<void(T&)>>arr;
public:
    template<typename M,typename N>
    void set(M T::*a, N f) {
        arr.push_back([a, f](T& obj) {obj.*a = f(); });
    }
    T create() {
        T obj;
        for (auto& aa : arr) {
            aa(obj);
        }
        return obj;
    }
};

struct Xyz {
    int x, y;
    double z;
};

struct Student {
    int age;
    std::string name;
};

int main() {
    int x{ 1 }, y{ 2 }, z{ 4 };
    std::string s;

    MemberFactory<Xyz> f1;
    f1.set(&Xyz::x, [&]() { return x * 2; });
    f1.set(&Xyz::y, [&]() { return y * 3; });
    f1.set(&Xyz::z, [&]() { return std::sqrt(z); });

    auto a = f1.create();
    std::cout << std::fixed << a.x << ' ' << a.y << ' ' << a.z << '\n';

    std::cin >> x >> y >> z >> s;
    auto b = f1.create();
    std::cout << std::fixed << b.x << ' ' << b.y << ' ' << b.z << '\n';

    MemberFactory<Student> f2;
    f2.set(&Student::age, [=]() { return 24ull; });
    f2.set(&Student::name, [=]() { return s; });

    auto student = f2.create();
    std::cout << student.age << ' ' << student.name << '\n';
}