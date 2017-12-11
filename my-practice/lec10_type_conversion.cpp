#include<iostream>
using namespace std;

class Person//기초 클래스
{
public:
    void Sleep()
    {
        cout << "Sleep" <<endl;
    }
};

class Student : public Person
{
public:
    void Study()
    {
        cout << "Study" << endl;
    }
};

class Undergraduate : public Student
{
public:
    void Research()
    {
        cout << "Research" << endl;
    }
};

int main()
{
    /*
    Person *p1 = new Student;
    Person *p2 = new Undergraduate;
    Student *p3 = new Undergraduate;
    */
    Person * p1 = new Person;
    Person * p2 = new Student;
    Person * p3 = new Undergraduate;
    
    p1 ->Sleep();
    p2 ->Sleep();
    p3 ->Sleep();
    return 0;
}

/* output : 
Sleep
Sleep
Sleep
*/
