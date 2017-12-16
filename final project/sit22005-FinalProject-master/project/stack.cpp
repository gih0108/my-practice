#include "stack.h"

void stack::push(int val)
{
    ll.InsertToBack(val);
}

int stack::pop()
{
  if(!ll.isEmpty())
  {
      return ll.RemoveFromBack_Integer();
  }
  else{
      std::cout << "Empty" << std::endl;
      return 0;
  }
}

int stack::top()
{
    Node* cur = ll.get_head();
    IntegerNode* inode = static_cast<IntegerNode*>(cur);
    return inode->get_value();
}

void stack::print(std::ostream& os)
{
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "|";
    ll.print(os);
    std::cout << "-----------------------------------" << std::endl;
}