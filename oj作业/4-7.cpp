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
        // ���ƴ��۵ͣ�ʡ���Ը�ֵ�жϡ�
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
    // �ڴ˴�������Ĵ���
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

    { // ����Student֮��ĸ���
        Student student2{ student };
        std::cout << student2.GetAge() << " " << student2.GetID() << "\n";
        Student student3{ 13, 10085 };
        student2 = student3;
        std::cout << student2.GetAge() << " " << student2.GetID() << "\n";
    }

    { // ����Student��Person�ĸ��ƺ�Clone
        Student student3{ 13, 10085 };

        Person& studentRef = student;
        studentRef = student3;

        std::cout << student.GetAge() << " " << student.GetID() << "\n";
        studentRef.Clone(student3);
        std::cout << student.GetAge() << " " << student.GetID() << "\n";
    }

    { // ���Դ�����
        std::cout << error << "\n";
        student.Clone(person);
        std::cout << student.GetAge() << " " << student.GetID() << "\n";
        std::cout << error << "\n";
    }

    return 0;
}