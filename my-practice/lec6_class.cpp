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

void main(void)
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
    cout << "카메라 장착여부(O/X) :"
    cin >> camera;
}