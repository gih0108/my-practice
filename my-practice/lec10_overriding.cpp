#include<iostream>
using namespace std;

class Parent{
public:
    void print(){
        cout << "I'm your father" << endl;
    }
};

class Child:public Parent{
public:
/*
    void print(){
        cout << "I'm your son" <<endl;
    }
    */
    void print(int i =1){
        for(int j=0;j<i;j++)
            cout << "I'm your son."<<endl;
    }
};

int main()
{
    Child child;
    child.print();
    return 0;
}