#include <iostream>
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
        
        Point operator+(const Point &ref)//operator +라는 이름의 함수
        {
            Point pos(xpos+ref.xpos, ypos+ref.ypos);
            return pos;
        }
        
};

int main(void)
{
    Point pos1(3,4);
    Point pos2(10,20);
    Point pos3=pos1.operator+(pos2); //pos1객체의 멤버함수 operator+를 호출하면서 인자로 pos2를 전달하고 있음
    //따라서 이 두 객체의 멤버 별 덧셈결과로 새로운 Point 객체(pos3)가 만들어지고 이것이 반환되어 pos3를 초기화
    //위 과정에서 복사 생성자가 호출됨
    
    //Point pos3 = pos1+pos2;//이 방법도 가능함!일종의 약속임. 이렇게 쓰여 있으면 위와 같이 반환하라는 뜻으로 받아들임
    
    
    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
    return 0;
}

/*output : 
[3,4]
[10,20]
[13,24]
*/