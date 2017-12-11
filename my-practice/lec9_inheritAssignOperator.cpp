#include<iostream>

using namespace std;

class First//기초 클래스
{
private:
    int num1, num2;//private으로 변수 설정
public:
    First(int n1=0, int n2=0):num1(n1),num2(n2)
    { }//멤버이니셜라이저, 바로 초기화 =이랑 같은 의미, constructor
        
    void ShowData() 
    {
        cout << num1 << "," <<num2 <<endl;
    }
        
    First& operator=(const First& ref)//기초 클래스에는 멤버 대 멤버 복사가 이루어지도록
    //대입 연산자 오버로딩 함
    {
        cout<<"First& operator=()"<<endl;
        num1=ref.num1;
        num2=ref.num2;
        return *this;
    }
};

class Second: public First
{
private:
    int num3, num4;
public:
    Second(int n1, int n2, int n3, int n4) : First(n1,n2), num3(n3),num4(n4)
    { }
        
    void ShowData()
    {
        First::ShowData();
        cout<<num3<<","<<num4<<endl;
    }
        
    
    Second& operator=(const Second& ref)//유도 클래스에도 멤버 대 멤버의 복사가 이루어지도록 대입 연산자를 오버로딩
    //이 부분을 주석 처리하면  First& operator=(const First& ref)부분만 출력됨
    //결과를 통해서 디폴트 대입 연산자의 특성을 알 수 있음
    {
        cout<<"Second& operator =()" <<endl;
        First::operator=(ref);//기초 클래스의 대입 연산자 호출을 명령!
        num3=ref.num3;
        num4=ref.num4;
        return *this;
            
    }
};

int main(void)
{
    Second ssrc(111,222,333,444);//Second 클래스 불러오기 위해서는 기초 클래스인 First 클래스가 호출되어야 한다(나중 호출)
    Second scpy(0,0,0,0);
    scpy=ssrc;//대입연산자 호출
    scpy.ShowData();
    return 0;
}

//이 코드의 의도 : 유도 클래스의 생성자에는 아무런 명시를 하지 않아도 기초 클래스의 생성자가 호출되지만,
//유도 클래스의 대입 연산자에는 아무런 명시를 하지 않으면, 기초 클래스의 대입 연산자가 호출되지 않는다

/*output:
Second& operator =()
First& operator=()
111,222
333,444
*/