#include <iostream>
#include <cstring>

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

class LinkedList
{
public: 
    LinkedList():pHead(NULL){ }
    ~LinkedList(){}
    
public:
    void insert_val(int num)
    {
        if( pHead == NULL)
        {
            // 1. list가 비어 있는 경우
            // Container 할당 by cbchoi
            pHead = new Container(num);
        }
        else
        {// 2. list가 비어 있지 않는 경우
            // 따라간다. by San
            Container* cur = pHead; //pHead의 member 변수 복사 
            
            while(cur->get_next() != NULL)
            {
                cur = cur->get_next();
            }
            
            // Container 할당 by cbchoi
            Container* temp = new Container(num);
            // Connect by cbchoi 
            cur->set_next(temp); 
        }
    }
    
    void insert_to_head(int num)
    {
        //1. LIST가 비어있는 경우
        if(pHead == NULL){
            pHead = new Container(num);
        }
        else{
            // 할당
            Container* cur = new Container(num);
            // 2-2 pHead 옮기기
            // 2-2-1. cur의 next를 이전 헤드 로 연결
            cur->set_next(pHead);
            // 2-2-2. cur를 새로운 헤드로 옮기기
            pHead = cur;
            
            //Container* temp=pHead;
            //pHead=cur;
            //pHead->set_next(temp);
        }
    }
    
    Container* search(int val)
    {
        Container* cur = pHead;
        
        while(cur != NULL)
        {
            if(cur->get_contents() == val)
                break;
            else
                cur = cur->get_next();
        }
        return cur;
        //return NULL;
    }
    
    void erase_contents(int val)
    {
        Container* cur = search(val);
        if(cur != NULL)
        {
            // container가 하나만 있는 경우
                // Container == pHead
            if(cur == pHead && cur->get_next() == NULL)
            {
                delete cur;
                pHead = NULL;
            }
            else
            {
                if(cur == pHead)
                {
                    remove_head();
                }
                else
                {
                    Container* cur2 = pHead;
                    while(cur2->get_next() != cur)
                    {
                        cur2 = cur2->get_next();
                    }
                    
                    cur2->set_next(cur->get_next());
                    delete cur;
                }
            }
            // container가 다수 있는 경우
                // 지우려는 대상이 Head인 경우
                // 그 외
            
        }
    }
    
    void remove_head()
    {
        // 리스트에 아무것도 없는 경우
        if(pHead != NULL)
        {
        // 리스트에 하나만 있는 경우
        // 그외
            if(pHead->get_next() == NULL)
            {
                delete pHead;
                pHead = NULL;
            }
            else
            {
                Container* cur = pHead;
                pHead = pHead->get_next();
                delete cur;
            }
        }
        
    }
    
    void print_list()
    {
        Container* cur = pHead;
        while(cur != NULL)
        {
            std::cout << cur->get_contents() << ", ";
            cur = cur->get_next();
        }
       std::cout << std::endl;
    }
private:
    Container* pHead;
};

int main(int argc, char** argv)
{
    LinkedList ll;
    
    char ch = ' ';
    int val = 99;
    while(val != -1) 
    {
        std::cout << ">>";
        std::cin >> val;
        ll.insert_val(val);
    }
    ll.print_list();
    ll.erase_contents(10);
    ll.print_list();
    return 0;
}