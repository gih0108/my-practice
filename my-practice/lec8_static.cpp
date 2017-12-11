#include<iostream>
#include<string.h>
using namespace std;

class student{ 
    char name[20];
    int age;
    static int count; // 전역변수가 아닌 static으로 선언된 count variable
    //student class로부터 만들어진 모든 객체에 global로 작용
    //static : class의 멤버들 + class들에 공유되는 공간

public:
    student(char* _name, int _age){
        strcpy(name, _name);
        age = _age;
        cout << count++ << "th student" <<endl;
        cout << name << endl;
        cout << age << endl;
        
    }
};

int student::count =1; // 초기화를 class 밖에서 해줌
//student가 class이기 때문에 class들에 공유되어 있는 count를 밖에서 선언해주어도 문제가 없다. 

int main()
{
    student s1("Ji", 21);
    student s2("Hyun", 23);
    
    return 0;
}

/*output: 
1th student
2th student
*/