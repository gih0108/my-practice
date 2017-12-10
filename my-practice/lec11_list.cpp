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
    std::string& get_name()//get_name은 string이라는 데이터 타입이 참조하는 값을 반환해주는 함수 기능
    { 
        return m_name;
        
    }
    
    std::string say_something()//string이라는 데이터 타입의 say_something 또한 반환해줌
    { 
        return m_name;
        
    } 
    
protected:
    std::string m_name; //string이라는 데이터 타입의 m_name이라는 변수
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
Animal p1("Jimin");
ICTer p2("Jeong San");
std::cout<<p.say_something()<<std::endl;
std::cout<<p1.say_something()<<std::endl;
std::cout<<p2.say_something()<<std::endl;
Thing *c = new Person("Jihyun");
Thing *c1 = new Animal("Jimin");
Thing *c2 = new ICTer("Jeong San");
std::cout<<c->say_something()<<std::endl;
std::cout<<c1->say_something()<<std::endl;
std::cout<<c2->say_something()<<std::endl;
delete c;
delete c1;
delete c2;
}