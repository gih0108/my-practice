#include<iostream>
#include<string.h>
using namespace std;

class First //First 라는 이름의 클래스 설정
{
private: 
    char *strOne;// 포인터 변수를 private으로 설정
public:
    First(char * str) //First함수
    {
        strOne=new char[strlen(str)+1];//미리 설정해 놓은 포인터 변수에 First함수에 들어오는 parameter의 값+null만큼 공간 할당
        cout<<str<<endl;//str의 값 출력해주는 코드
        
    }
    virtual ~First()
    {
        cout<<"~First()"<<endl;
        delete []strOne;
    }
};

class Second :public First
{
private:
    char * strTwo;
public:
    Second(char * str1, char * str2) : First(str1)
    {
        strTwo=new char[strlen(str2)+1];
        cout<<str1<<","<<str2<<endl;
    }
    virtual ~Second()
    {
        cout<<"~Second()"<<endl;
        delete []strTwo;
    }
};

int main(void)
{
    First * ptr = new Second("simple","complex");
    //virtual이 선언되면 포인터의 자료형을 기반으로 호출대상을 결정하지 않고, 포인터 변수가 실제로 가르키는 객체를 호출대상으로 함
    cout<<ptr<<endl;
    delete ptr;
    return 0;
}