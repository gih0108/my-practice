#include<iostream?
using namespace std;
#define MAX 10

class record{
    public:
    char name[MAX];
    
    private:
    int course1, course2;
    double avg;
    
    public:
    record();
    void print(void);
};

vpod record::print(void)
{
    
}

record::record(){
    strcpy(name,"");
    course1 = course2 =100;
    avg = 100;
}

int main(){
    record myRecord = record::record();
    record hisRecord = record();
    record herRecord;
    
    myRecord.print();
    hisRecord.print();
    herRecord.print();
    return 0;
}