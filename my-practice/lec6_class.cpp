#include<iostream>
#include<string>

using namespace std;

class cellphone{
private:
    string model;
    string company;
    string color;
    bool on;
    bool install;
    char power;
    char camera;
    
public:
    void input();
    void print();
    void turnon();
    void turnoff();
    void installon();
    void installoff();
};

int main(void)
{
    cellphone product;
    product.input();
    product.print();
}

void cellphone::input()
{
    cout << "상품의 모델명 :";
    cin >> model;
    cout << "상품의 회사명 :";
    cin >> company;
    cout << "상품의 색상 :";
    cin >> color;
    cout << "전원 상태(O/X) :";
    cin >> power;
    cout << "카메라 장착여부(O/X) :";
    cin >> camera;
}

void cellphone::print()
{
    cout << "상품의 모델명은 " << model << endl;
    cout << "사품의 회사명은 " << company << endl;
    cout << "상품의 색상은" << color <<endl;
    if(power == 'o' || power == 'O')
    {
        turnon();
    }
    else
        turnoff();
    cout << "전원은" << (on==true? "켜져있습니다" : "꺼져있습니다") <<endl;
    if(camera=='o' || camera =='O')
    {
        installon();
    }
    else
        installoff();
    cout << "카메라는" <<(install==true?"장착되었습니다" :"장착되지 않았습니다") <<endl;
}

void cellphone::turnon()
{
    on=true;
}
void cellphone::turnoff()
{
    on=false;
}
void cellphone::installon()
{
    install=true;
}
void cellphone::installoff()
{
    install=false;
}