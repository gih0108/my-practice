#include<iostream>
using namespace std;

class BaseOne
{
public:
    void SimpleFuncOne()
    {
        cout<<"BaseOne" <<endl;
    }
};

class BaseTwo
{
public:
    void SimpleFuncTwo()
    {
        cout<<"BaseTwo"<<endl;
    }
};

class MultiDerived:public BaseOne, protected BaseTwo//상속의 대상이 되는 클래스를 구분해서 명시
{
public:
    void ComplexFunc()
    {
        //다중상속을 했기 때문에 가능한 일
        SimpleFuncOne();
        SimpleFuncTwo();
    }
};

int main(void)
{
    MultiDerived mdr;
    mdr.ComplexFunc();
    return 0;
}