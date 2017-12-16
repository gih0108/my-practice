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
        for(int i = 0; i <12; i++)
            ll.RemoveFromBack_Integer();
        
        ll.print(std::cout);    
    }
    std::cout << std::endl;
    /*
    {
        std::cout << "Test Linked List" << std::endl;
        linkedlist ls;
        ls.InsertToFront("a");
        ls.InsertToFront("b");
        ls.InsertToFront("c");
        ls.print(std::cout);
        
        ls.InsertNextTo("b","ko");
        ls.print(std::cout);
        ls.RemoveNode("c");
        ls.print(std::cout);
        
    }*/
    {// Test Case 02
        std::cout << "Test Stack" << std::endl;
        int index = 0;
        stack s;
        for(int i = 0; i < 10; i++)
            s.push(index++);
        
        s.print(std::cout);
        s.pop();
        //std::cout<<s.top()<<std::endl;
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
    
    {// Additional Points
        std::cout << "Additional Points" << std::endl;
        std::cout << "Insert number 1 ~ 10" << std::endl;
        linkedlist ad;
        
        
        int index = 10;
        ad.InsertToFront(index--);
        ad.InsertToFront(index--);
        ad.InsertToFront(index--);
        ad.InsertToFront(index--);
        ad.InsertToFront(index--);
        ad.InsertToFront(index--);
        ad.InsertToFront(index--);
        ad.InsertToFront(index--);
        ad.InsertToFront(index--);
        ad.InsertToFront(index--);
        
        ad.print(std::cout);
        std::cout << "Remove Node which contains 5" << std::endl;
        ad.RemoveNode(5);
        ad.print(std::cout);
        std::cout << "Insert Node with value 11 next to node which contains value 9" << std::endl;
        ad.InsertNextTo(9,11);
        ad.print(std::cout);
        
    }
    return 0;
}
