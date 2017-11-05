#include<iostream>
#include<cstring>
#include<string>
using namespace std;
std::string
class Printer
{
private:
    str[30];
public:
    void SetString(char* s);
    void ShowString();
    
};

void Printer::SetString(char* s)
{
    strcpy(str,s);
}
void Printer::ShowString()
{
    cout << str << endl;
}

int main(void)
{
    Printer pnt;
    pnt.SetString("Hello world");
    pnt.ShowString();
    
    pnt.SetString("I love C++");
    pnt.ShowString();
    return 0;
}