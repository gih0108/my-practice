#include "queue.h"

void queue::push(int val)
{
    InsertToBack(val);
}

int queue::pop()
{
    if(!isEmpty())
  {
      return RemoveFromFront_Integer();
  }
  else{
      std::cout << "Empty" << std::endl;
      return 0;
  }
    
}

int queue::front()
{
    Node* cur = find_prev_node(nullptr);
    IntegerNode* inode = static_cast<IntegerNode*>(cur);
    return inode->get_value();
}
    


void queue::print(std::ostream& os)
{
    std::cout << "-----------------------------------" << std::endl;
    linkedlist::print(os);
    std::cout << "-----------------------------------" << std::endl;
}