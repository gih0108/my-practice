#include <iostream>

#include "linkedlist.h"
#include "queue.h"
#include "stack.h"

int main()
{
    {// Test Case 01
        std::cout << "Test Linked List" << std::endl;
        linkedlist ll;
        
        int index = 10;
        ll.InsertToFront(index--);
        ll.InsertToFront(index--);
        ll.InsertToFront(index--);
        ll.InsertToFront(index--);
        ll.InsertToFront(index--);
        ll.InsertToFront(index--);
        ll.InsertToFront(index--);
        ll.InsertToBack(index--);
        ll.InsertToBack(index--);
        ll.InsertToBack(index--);
        ll.InsertToBack(index--);
        
        ll.print(std::cout);
        
        for(int i = 0; i <3; i++)
            ll.RemoveFromBack_Integer();
        
        ll.print(std::cout);    
    }
    std::cout << std::endl;
    
    {// Test Case 02
        std::cout << "Test Stack" << std::endl;
        int index = 0;
        stack s;
        for(int i = 0; i < 10; i++)
            s.push(index++);
        
        s.print(std::cout);
        s.pop();
        s.print(std::cout);    
    }
    std::cout << std::endl;
    
    {// Test Case 03
        std::cout << "Test Queue" << std::endl;
        int index = 0;
        queue q;
        for(int i = 0; i < 10; i++)
            q.push(index++);
        
        q.print(std::cout);
        q.pop();
        q.print(std::cout);    
    }
    
    std::cout << std::endl;
    
    return 0;
}
