
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

class Queue
{
    public:
        Container* front;
        int length;
        
        Queue();
        void enqueue(int data);
        int dequeue();
        
        int get_size();
        void print_queue();
        bool isEmpty();
        bool isFULL();
};
    
Queue::Queue(){
    this->front = NULL;
    this->length = 0;
}
void Queue::enqueue(int data){
    if( front == NULL)
    {
        front = new Container(data);
    }
    else
    {
        Container* cur = front;
        while(cur->get_next() != NULL)
            {
                cur = cur->get_next();
            }
        Container* temp = new Container(data);
        cur->set_next(temp); 
    }
    length++;
}

int Queue::dequeue(){
    if(front != NULL)
        {
        // 리스트에 하나만 있는 경우
        // 그외
            if(front->get_next() == NULL)
            {
                delete front;
                front = NULL;
            }
            else
            {
                Container* cur = front;
                front = front->get_next();
                delete cur;
            }
        }
    length--;
}

int Queue::get_size(){
    return length;
}

void Queue::print_queue(){
    Container* cur = front;
        while(cur != NULL)
        {
            std::cout << cur->get_contents() << ", ";
            cur = cur->get_next();
        }
       std::cout << std::endl;
    
}


int main() {
    Queue que;
    que.enqueue(1);
    que.enqueue(2);
    que.enqueue(3);
    que.print_queue();
    que.dequeue();
    que.enqueue(4);
    que.enqueue(5);
    que.print_queue();
    cout << "length: " << que.get_size() << endl;
}