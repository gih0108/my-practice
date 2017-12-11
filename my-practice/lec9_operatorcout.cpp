#include<iostream>
using namespace std;

class Point
{
    private:
        int xpos, ypos;
        
    public:
        Point(int x=0, int y=0) : xpos(x) , ypos(y)
        {}
        
        void ShowPosition() const{
            cout << '[' <<xpos<< "," <<ypos << ']' <<endl;
        }
        
        friend ostream& operator<<(ostream&, const Point&);//point 클래스 안에 public으로 있음
};

/*
ostream& operator<<(ostream& os, const Point& pos)//ostream이라는 전연변수 설정
{
    os << '[' <<pos.xpos<< "," <<pos.ypos << ']' <<endl;//인자로 전달된 cout의 참조자를 통한 출력을 구성
    //ostream의 참조자 os를 불러냄, 참조자 pos의 xpos와 ypos 값이 각각 os로 밀려들어감, 저장됨
    return os;//cout을 대신하여 반환 값을 설정
}
*/
int main(void)
{
    Point pos1(1,3);//20행의 함수 호출, 이는 <<연산자의 오른편에 등장한 것이 Point객체이기 때문임 
    cout<<pos1; 
    Point pos2(10,303);//20행의 함수 호출, 이는 <<연산자의 오른편에 등장한 것이 Point객체이기 때문임 
    cout<<pos2;
    return 0;
}

/*output : 
error
*/