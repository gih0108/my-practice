#include "Person.h"

int Person::m_count = 0;

Person::Person()
{
    std::cout << "Default Constructor" << std::endl;
    m_age = -1;
    m_name = NULL;
    
    std::cout << m_count << std::endl;
    m_count++;
}