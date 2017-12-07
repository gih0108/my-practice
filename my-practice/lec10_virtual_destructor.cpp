#include<iostream>
#include<string.h>
using namespace std;

class Parent{
    char* familyName;
public:
    Parent(char* _familyName){ //Constructor
        familyName=new char[strlen(_familyName)+1];//메모리 동적할당, familyName에 _familyName+null만큼의 배열길이로 char형만큼 할당
        strcpy(familyName, _familyName);//_familyName에 들어온 메모리를 familyName에 복사
    }
    ~Parent(){//Destructor
        cout << "~Parent()" <<endl//소멸자는 보이지 않기 때문에 일부러 출력결과를 확인해주는 코드를 작성
        delete familyName;//Parent함수에서 할당해 준 메모리 공간을 소멸자를 통해서 삭제시켜줌
    }
    virtual void PrintName(){//가상함수로 선언된 PrintName함수
        cout << familyName <<",";//PrintName함수의 기능
    }
};//class 끝

class Child:public Parent{//Child 클래스에 Parent클래스 상속
    char * name;//변수 설정
public:
    Child(char* _familyName,char* _name) : Parent(_familyName){//Child 클래스와 상속 받은 Parent클래스 초기화, 멤버 이니셜라이저
        name = new char[strlen(_name)+1];
        strcpy(name,_name);
    }
    ~Child(){
        cout << "~Child()" <<endl;
        delete name;
    }
    virtual void PrintName(){
        Parent::PrintName();
        cout <<name <<endl;
    }
};

int main(){

Parent * parent = new Child("KIM","JH");
Child * child = new Child("KIM","HS");
parent->PrintName();
child->PrintName();
cout <<endl;
delete child;
cout <<endl;
delete parent;

return 0;
}

//주석달기!