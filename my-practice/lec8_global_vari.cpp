#include<iostream>
#include<string.h>
using namespace std;

int count = 1;

class student{
    char name[20];
    int age;

public:
    student(char* _name, int _age){
        strcpy(name, _name);
        age = _age;
        cout << count++ << "th student" <<endl;
    }
};

int main()
{
    student s1("LEE", 21);
    student s2("Kim", 23);
    
    return 0;
}