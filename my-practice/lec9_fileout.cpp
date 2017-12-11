#include<iostream>
#include <fstream>
//#include <cstring>
//#include <sstream>
//#include <stdlib.h>

using namespace std;

int iObj1;
int iObj2;
char arr[] = "I love programming2";
char*arr1[20];

int main(void)
{
    ofstream outFile;
    
    outFile.open("textOut.txt");
    iObj1 = 81;
    outFile << "Obj1: " << iObj1 << endl;
    iObj2 = iObj1 ++;
    outFile << "iObj1: " << iObj1 << ","<< "iObj2: " << iObj2 << endl;
    outFile << "jihyun:" << arr << endl;
    outFile << "address value:" << arr1 << endl;
    outFile.close(); 
    return 0;
}

/*
int iObj1;
int iObj2;

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
}*/

/*output:
Obj1: 81
iObj1: 82,iObj2: 81
jihyun:I love programming2
address value:0x602120
(txt파일이 별도로 만들어짐)
*/
