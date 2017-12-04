#include<iostream>
#include "ArrayList.h"
using namespace std;

int main(void)
{
    List list;
    int data;
    ListInit(&list);
    
    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);
    
    cout<<"현재 데이터의 수 :" << LCount(&list) << endl;
    
    if(LFirst(&list, &data))
    {
        cout << data << endl;
        
        while(LNext(&list, &data))
            cout << data <<endl;
    }
    cout << endl;
    
    if(LFirst(&list, &data))
    {
        if(data == 22)
            LRemove(&list);
            
        while(LNext(&list, &data))
        {
            if(data == 22)
                LRemove(&list);
        }
    }
    
    cout << "현재 데이터의 수 :" <<LCount(&list) <<endl;
    
    if(LFirst(&list, &data))
    {
        cout << data <<endl;
        
        while(LNext(&list,&data))
            cout <<data <<endl;
    }
    cout <<endl;
    return 0;
    
}