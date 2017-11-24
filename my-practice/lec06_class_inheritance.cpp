#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>

class human{
    private:
    char* name;
    int age;
    char* hobby;

    public:
    human(char* _name,int _age,char* _hobby):name(_name),age(_age),hobby(_hobby){}//멤버 이니셜라이저
    void Showinfo(){
    std::cout<<name<<","<<age<<","<<hobby<<std::endl;}
    
    void Study(){
        std::cout<<"공부"<<std::endl;
    }
    
};

class student:public human{ //상속
    private:
        char school[30];
    public:
    student(char* _name,int _age,char* _hobby,char* _school):human(_name,_age,_hobby){ //상속 
        strcpy(school,_school);
    }
    void Schoolinfo(){
        Showinfo();
        std::cout<<school<<std::endl;
    }
};

int main(){
    student stu("이지현",21,"그림","한동");
    stu.Showinfo();
    stu.Study();

    
    return 0;
}
    
    