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
        name = new char[strlen(_name)+1];//
        strcpy(name,_name);//name도 마찬가지로 공간 동적할당 및 복사 
    }
    ~Child(){
        cout << "~Child()" <<endl;
        delete name;//위와 같은 방법으로 소멸자 생성 및 소멸됨을 알 수 있게 해주는 출력결과 코딩
    }
    virtual void PrintName(){ //가상함수
        Parent::PrintName();//PrintName이 다형성이기 때문에 원하는 출력결과가 나올 수 있도록 해줌
        cout <<name <<endl;
    }
};

int main(){

Parent * parent = new Child("KIM","JH");//Parent자료형 *parent 포인터 변수에 Child 변수공간을 할당해줌과 동시에 초기화
Child * child = new Child("KIM","HS");//Chile자료형 *child 포인터 변수에 Child 변수공간을 할당해줌과 동시에 초기화시켜줌
parent->PrintName();//parent 포인터의 PrintName함수를 불(상속받았음에도 불구하고)
child->PrintName();//child 포인터의 PrintName함수를 불러옴
cout <<endl;
delete child;//동적할당 해준 공간 소멸
cout <<endl;
delete parent;//동적할당 해준 공간 소멸

return 0;
}

