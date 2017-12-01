#include<iostream>
using namespace std;

class AAA
{
private:
    int num1;
    
public:
    virtual void Func1() 
    {
        cout << "Func1" <<endl;
    }
    virtual void Func2()
    {
        cout << "Func2" <<endl;
    }
};

class BBB:public AAA
{
private:
     int num2;
public:
    virtual void Func1()//오버라이딩 된 가상함수의 주소정보는 유도 클래스의 가상함수 테이블에 미포함
    //때문에 오버라이딩 된 가상함수를 호출하면, 무조건 가장 마지막에 오버라이딩을 한 유도 클래스의 멤버함수가 호출
    {
        cout<<"BBB::Func1" <<endl;
    }
    void Func3()
    {
        cout <<"Func3" << endl;
    }
};

int main(void)
{
    AAA * aptr = new AAA();
    aptr->Func1();
    
    BBB * bptr = new BBB();
    bptr->Func1();
    return 0;
}