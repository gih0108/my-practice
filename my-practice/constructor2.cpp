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
    SimpleClass sc1();// main 함수 내에 지역적으로 함수의 원형이 선언(함수의 원형 호출!), 이는 31행에 정의되어 있는 함수의 호출을 위한 것이다.
    // -> 이에 해당하는 함수가 나와야 함.
    SimpleClass mysc = sc1(); // sc1 함수를 호출하여, 이때 반환되는 객체의 값(sc)으로 mysc 객체를 초기화 하고 있다.
    mysc.ShowData();
    return 0;
}

SimpleClass sc1() // 지역적으로 선언한 함수 
{
    SimpleClass sc(20,30);
    return sc;
}