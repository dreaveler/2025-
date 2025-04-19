//һ��1C 1D(�����ٿ���) 1F(gptһ�Σ�1H
//1C��const int*�ǿ����޸�ָ��ָ�򲻿��޸�ֵ   int* const�ǿ����޸�ֵ���ɻ���
//1F��ע�������ָ���������  ���庯������ʱֱ��F funcs[]���� ��Ϊ�Ѿ���ָ����   �ð�WA��һ��  ��������ֱ����double
//����2B(ʱ��ע������Ҫ�ڸ��ƹ��캯�����) 2C(��˼��һ��) 2D(��ע���޸�mutable�ڳ�Աǰ��)  
//����3B������ѧϰһ�´������ʹ�ã��Լ������ſ��Խ��оۺϳ�ʼ����3D  
//����ģ�⣺9 ���в����б��lambda���ʽ���ܱ�����ָ��ָ��  functional���еĺ���������  ������ʱ�ʲ�����ӿ��أ���

#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
// �ڴ˴�������Ĵ���
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