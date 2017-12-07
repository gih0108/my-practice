#include<iostream>
using namespace std;

class Parent
{
public:
    Parent()
    {
        cout << "Parent 생성자 호출" <<endl;
    }
    ~Parent()
    {
        cout << "Parent 소멸자 호출" << endl;
    }
};

class Child:public Parent
{
public:
    Child():Parent()
    {
        cout << "Child 생성자 호출" <<endl;
    }
    ~Child()
    {
        cout << "Child 소멸자 호출" << endl;
    }
};

int main()
{
    cout << "---평범한 Child 만들었을 때---"<<endl;
    {
        Child c;
    }
    cout << "---Parent 포인터로 Child가리켰을 때---" <<endl;
    {
        Parent *p = new Child();
        delete p;
    }
}

