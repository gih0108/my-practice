#pragma once

#include "linkedlist.h"

class queue: public linkedlist
{
public:
    queue(){}
    
public:
    void push(int val);
    int  pop();
    int  front();
    
public:
    virtual void print(std::ostream& os);
};