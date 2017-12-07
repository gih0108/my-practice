#include<iostream>
#include<string.h>
using namespace std;

class Human{//부모 클래스
private:
    int age;
    char name[10];
    char hobby[20];
public:
    Human(int _age, char * _name, char * _hobby):age(_age)//멤버 이니셜라이저->바로 초기화를 진행
    //멤버 이니셜라이저는 생성자의 몸체 부분보다 먼저 실행된다는 특징을 가지고 있음
    {
        strcpy(name, _name);
        strcpy(hobby, _hobby);
    }
    
    void getup()
    {
        cout << "기상!" << endl;
    }
    void eat()
    {
        cout << "식사!" << endl;
    }
    void study()
    {
        cout << "공부!" << endl;
    }
    
    void showInfo()
    {
        cout << "이름:" << name << endl;
        cout << "나이:" << age << endl;
        cout << "취미:" << hobby << endl;
    }

};

class Student:public Human{//public으로 상속되었기 때문에 private은 상속되지 않음
//Student 클래스는 자식 클래스
private:
    char school[30];
public:
    Student(int _age, char * _name, char * _hobby, char * _school):Human(_age,_name,_hobby)//멤버 이니셜라이저
    //Student 클래스에서 Human 클래스 내에 매개변수가 있는 생성자를 호출하여 _age, _name, _hobby를 각각 넘겨 age,name,hobby를 초기화
    {
        strcpy(school,_school);
    }
    void schoolInfo()
    {
        showInfo();
        cout << "소속 학교:" <<school << endl;
    }
};

int main()
{
    Student stu(21,"이지현","프로그래밍","한동대학교");//Student클래스 내에서 Human클래스 내의 함수까지 호출
    //Human클래스를 상속 받았기 때문에 가능
    
    stu.schoolInfo();
    stu.getup();
    stu.eat();
    stu.study();
    stu.sleep();
    
    return 0;
}