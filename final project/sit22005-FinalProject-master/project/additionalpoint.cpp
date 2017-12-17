#include <iostream>

#include "linkedlist.h"
#include "queue.h"
#include "stack.h"

int main()
{ {// Additional Points
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