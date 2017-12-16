#pragma once

#include <iostream>

/**
 * Class Name: Node
 * Description:
 *  Following class is the base class for a container. 
 *  The container for a linked list may contain various data types. However, the behaviors of the linked lists are the same. 
 *  Therefore, you may define a base class for a container and extend it.
 */
 
typedef enum {INT_NODE = 0, STRING_NODE = 1} NodeType;
 
class Node // Inheritance as Extension
{
private:
    Node(){}
    
public:
    Node(Node* next, NodeType _type = INT_NODE);
    
public:
    Node* get_next() { return pNext; }
    void set_next(Node* next) { pNext = next; }

    NodeType get_node_type() { return node_type; }
protected:
    Node* pNext;
    NodeType node_type;
};

/**
 * Class Name: IntegerNode
 * Description:
 *  Following class is a derived class from the base class Node. The container stores an integer value.
 */
class IntegerNode: public Node
{
private:
    IntegerNode();
    
public:
    IntegerNode(int val, Node* next);
    
public:
    int get_value();
    void set_value(int val);
    
private:
    int value;
};

/**
 * Class Name: StringNode
 * Description:
 *  Following class is a derived class from the base class Node. The container stores a string value.
 */
class StringNode: public Node
{
private:
    StringNode();
    
public:
    StringNode(char* val, Node* next);
    virtual ~StringNode();
    
public:
    char* get_value();
    void set_value(char* val);

private:
    char* value;
};

/**
 * Class Name: linkedlist
 * Description:
 *  Following class is controller for linked list.
 */
class linkedlist
{
public:
    linkedlist();
    
    void InsertToFront(int val);
    void InsertToBack(int val);
    int RemoveFromFront_Integer();
    int RemoveFromBack_Integer();
    
    void InsertToFront(char* val);
    void InsertToBack(char* val);
    char* RemoveFromFront_String();
    char* RemoveFromBack_String();
    
    Node* find_prev_node(Node* next_node);
    
    bool isEmpty();

public: // additional proint
    void InsertNextTo(int find_val, int val);
    void InsertNextTo(char* find_val, char* val);
    void RemoveNode(int val);
    void RemoveNode(char* val);
    Node* find_node(int val);
    Node* find_node(char* val);

public:
    Node* get_head(){ return pHead; }
    virtual void print(std::ostream& os);
    
protected:
    Node* pHead;
};