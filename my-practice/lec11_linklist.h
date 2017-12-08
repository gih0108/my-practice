#pragma once

class IntergerNode
{
private:
    IntergerNode();
    
public:
    IntergerNode(int val, IntergerNode* next);

public:
    int get_value() { return value; }
    IntergerNode* get_next() { return pNext; }
    
private:
    int value;
    IntergerNode* pNext;
};
 