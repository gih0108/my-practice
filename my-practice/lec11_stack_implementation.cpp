#include<iostream>

using namespace std;

typedef struct
{
    int key;
    
}Element;

typedef struct
{
    Element *stack;
    int max_size;
    int top;
}Stack;

Stack *CreateStack(int max_stack_size)
{
    Stack * s = (Stack*)malloc(sizeof(Stack));
    s->stack = (Element*)malloc(max_stack_size*sizeof(Element));
    s->max_size=max_stack_size;
    s->top =-1;
    return s;
}

Stack *DuplicateStack(Stack* original)
{
    Stack *s = CreateStack(original->max_size);
    s->maz_size = original->max_size;
    s->top = original->top;
    for(int i=0;i<s->top+1; i++)
        s->stack[i]=original->stack[i];
    return s;
}

void Push(Stack *s, Element item)
{
    if(IsFullStack(s))
        print("Stack Full\n");
    else{
        s->stack[++s->top] = item;
    }
}

void DestroyStack(Stack *s)
{
    free(s->stack);
    free(s);
    s = NULL;
}

Element Pop(Stack *s)
{
    if(IsEmptyStack(s))
        print("Stack Empty\n");
    else{
        return s->stack[s->top--];
    }
}