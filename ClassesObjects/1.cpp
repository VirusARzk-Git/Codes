#include <iostream>
using namespace std;

class student
{
public:
    string name;
    int age;
    student()
    {
        name = "";
        age = 0;
    }
    student(string a, int b)
    {
        name = a;
        age = b;
    }
    student(student &s)
    {
        name = s.name;
        age = s.age;
    }
    void print()
    {
        cout << "Name : " << name << ", Age : " << age << endl;
    }
};

int main()
{
    student s1("Aditya", 23);
    student s2 = s1;
    student s3(s1);
    s2.age = 47;
    s3.age = 79;
    s1.print();
    s2.print();
    s3.print();
}