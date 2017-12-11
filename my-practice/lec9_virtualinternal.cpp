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
    void Func3()//Func3함수는 virtual 아님
    {
        cout <<"Func3" << endl;
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
    void Func3()//Func3함수는 virtual 아님
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

//이 코드에서 보여주려고 하는 것은 Func1함수가 AAA클래스와 BBB클래스에 동일하게 있기 때문에 함수 오버라이딩이 되어있는 형태인데
//가상함수이기 때문에 이와 같이 출력됨을 보여줌, 또한 AAA객체가 가리키고 있었던 AAA::Func1의 key가 BBB클래스에서 
//오버라이딩된 Func1()의 주소 값으로 바뀜. 즉, AAA의 Func1함수의 주소 값이 남아있지 않음

/*output : 
Func1
BBB::Func1
*/