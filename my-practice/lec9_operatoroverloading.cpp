#include<iostream>

class ChangePocketClass
{
    
    private :
    int quarters;
    int dimes;
    
    public:
    /*
    ChangePocketClass():quarters(0),dimes(0)
    {}
    
    ChangePocketClass(int q, int d):quarters(q),dimes(d)
    {}*/
    
    ChangePocketClass(int q = 0, int d = 0):quarters(q),dimes(d)
    {}
    
    ChangePocketClass operator+(const ChangePocketClass &rhs)
    {
        ChangePocketClass pos(quarters+rhs.quarters, dimes+rhs.dimes);
        return pos;
    }
    
    
    void setQuarters(int val)
    {
        quarters = val;
    }
    
    void setDimes(int val)
    {
        dimes = val;
    }
    
    int getQuarters()
    {
        return quarters;
    }
    
    int getDimes()
    {
        return dimes;
    }
    
    
};

int  main()
{
    ChangePocketClass c1;
    ChangePocketClass c2;
    ChangePocketClass c3;
    
    c1.setQuarters(5);
    c1.setDimes(7);
    c2.setQuarters(3);
    c2.setDimes(8);
    
    //c3 = c1 + c2;
    c3 = c1.operator+(c2);
    
    return 0;
}