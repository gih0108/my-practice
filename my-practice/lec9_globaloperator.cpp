#include<iostream>
using namespace std;

class Point
{
    private:
        int xpos, ypos;
        
    public:
        Point(int x=0, int y=0) : xpos(x) , ypos(y)
        {} //constructor, 멤버 이니셜라이저, 바로 초기화
        
        void ShowPosition() const{
            cout << '[' <<xpos<< "," <<ypos << ']' <<endl;
        }
        
        friend Point operator +(const Point &pos1, const Point &pos2);
        //21행의 함수에 대해 private 영역의 접근을 허용하기 위해서 friend선언을 함
};

Point operator +(const Point &pos1, const Point &pos2)//+연산자를 전역함수의 형태로 오버로딩 하였음.
//Point 클래스는 이 함수에 대해서 friend 선언을 하였으므로, 함수 내에서는 Point 클래스의 private멤버에 접근이 가능함
{
    Point pos(pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos); 
    return pos;
}

int main(void)
{
    Point pos1(45,15);
    Point pos2(11,21);
    //Point pos3=pos1.operator+(pos2);//pos1객체의 멤버함수 operator+를 호출하면서 인자로 pos2를 전달하고 있음
    //따라서 이 두 객체의 멤버 별 덧셈결과로 새로운 Point 객체(pos3)가 만들어지고 이것이 반환되어 pos3를 초기화
    //위 과정에서 복사 생성자가 호출됨
    
    Point pos3 = pos1+pos2;//+ 연산자가 전역함수의 형태로 오버로딩 되었으므로, + 연산은 'operator+(pos1,pos2)'로 해석됨
    //클래스의 멤버함수였을 경우 pos1.operator+(pos2)로 해석
    
    
    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
    return 0;
}

/*output:
[45,15]
[11,21]
[56,36]
*/