#include<iostream>
using namespace std;

class Parent{
public:
    virtual void vpr()
    {
        cout <<"vpr.parent" <<endl;
    }
    void nvpr()
    {
        cout <<"nvpr.parent" <<endl;
    }
};

class Child:public Parent{
public:
    void vpr()
    {
        cout<<"vpr.child"<<endl;
        
    }
    void nvpr()
    {
        cout <<"nvpr.child"<<endl;
    }
};

int main(void)
{

    Parent father;
    Child son;
    
    father.vpr() -> vpr.parent;
    father.nvpr() -> nvpr.parent;
    
    Parent *par_pt = &son;
}

//error