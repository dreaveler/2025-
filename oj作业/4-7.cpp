#include <iostream>

bool error = false;

class Person
{
    int age_;
public:
    Person(int age) : age_{ age } {}
    Person(const Person& another) : age_{ another.age_ } {}
    Person& operator=(const Person& another)
    {
        // 复制代价低，省略自赋值判断。
        age_ = another.age_;
        return *this;
    }
    virtual Person& Clone(const Person& another)
    {
        return operator=(another);
    }
    int GetAge() const { return age_; }
};

class Student : public Person
{
    int studentID_;
public:
    Student(int age, int studentID) :
        Person{ age }, studentID_{ studentID }
    {
    }

    int GetID() const { return studentID_; }
    // 在此处补充你的代码
    Student(const Student& s) :Person{ s.GetAge()}, studentID_{s.GetID()} {}
    Student& operator=(const Student& s) {
        if (this == &s) return *this;
        Person::operator=(s);
        studentID_ = s.GetID();
        return *this;
    }
    Person& Clone(const Person& p) {
        const Student* s = dynamic_cast<const Student*>(&p);
        if (s) return operator=(*s);
        else {
            error = true;
            return *this;
        }
    }
};

int main()
{
    const Person person{ 35 };
    Student student{ 15, 10086 };

    { // 测试Student之间的复制
        Student student2{ student };
        std::cout << student2.GetAge() << " " << student2.GetID() << "\n";
        Student student3{ 13, 10085 };
        student2 = student3;
        std::cout << student2.GetAge() << " " << student2.GetID() << "\n";
    }

    { // 测试Student向Person的复制和Clone
        Student student3{ 13, 10085 };

        Person& studentRef = student;
        studentRef = student3;

        std::cout << student.GetAge() << " " << student.GetID() << "\n";
        studentRef.Clone(student3);
        std::cout << student.GetAge() << " " << student.GetID() << "\n";
    }

    { // 测试错误复制
        std::cout << error << "\n";
        student.Clone(person);
        std::cout << student.GetAge() << " " << student.GetID() << "\n";
        std::cout << error << "\n";
    }

    return 0;
}