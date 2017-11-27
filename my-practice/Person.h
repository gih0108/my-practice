#pragma once
#include <iostream>
#include <cstring>
//#include <stdlib.h>

class Person{

public:
    Person();
  
    
    Person(int age)
    :m_age(age), m_name(NULL)
    {
        //m_age = age;
        //m_name = NULL;
        
        std::cout << "Age Constructor" << std::endl;
        std::cout << m_count << std::endl;
        m_count++;
    }
    
    Person(int age, const char* name):m_age(age)
    {
        // m_name = name; - X
        m_name = new char[strlen(name)+1];
        strcpy(m_name, name);
        
        std::cout << "Age, Name Constructor" << std::endl;
        std::cout << m_count << std::endl;
        m_count++;
    }
    
    ~Person()
    {
        std::cout << "Destructor" << std::endl;
        if(m_name != NULL)
            delete [] m_name;
    
        std::cout << m_count << std::endl;
        m_count--;
        
    }
    
private:
    int   m_age;
    char* m_name;
    
    static int m_count;
};



