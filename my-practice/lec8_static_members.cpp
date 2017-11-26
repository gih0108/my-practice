#include<iostream>
#include<string.h>
using namespace std;

class student{
    public:
    int id;
    student(int i = 0); // student함수의 argument가 i로 선언되었고 0으로 초기화 됨
    static void printCount(); // static으로 함수 선언(static function)
    //student class가 공유되는 모든 곳에서 쓰일 수 있는 함수가 됨
    
    private:
    static int count;// static으로 count변수 설정, class함수가 쓰이고 공유되는 모든 곳에 쓰일 수 있는 변수가 됨
};

int student::count = 0;// student class의 static int count가 0으로 초기화
//count가 static변수 이기때문에 student class와 공유되고 있으므로 문제될 것이 없다.

student::student(int i){ // stduent class의 student함수(constructor),argument가 int i로 존재함
    id = i; // id = i의 값으로 초기화됨
    count++; // count가 후위증가
}

void student::printCount(){ // student class의 함수 & 기능 
    cout << "count = " << count << endl; // count값을 출력해주는 기능을 함
    //cout << "id = " << "," << id << endl;
}

int main(){
    student myID = 21600555; // student 클래스의 object가 myID로 설정됨, 그리고 학번으로 초기화됨
    myID.printCount(); 
    student yourID; 
    myID.printCount();
    student hisID, herID;
    student::printCount();
}