#include <stdio.h>
#include <iostream>
#include <cstring>

class student{
    private:
    char* name;
    int age;
    char* hobby;
    
    public:
    student(char* _name,int _age,char* _hobby);
    void Showinfo();
    void Study();
    
};
student::student(char* _name,int _age,char* _hobby){ //생성자
    name = _name;
    age = _age;
    hobby= _hobby;
}
void student::Showinfo(){
    std::cout<<name<<","<<age<<","<<hobby<<std::endl;
}
void student::Study(){
    std::cout<<"공부"<<std::endl;
}
int main(){
    
    student stu("이지현",21,"그림");
    stu.Showinfo();
    stu.Study();
    return 0;
    
    
}
    
    
    
    
    