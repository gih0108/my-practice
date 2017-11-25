#include<iostream>
#include<string.h>
using namespace std;

class student{
    public:
    int id;
    student(int i = 0);
    static void printCount();
    
    private:
    static int count;
};

int student::count = 0;

student::student(int i){
    id = i;
    count++;
}

void student::printCount(){
    cout << "count = " << count <<endl;
}

int main(){
    student myID = 21600555;
    myID.printCount();
    student yourID;
    myID.printCount();
    student hisID, herID;
    student::printCount();
}