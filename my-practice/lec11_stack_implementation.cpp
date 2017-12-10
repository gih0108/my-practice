#include<iostream>
#include <cstring>


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
};

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

bool IsEmpty()
{
    if(top <0)
        return true;
    else    
        return false;
}

void PrintStack(Stack *s)
{
    int i = 0;
    cout << "-----------------\nㅣ";
    for(i=0;i<s->top+1;i++)
    {
        cout << "stack[i].key"<<"ㅣ";
    }
    cout << "-----------------\n";
    
}

int main(int argc, char *argv[])
{
    Element elem;
    Element pop_item;
    
    Stack my_stack2(0);
    Stack my_stack(10);
    
    elem.key=2;
    cout<<"Pushed Item:"<<elem.key<<endl;
    my_stack.Push(elem);
    my_stack.PrintStack();
    
    elem.key=1;
    cout<<"Pushed Item:"<<elem.key<<endl;
    my_stack.Push(elem);
    my_stack.PrintStack();
    
    elem.key=3;
    cout<<"Pushed Item:"<<elem.key<<endl;
    my_stack.Push(elem);
    my_stack.PrintStack();
    
    pop_item=my_stack.Pop();
    cout << "Popped Item:" <<pop_item.key<<endl;
    my_stack.PrintStack();
    
    pop_item=my_stack.Pop();
    cout << "Popped Item:" <<pop_item.key<<endl;
    my_stack.PrintStack();
    
    elem.key=4;
    cout<<"Pushed Item:"<<elem.key<<endl;
    my_stack.Push(elem);
    my_stack.PrintStack();
    
    my_stack2=my_stack;
    my_stack2.PrintStack();
    
    return 0;
}

//error
