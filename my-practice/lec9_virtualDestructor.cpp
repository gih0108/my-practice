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
    ~First()//가상함수로 설정된 destructor(virtual destructor)
    {
        cout<<"~First()"<<endl;//virtual destructor가 실행되었음을 확인해주는 코드
        delete []strOne;//strOne에 할당된 배열 메모리 공간 삭제
    }
};

class Second :public First //Second 클래스 안에 First 클래스를 public으로 상속
{
private:
    char * strTwo;// 포인터 변수를 private으로 설정
public:
    Second(char * str1, char * str2) : First(str1)//상속 받은 멤버 변수는 이와같은 식으로 초기화 해줌
    {
        strTwo=new char[strlen(str2)+1];//미리 설정해 놓은 포인터 변수에 Second함수에 들어오는 두번째 parameter의 값+null만큼 공간 할당
        cout<<str1<<","<<str2<<endl;//str1,str2 출력해주는 코드
    }
    ~Second()//가상함수로 설정된 destructor(virtual destructor)
    {
        cout<<"~Second()"<<endl;//virtual destructor가 실행되었음을 확인해주는 코드
        delete []strTwo;//strTwo에 할당된 배열 메모리 공간 삭제
    }
};

int main(void)
{
    First * ptr = new Second("simple","complex");//Second 클래스만큼 새로운 공간 동적할당(포인터 ptr이 가리키고 있는 상황)
    //할당과 동시에 초기화해주고 있음
    cout<<ptr<<endl;//ptr의 주소값을 출력해주는 코드
    delete ptr;//ptr 메모리 공간 삭제
    return 0;
}

//virtual이 선언되면 포인터의 자료형을 기반으로 호출대상을 결정하지 않고, 포인터 변수가 실제로 가르키는 객체를 호출대상으로 함
//이 코드의 중요한 점은 소멸자가 가상함수로 설정되었다는 것임. main함수 안에서 First * ptr = new Second("simple","complex");을
//보았을 때 ptr은 Second 클래스를 가리키고 있기 때문에 Second에 먼저 가서 호출대상을 결정함
//출력결과를 보면 베이스 클래스인 First가 먼저 출력되고 유도클래스인 Second가 나중에 출력되는 것을 알 수 있으며
//호출은 Second가 먼저 되지만 출력은 가장 나중에 됨
//가상 소멸자를 보면 Second가 먼저 소멸되고 First가 나중에 소멸되는데 이는 virtual선언 때문임
//실제로 가상함수화 되어있기 때문에 포인터가 가리키고 있는~Second에 먼저가서 삭제되고 상속되어있던 First클래스의
//~First()가 나중에 삭제되는 것을 알 수 있음(Second 클래스에 First 클래스가 상속되어졌기 때문)
//만약 소멸자가 가상함수가 아니었다면 포인터 ptr의 자료형이 First이기 때문에 ~First 함수만 실행됨