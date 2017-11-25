#include<iostream>
#include<string.h>
using namespace std;

class student{
    char name[20];
    int age;
    static int count;

public:
    student(char* _name, int _age){
        strcpy(name, _name);
        age = _age;
        cout << count++ << "th student" <<endl;
    }
};

int student::count =1;

int main()
{
    student s1("Ji", 21);
    student s2("Hyun", 23);
    
    return 0;
}