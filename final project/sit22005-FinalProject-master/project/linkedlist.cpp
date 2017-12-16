#include "linkedlist.h"
#include <stdlib.h>
#include <cstring>

//////////////////////////////////////////////////////////////
// Node
Node::Node(Node* next, NodeType node)
:pNext(next), node_type(node)
{

}


//////////////////////////////////////////////////////////////
// IntegerNode
IntegerNode::IntegerNode()
:Node(nullptr, INT_NODE)
{
    
}

IntegerNode::IntegerNode(int val, Node* next)
:Node(next, INT_NODE), value(val)
{
    
}

int IntegerNode::get_value()
{
    return value;
}


void IntegerNode::set_value(int val)
{
    value = val;
}
//////////////////////////////////////////////////////////////
// StringNode
StringNode::StringNode()
:Node(nullptr, STRING_NODE)
{
    
}

StringNode::StringNode(char* val, Node* next)
:Node(next, STRING_NODE)
{
    value = new char[strlen(val)+1];
    strcpy(value, val);
    value[strlen(val)]='\0';
}

StringNode::~StringNode()
{
    delete [] value;
}

char * StringNode::get_value()
{
    return value;
}

void StringNode::set_value(char * val)
{
    if(value != val)
    {
        delete [] value;
        value = new char[strlen(val)+1];
        strcpy(value, val);
        value[strlen(val)] = '\0';
    }
}
//////////////////////////////////////////////////////////////
// LinkedList Manager
linkedlist::linkedlist()
:pHead(nullptr)
{
    
}

void linkedlist::InsertToFront(int val)
{
    IntegerNode* inode = new IntegerNode(val, pHead);
    pHead = inode;
}

void linkedlist::InsertToBack(int val)
{
    if(isEmpty())
    {
        InsertToFront(val);
    }
    else
    {
        Node* last_node = find_prev_node(nullptr);
        
        IntegerNode* inode = new IntegerNode(val, nullptr);
        last_node->set_next(inode);
    }
}

int linkedlist::RemoveFromFront_Integer()
{
    int temp = 0;
    if(!isEmpty())
    {
        Node* cur = pHead;
        IntegerNode* inode = static_cast<IntegerNode*>(cur);
        temp = inode->get_value();
        
        pHead = cur->get_next();
        
        delete cur;
    }
    return temp;
}

int linkedlist::RemoveFromBack_Integer()
{
    int temp=0;
    if(!isEmpty())
    {
        if(pHead->get_next() == nullptr)
        {
            IntegerNode* inode = static_cast<IntegerNode*>(pHead);
            temp = inode->get_value();
            
            delete inode;
            
            pHead = nullptr;
        }
        else
        {
            Node* last_node = find_prev_node(nullptr);
            Node* prev_node = find_prev_node(last_node);
            prev_node->set_next(nullptr);
            IntegerNode* inode = static_cast<IntegerNode*>(last_node);
            temp = inode->get_value();

            delete inode;
        }
    }
    return temp;
}



//---------------------------------------------------------------------------------------



void linkedlist::InsertToFront(char* val)
{
    StringNode* inode = new StringNode(val, pHead);
    pHead = inode;
}

void linkedlist::InsertToBack(char* val)
{
    if(isEmpty())
    {
        InsertToFront(val);
    }
    else
    {
        Node* last_node = find_prev_node(nullptr);
        
        StringNode* inode = new StringNode(val, nullptr);
        last_node->set_next(inode);
    }
}

char* linkedlist::RemoveFromFront_String()
{
    char* temp;
    if(!isEmpty())
    {
        Node* cur = pHead;
        StringNode* inode = static_cast<StringNode*>(cur);
       
        int len = strlen(inode->get_value());
        temp = new char[len+1];
        strcpy(temp,inode->get_value());
        
        pHead = cur->get_next();
        //delete cur;
        
    }
    return temp;
}

