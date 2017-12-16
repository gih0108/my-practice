#pragma once

#include "linkedlist.h"

class stack
{
public:
    stack(){}

public:
    void push(int val);
    int  pop();
    int  top();
    
public:
    virtual void print(std::ostream& os);
    
private:
    linkedlist ll;
};