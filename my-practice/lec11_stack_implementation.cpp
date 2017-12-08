#include<iostream>

using namespace std;

class Element
{
public:
    Element();
public:
    int key;
};

class Stack
{
public:
    Stack(int max_stack_size);
    void Push(Element elem);
    Element Pop();
public:
int max_size;
int top;
Element* stack;
}

Stack::Stack(int max_stack_size)
:max_size(max_stack_size),top(-1),stack(NULL)
{
    stack = new Element[max_size];
}

Stack::Stack(const Stack& rhs)
{
    max_size = rhs.max_size;
    top=rhs.top;
    stack=new Element[max_size];
    
    if(rhs.top>=0){
        for(int i=0;i<top+1;i++)
            stack[i]=rhs.stack[i];
    }
}

Stack& Stack::operator=(const Stack& rhs)
{
    if(&rhs != this){
        max_size=rhs.max_size;
        top=rhs.top;
        stack = new Element[max_size];
        
        if(rhs.top>=0){
            for(int i=0;i<top+1;i++)
                stack[i]=rhs.stack[i];
        }
    }
    return *this;
}

void Stack::Push(Element elem)
{
    if(IsFull())
        cout << "Stack Full" <<endl;
    else{
        stack[++top] =elem;
    }
}

Stack::~Stack()
{
    delete []stack;
}

Element Stack::Pop()
{
    if(IsEmpty()){
        cout << "Stack Empty" <<endl;
        return Element();
    }
    else{
        return stack[top--];
    }
}

bool IsFull()
{
    if(top==max_size-1)
        return true;
    else
        return false;
}

bool IsEmptyStack(Stack *s)
{
    if(s->top <0)
        return 1;
    else    
        return 0;
}

void PrintStack(Stack *s)
{
    int i = 0;
    cout << "-----------------\n");
    for(i=0;i<s->top+1;i++)
    {
        cout << "s->stack[i].key");
    }
    cout << "-----------------\n");
    
}


int argc;
char * argv[];
int main(argc, argv)
{
    
}