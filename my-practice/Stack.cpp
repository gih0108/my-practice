
#include <iostream>

using namespace std;

class Container{
public:
    Container(int num):contents(num), pNext(NULL){}  

public:
    void set_contents(int num){ contents = num; }
    int get_contents() { return contents; }

    void set_next(Container* next){ pNext = next;}
    Container* get_next() { return pNext; }

private:
    int contents;
    Container* pNext;
};


class Stack {
    public:
        Container* top;
        int length;

        Stack();

        void push(int data);
        int pop();
        int get_size();
        void print_stack();
        bool isEmpty();
        bool isFULL();
        
};

Stack::Stack() {
    this->top = NULL;
    this->length = 0;
}

void Stack::push(int data){
    if(this->top == NULL) {
        this->top = new Container(data);
    } else {
        Container* cur = new Container(data);
        cur->set_next(this-> top);
        top = cur;
    }
    length++;
}

int Stack::pop() {
    if(this->top != NULL)
        {
            if(this->top->get_next() == NULL)
            {
                delete top;
                top = NULL;
            }
            else
            {
                Container* cur = top;
                top = top->get_next();
                delete cur;
            }
        }
    length--;
}

int Stack::get_size(){
    return length;
}

void Stack::print_stack(){
    
    Container* cur = top;
        while(cur != NULL)
        {
            std::cout << cur->get_contents() << ", ";
            cur = cur->get_next();
        }
       std::cout << std::endl;
    
    
    
}
int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);


    stack.pop();
    stack.push(4);
    stack.print_stack();

    cout << "length: " << stack.getsize() << endl;

    stack.push(10);
    stack.push(11);
    stack.push(12);
    stack.print_stack();
}

//stack = first in, last out(먼저 들어온것이 아래로 쌓이고 나중에 들어올수록 위로 쌓인다, 위에서부터 차래로 pop됨)