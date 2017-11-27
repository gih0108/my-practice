#include <iostream>

#include "Person.h"

int main(int argc, char** argv)
{
    {
        int a;
        Person student;
        
        int b = int();
        Person stduent2 = Person();
        
    }
    
    {
        int a = 10;
        Person student(10);
        
        int b = int(10);
        Person student2 = Person(10);
    }
    
    Person* pStudent;
    {
        pStudent = new Person(10, "cbchoi");
    }
    
    delete pStudent;
    return 0;
}