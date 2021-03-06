#include<iostream>
using namespace std;

class point{
    public:
    int x,y;
    
    point(int _x, int _y){
        x = _x; 
        y = _y;
    }//constructor
    
    point(const point &pt){
        x = pt.x; 
        y = pt.y;
    }//copy constructor
    //참조자를 선언해 줌으로써 새로운 공간이 할당되게 만들어줌
    
    void set(int _x, int _y){
        x = _x; 
        y = _y;
    }
    void print();
};

void point::print(){
    cout<<x<<","<<y<<endl;
}

int main(){
    point p1(1,1); // p1.x = 1, p1.y = 1
    point p2(p1);//p1객체 value 가져와서 초기화, p2 = p1
    p1.set(2,2);// p1.x=2, p1.y=2 / p2.x=1, p2.y=1
    cout << "P1:";
    p1.print();
    cout << "P2:";
    p2.print();
    
    return 0;
}

/*output:
P1:2,2
P2:1,1
*/