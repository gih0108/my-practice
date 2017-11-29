#include<iostream>

class ChangePocketClass
{
    public:
    ChangePocketClass():quarters(0),dimes(0)
    {}
    
    ChangePocketClass(int q, int d):quarters(q),dimes(d)
    {}
    
    /*
    ChangePocketClass ChangePocketClass::add(const ChangePocketClass &rhs) const;
    {}*/
    
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
    
    private :
    int quarters;
    int dimes;
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
    c3 = c1.add(c2);
    
    return 0;
}