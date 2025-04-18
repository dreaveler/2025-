#include <iostream>
#include <typeinfo>
using std::cout, std::endl;
class Animal {
public:
    virtual ~Animal() = default;
};
class Dog : public Animal {};
class Cat : public Animal {};
class Mouse : public Animal {};

void whoAreYou(Animal* a) {
    // 在此处补充你的代码
    if (typeid(*a) == typeid(Dog)) cout << "I'm a dog." << endl;
    else if (typeid(*a) == typeid(Cat)) cout << "I'm a cat." << endl;
    else if (typeid(*a) == typeid(Mouse)) cout << "I'm a mouse." << endl;
    else cout << "I don't know who I am.";
    //必须要是*a  不然会返回T* 
}
int main() {
    Animal* a[4]{ new Dog(), new Cat(), new Mouse(), new Animal() };
    for (int i = 0; i < 4; i++) {
        whoAreYou(a[i]);
    }
    for (int i = 0; i < 4; i++) {
        delete a[i];
    }
}