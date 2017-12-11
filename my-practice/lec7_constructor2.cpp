#include<iostream>
using namespace std;

class SimpleClass
{
private:
    int num1;
    int num2;

public:
    SimpleClass(int n1 =0, int n2 =0) //constructor
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
    SimpleClass mysc = sc1(); // SimpleClass 클래스의 sc1 객체를 호출하여, 새로운 SimpleClass의 mysc 객체를 초기화 하고 있다.
    mysc.ShowData();
    return 0;
}

SimpleClass sc1() // 지역적으로 선언한 함수 
{
    SimpleClass sc(20,30); 
    return sc;
}

//생성자 이용하여 객체도 생성과 동시에 초기화 가능

/*output:
20 30
*/