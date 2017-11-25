#include <iostream>
using namespace std;

class Human{
    
private:// Personal information
    int age;
    double height;
    char* name;
    
public:// Initialization
    Human();// 기본 생성자
    Human(int,double,char*);

    //Member function
    void AskName(Human);
    void AskAge(Human);
    int GetAge();
    char* GetName();
    void What_is_your_name();
    void How_old_are_you();

private://Private function
    void Aging();
    void Growing();
};

int Human::GetAge()//human 객체 안에 있는 멤버 함수 중 GetAge()에 대한 기능
{
    return age;//함수의 기능, age값을 반환
}

char* Human::GetName()//human 객체 안에 있는 멤버 함수 중 GetName()에 대한 기능
{
    return name;//함수의 기능, name값을 반환
}

void Human::AskName(Human other_person){
    cout<<GetName()<<":"<<"Hi,What is your name?" << endl;
    other_person.What_is_your_name();
}

void Human::AskAge(Human other_person){
    cout<<GetName()<<":"<<"How old are you?"<<endl;
    other_person.How_old_are_you();
}

void Human::What_is_your_name(){
    cout<<GetName()<<":"<<"Hello,I am"<<" "<<GetName()<<endl;
}

void Human::How_old_are_you(){
    cout<<GetName()<<":"<<"I am"<<" "<<GetAge()<<"."<<endl;
}

Human::Human()//Default Constructor
{
    age = -1;
    height = 0.0;
    name = "";
}

Human::Human(int Age,double Height, char* Name)
{
    age = Age;
    height = Height;
    name = Name;
}

void Human::Aging()
{
    age++;
}

void Human::Growing()
{
    height += 0.5;
}

int main(){
    Human jihyun(21,50,"Lee Ji Hyun");
    Human jimin(21,68,"Lee Ji Min");
    
    cout << "Greeting"<<endl;
    jihyun.AskName(jimin);
    jimin.AskName(jihyun);
    jihyun.AskAge(jimin);
    jimin.AskAge(jihyun);
}