char* linkedlist::RemoveFromBack_String()
{
    char* temp;
    
    if(!isEmpty())
    {
        if(pHead->get_next() == nullptr)
        {
            StringNode* inode = static_cast<StringNode*>(pHead);
           
            int len = strlen(inode->get_value());
            temp = new char[len+1];
            strcpy(temp,inode->get_value());
           
            
            delete inode;
            
            pHead = nullptr;
        }
        else
        {
            Node* last_node = find_prev_node(nullptr);
            Node* prev_node = find_prev_node(last_node);
            prev_node->set_next(nullptr);
            StringNode* inode = static_cast<StringNode*>(last_node);
            
            int len = strlen(inode->get_value());
            temp = new char[len+1];
            strcpy(temp,inode->get_value());

            delete inode;
        }
    }
    
    return temp;
}

bool linkedlist::isEmpty()
{
    return pHead == nullptr? true:false;
}

Node* linkedlist::find_prev_node(Node* next)
{
    Node* cur = pHead;
    if(next == cur)
    {
        return nullptr;
    }
    
    while(cur->get_next() != next && cur != nullptr)
    {
        cur = cur->get_next();
    }
    
    return cur;
}

void linkedlist::print(std::ostream & os)
{
    for(Node* cur = pHead; cur!= nullptr; cur = cur->get_next())
    {
        if(cur->get_node_type() == INT_NODE)
        {
            IntegerNode* node = static_cast<IntegerNode*>(cur);
            os<<node->get_value() << " ";
        }
        else if(cur->get_node_type() == STRING_NODE)
        {
            StringNode* node = static_cast<StringNode*>(cur);
            os<<node->get_value() << " ";
        }
    }
    os <<std::endl;
}

void linkedlist::InsertNextTo(int find_val, int val)
{   
    Node* cur = find_node(find_val);
    cur = cur->get_next();
    IntegerNode* inode = new IntegerNode(val, cur);
    find_prev_node(cur)->set_next(inode);
}

void linkedlist::InsertNextTo(char* find_val, char* val)
{
    Node* cur = find_node(find_val);
    cur = cur->get_next();
    StringNode* inode = new StringNode(val, cur);
    find_prev_node(cur)->set_next(inode);
}

void linkedlist::RemoveNode(int val)
{
    Node* cur = find_node(val);
    if(cur != NULL)
        {
            
            if(cur == pHead && cur->get_next() == NULL)
            {
                delete cur;
                pHead = NULL;
            }
            else
            {
                if(cur == pHead)
                {
                    RemoveFromFront_Integer();
                }
                else
                {
                    Node* cur2 = pHead;
                    while(cur2->get_next() != cur)
                    {
                        cur2 = cur2->get_next();
                    }
                    
                    cur2->set_next(cur->get_next());
                    delete cur;
                }
            }
            
        }
}

void linkedlist::RemoveNode(char* val)
{
    Node* cur = find_node(val); 
    if(cur != NULL)
        {
            
            if(cur == pHead && cur->get_next() == NULL)
            {   
                delete cur;
                pHead = NULL;
            }
            else
            {
                if(cur == pHead)
                {   
                    RemoveFromFront_String();
                }
                else
                {
                    Node* cur2 = pHead;
                    while(cur2->get_next() != cur)
                    {
                        cur2 = cur2->get_next();
                    }
                    
                    cur2->set_next(cur->get_next());
                    
                }
            } 
            
        }
}

Node* linkedlist::find_node(int val)//Node 자료형
{
    Node* cur = pHead;
    IntegerNode* fish = static_cast<IntegerNode*>(cur);
        
        while(fish != NULL)
        {   
   
            if(fish->get_value() == val)
                break;
            else{
                cur = cur->get_next();
                fish = static_cast<IntegerNode*>(cur);
            }
        }
        return cur;
}




Node* linkedlist::find_node(char* val)
{
    Node* cur = pHead;
    StringNode* fish = static_cast<StringNode*>(cur);
        
        while(fish != NULL)
        {   
           
            if(!strcmp(val,fish->get_value()))
                break;
            else{
                cur = cur->get_next();
                fish = static_cast<StringNode*>(cur);
            }
        }
        return cur;
}