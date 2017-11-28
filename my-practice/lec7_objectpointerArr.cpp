#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;

class Person
{
    private:
        char * name;
        int age;
        
    public://public에 함수를 정의하고 함수의 기능들도 동시에 코딩
        Person(char* myname, int myage)
        {
            int len = strlen(myname)+1;
            name = new char[len];
            strcpy(name,myname);
            age=myage;
            
        }
        Person()//배열 생성시 필요한 생성자를 추가, 생성자 호출 시 호출되는 함수
        {
            name = NULL;
            age=0;
            cout<<"called Person()" <<endl;
        }
        void SetPersonInfo(char * myname, int myage)
        //원하는 데이터로의 초기화를 목적으로 정의된 함수
        {
            name=myname;
            age=myage;
        }
        void ShowPersonInfo() const
        {
            cout<<"이름: " << name <<"," ;
            cout<<"나이: " << age << endl;
        }
        ~Person()//객체의 소멸자 호출 시 호출되는 함수
        {
            delete []name;
            cout <<"called destructor!" <<endl;
        }
};

int main(void)
{
    Person * parr[3];//포인터 배열이 선언, 이는 객체의 주소 값 3개를 저장할 수 있는 배열임
    char namestr[100];
    int age;
    
    for(int i = 0;i<3;i++)
    {
        cout<<"이름: ";
        cin>>namestr;
        cout<<"나이: ";
        cin>>age;
        parr[i]=new Person(namestr,age);//객체를 생성, 이 객체의 주소 값을 배열에 저장
    }
    
    parr[0]->ShowPersonInfo();
    parr[1]->ShowPersonInfo();
    parr[2]->ShowPersonInfo();
    
    //총 3회에 걸쳐 new연산을 진행했으므로 총 3회에 걸쳐 delete연산을 진행해야 함
    delete parr[0];
    delete parr[1];
    delete parr[2];
    return 0;
}
