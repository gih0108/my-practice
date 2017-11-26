#include<iostream>
#include<string.h>
using namespace std;

class student{
    public:
    int id;
    student(int i = 0); // student함수의 argument가 i로 선언되었고 0으로 초기화 됨
    static void printCount(); // static으로 함수 선언(static function)
    void printID();
    //student class가 공유되는 모든 곳에서 쓰일 수 있는 함수가 됨
    
    private:
    static int count;// static으로 count변수 설정, class함수가 쓰이고 공유되는 모든 곳에 쓰일 수 있는 변수가 됨
};

int student::count = 0;// student class의 static int count가 0으로 초기화
//count가 static변수 이기때문에 student class와 공유되고 있으므로 문제될 것이 없다.
//static 멤버는 무조건 class 정의 밖에서 초기화되어야 한다
//그리고 static 멤버 변수는 딱 한번 초기화 된다

student::student(int i){ // stduent class의 student함수(constructor),argument가 int i로 존재함
    id = i; // id = i의 값으로 초기화됨
    count++; // count가 후위증가
}

void student::printCount(){ // student class의 함수 & 기능 
    cout << "count = " << count << endl; // count값을 출력해주는 기능을 함
}

void student::printID(){ //student class의 함수 & 기능
    cout << "id = " << id << endl; // id값을 출력해주는 기능을 함
}

int main(){
    student myID = 21600555; // student 클래스의 object가 myID로 설정됨, 그리고 학번으로 초기화됨
    myID.printCount(); //count = 1이 출력될 것임
    myID.printID(); // 학번이 출력됨. 객체 생성시 초기화 시켰던 값이 그대로 출력됨.
    
    student yourID = 21400687; // 객체 생성, 학번으로 객체 생성 후 초기화
    myID.printCount(); // count = 1로 초기화 되었던 myID의 재초기화 -> count = 2
    //여기서 보여주려고 하는 것은 static 멤버 변수는 한 번만 초기화 된다는 것을 보여주려는 것
    yourID.printID();// 학번이 출력됨. 객체 생성시 초기화 시켰던 값이 그대로 출력됨.
    
    student hisID;//초기화 시켜준 값이 없기 때문에, student(int i = 0)을 부르고 0으로 초기화 됨.
    student herID = 21600555;//객체 생성, 학번으로 객체 생성 후 초기화
    student::printCount();//hisID와 herID가 각각 1번씩 count했으므로 총 count = 4가 됨
    //student의 printCount함수를 통째로 부름..
    
    hisID.printID();// 학번이 출력됨, hisID는 객체 생성 시 초기화 값이 없었기 때문에 
    herID.printID();// 학번이 출력됨. 객체 생성시 초기화 시켰던 값이 그대로 출력됨
    
    //student hisID;
    //myID.printCount();
    //student herID;
    //myID.printCount();
    //위 주석처리 된 것 처럼하면 그냥 각각 count가 3,4로 출력됨
}