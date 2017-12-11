#include<iostream>
#include<cstring>
#include<string>
using namespace std;
//std::string;

class Printer
{
private:
    char str[30];//array 변수
public:
    void SetString(char* s);
    void ShowString();
    
};

void Printer::SetString(char* s)
{
    strcpy(str,s);//array 변수->strcpy로 선언
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

/*output : 
Hello world
I love C++
*/