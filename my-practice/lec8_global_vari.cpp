#include<iostream>
#include<string.h>
using namespace std;

int count = 1; //전역 변수로 count 변수 설정, 1로 초기화

class student{ // student라는 클래스 생성
    char name[20];//이름을 저장할 수 있는 배열 공강 생성(20 크기 만큼)
    int age;//나이에 관련된 숫자를 저장할 수 있는 공간이 int만큼 생성

public: // public으로 생성해 줌으로써 모든 함수가 접근 가능, 컴퓨터도 볼 수 있음
    student(char* _name, int _age){ // 생성자 생성, name과 age를 argument로 함
        strcpy(name, _name);//_name에 받은 문자를 name에 복사
        age = _age; // _age에 받은 숫자를 age에 저장, 할당(초기화)
        cout << count++ << "th student" <<endl;
        }//후위증가 이기때문에 count=1이 먼저 출력된 다음, 그 다음에 1이 증가된 2가 출력됨
    void print1(void); // public에 print함수 선언
    void print2(void);// public에 print함수 선언
    
}; // student class종료

void student::print1(void){ //print1함수의 기능(student s1의 이름과 나이를 출력)
    cout << "student s1 :" << name <<"," << age << endl;
    }
void student::print2(void){ //print2함수의 기능(student s2의 이름과 나이를 출력)
    cout << "student s2 :" << name <<"," << age << endl;
    
}

int main() // main함수 
{
    student s1("LEE", 21);//student 클래스의 s1객체, 각 argument들이 객체 생성과 동시에 초기화
    student s2("Jeong", 23);//student 클래스의 s2객체, 각 argument들이 객체 생성과 동시에 초기화
    
    s1.print1();//s1객체의 print1함수를 불러서 print1함수의 기능인 이름과 나이 출력(s1객체에 있었던 이름과 나이가 출력됨)
    s2.print2();//s2객체의 print2함수를 불러서 print2함수의 기능인 이름과 나이 출력(s2객체에 있었던 이름과 나이가 출력됨)
    
  
    return 0;
}