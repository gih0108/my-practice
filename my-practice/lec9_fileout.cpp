#include<iostream>
#include <fstream>

int _tmain(int argc, _TCHAR* argv[])
{
    ofstream f;
    
    f.open("cpptest.txt");
    f<<"String"<<1234<<endl;
    f.close();
    return 0;
}

