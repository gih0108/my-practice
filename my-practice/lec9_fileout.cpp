#include<iostream>
#include <fstream>
//#include <cstring>
//#include <sstream>
//#include <stdlib.h>

using namespace std;

int iObj1;
int iObj2;

int main(void)
{
    ofstream outFile;
    
    outFile.open("textOut.txt");
    iObj1 = 81;
    outFile << "Obj1: " << iObj1 << endl;
    iObj2 = iObj1 ++;
    outFile << "iObj1: " << iObj1 << ","<< "iObj2: " << iObj2 << endl;
    outFile.close(); 
    return 0;
}



ostream& operator<<(ostream &os, const IntClass &iObj1)
{
    os<<iObj1.getVal();
    return(os);
}

int main(void)
{
    iObj1 = 81;
    cout <<  "iObj1: " << iObj1 <<endl;
    
    iObj2 = iObj1 ++;
    cout <<  "iObj1: " << iObj1 << ","<< "iObj2: " << iObj2 << endl;
}