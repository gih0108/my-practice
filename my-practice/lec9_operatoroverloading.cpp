#include<iostream>

using namespace std;

class ChangePocketClass
{
    
    private :
    int quarters;
    int dimes;
    
    public:
    /*
    ChangePocketClass():quarters(0),dimes(0)
    {}
    
    ChangePocketClass(int q, int d):quarters(q),dimes(d)
    {}*/
    
    //위와 같은 방법임. 편한대로 해주면 됨
    ChangePocketClass(int q = 0, int d = 0):quarters(q),dimes(d)//메모리 공간 할당과 동시에 초기화 해주는 기능
    {}
    
    //연산자 +해주는 함수
    ChangePocketClass operator+(const ChangePocketClass &rhs)
    {
        ChangePocketClass pos(quarters+rhs.quarters, dimes+rhs.dimes);//인자로 전달된 값을 참조해서
        //c1객체의 quarters와 dimes와 c2객체의 quarters와 dimes을 더해줌
        return pos;//객체를 반환(결과 값)
    }
    
    void ShowPosition() const{//각 변수들의 값들과 덧셈이 잘 되었는지 출력해주는 함수
            cout << '[' <<quarters<< "," <<dimes << ']' <<endl;
        }
    
    //set function : 변수의 값 설정
    void setQuarters(int val)
    {
        quarters = val;
    }
    
    void setDimes(int val)
    {
        dimes = val;
    }
    
    //get function : 변수 값 반환
    int getQuarters()
    {
        return quarters;
    }
    
    int getDimes()
    {
        return dimes;
    }
    
};

int  main()
{
    //c1,c2,c3라는 메모리 공간 각각 할당
    ChangePocketClass c1;
    ChangePocketClass c2;
    ChangePocketClass c3;
    
    c1.setQuarters(5);//c1의 quarters = 5
    c1.setDimes(7);// c1의 dimes = 7
    c2.setQuarters(3);//c2의 quarters = 3
    c2.setDimes(8);//c2의 dimes = 8
    
    //c3 = c1 + c2; //이 방법도 가능
    c3 = c1.operator+(c2);//덧셈해주는 operator 함수 호출, c1객체의 멤버함수인 operator+를 호출하면서 인자로 c2전달
    //덧셈 결과로 그 값이 반환되고 c3 초기화

    c1.ShowPosition();
    c2.ShowPosition();
    c3.ShowPosition();
    
    return 0;
}