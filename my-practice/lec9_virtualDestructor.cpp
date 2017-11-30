#include<iostream>
using namespace std;

class Fisrt
{
private:
    char *strOne;
public:
    First(char * str)
    {
        strone=new char[strlen(str)+1];
    }
    ~First()
    {
        cout<<"~First()"<<endl;
        delete []strOne;
    }
};

class Second :public Fisrt
{
private:
    char * strTwo;
public:
    Second(char * str1, char * str2) : First(str1)
    {
        strTwo=new char[strlen(str2)+1];
    }
    ~Second()
    {
        cout<<"~Second()"<<endl;
        delete []strTwo;
    }
}