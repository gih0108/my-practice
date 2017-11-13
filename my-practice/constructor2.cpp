#include<iostream>
using namespace std;

class SimpleClass
{
private:
    int num1;
    int num2;

public:
    SimpleClass(int n1 =0, int n2 =0)
    {
        num1 = n1;
        num2 = n2;
    }
    void ShowData() const
    {
        cout << num1<< ' ' << num2 << endl;
    }
};

int main(void)
{ 
    SimpleClass sc1();// main 함수 내에 지역적으로 함수의 원형이 선언, 이는 30행에 정의되어 있는 함수의 호출을 위한 것이다.
    SimpleClass mysc = sc1();
    mysc.ShowData();
    return 0;
}

SimpleClass sc1()
{
    SimpleClass sc(20,30);
    return sc;
}