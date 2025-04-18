#include <iostream>
using std::cout, std::endl;
class Person {
public:
    Person(int x) : age{ x } {}
private:
    int age;
    // 在此处补充你的代码
    friend void grow(Person* p, int num);

public:
    static void print(Person* p, int num);
};

void Person::print(Person* p, int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << p[i].age << endl;
    }
}

void grow(Person* p, int num) {
    for (int i = 0; i < num; i++) {
        p[i].age++;
    }
}
int main() {
    Person people[3]{ 28, 45, 8 };
    Person::print(people, 3);
    grow(people, 3);
    Person::print(people, 3);
}