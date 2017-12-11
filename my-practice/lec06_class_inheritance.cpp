#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>

class human{
    private:
    char* name;
    int age;
    char* hobby;
    char* school;

    public:
    human(char* _name,int _age,char* _hobby,char * _school): name(_name), age(_age), hobby(_hobby),school(_school){}
    //멤버 이니셜라이저를 반드시 써야하는 경우: 
    //상수 멤버가 있을 때
    //레퍼런스 멤버가 있을 때
    //멤버의 생성자를 호출해야 할 때
    //상속받은 클래스일 경우 부모의 생성자를 호출해야할 때
    
    void Showinfo(){
    std::cout<<name<<","<<age<<","<<hobby<<","<<school<<std::endl;
        
    }
    
    void Study(){
        std::cout<<"공부해라"<<std::endl;
    }
    
};

class student:public human{ //상속
    private:
        char school[30];
    public:
    student(char* _name,int _age,char* _hobby,char* _school):human(_name,_age,_hobby,_school){ //상속 
    //상속받은 human 안에서 _name, _age, _hobby, _school을 인자로 전달하는 생성자를 호출하라
        strcpy(school,_school);
    }
    /*
    void Schoolinfo(){
        //Showinfo();
        std::cout<<school<<std::endl;
    }*/
};

int main(){
    student stu("이지현",21,"혼자놀기","한동");
    //stu.Schoolinfo();
    stu.Showinfo();
    stu.Study();

    
    return 0;
}
    
/*output:
이지현,21,혼자놀기,한동
공부해라
*/
