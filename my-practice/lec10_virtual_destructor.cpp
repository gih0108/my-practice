#include<iostream>
#include<string.h>
using namespace std;

class Parent{
    char* familyName;
public:
    Parent(char* _familyName){
        familyName=new char[strlen(_familyName)+1];
        strcpy(familyName, _familyName)
    }
    ~Parent(){
        cout << "~Parent()" <<endl;
        delete FamilyName;
    }
    virtual void PrintName(){
        cout << familyName <<",";
    }
};

class Child:public Parent{
    char * name;
public:
    Child(char* _familyName,char* _name) : Parent(_familyName){
        name = new char[strlen(_name)+1];
        strcpy(name,_name);
    }
    ~Child(){
        cout << "~Child()" <<endl;
        delete name;
    }
    virtual void PrintName(){
        Parent::PrintName();
        cout <<name <<endl;
    }
};

int main(){

Parent * parent = new Child("KIM","JH");
Child * child = new Child("KIM","HS");
parent->PrintName();
child->PrintName();
cout <<endl;
delete child;
cout <<endl;
delete parent;

return 0;
}