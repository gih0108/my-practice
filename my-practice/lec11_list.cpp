#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>

class Thing
{
public:
    Thing(std::string name)//constructors, string이라는 데이터 타입에 name이라는 변수이름 설정
    :m_name(name){ }//멤버 이니셜라이저
public:
    std::string& get_name()//
    { 
        return m_name;
        
    }
    
    std::string say_something()
    { 
        return m_name;
        
    } 
    
protected:
    std::string m_name; 
};//클래스 종료

class Person: public Thing //inheritance
{
public:
    Person(std::string name) 
    :Thing(name){}
    
    std::string say_something(){ 
        std::string contents;
        contents += "My name is ";
        contents += m_name;
        return contents; 
    }
};

class Animal: public Thing 
{
public:
    Animal(std::string name)
    :Thing(name)
    {
        
    }
    
    std::string say_something(){ 
        std::string contents;
        contents += "Wang Wang! ";
        contents += m_name;
        return contents; 
    }
};

class ICTer: public Thing 
{
public:
    ICTer(std::string name)
    :Thing(name)
    {
        
    }
    
    
    std::string say_something(){ 
        std::string contents;
        contents += "I love Programming 2 ";
        contents += m_name;
        return contents; 
    }
};

int main(int argc, char** argv)
{
Person p("Jihyun");
std::cout<<p.say_something()<<std::endl;
Thing *c = new Person("Jihyun");
std::cout<<c->say_something()<<std::endl;
delete c;
}