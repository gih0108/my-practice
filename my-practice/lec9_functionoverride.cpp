#include <iostream>
using namespace std;



//11,20,28행 총 3개의 클래스가 상속관계로 연결되어 있으며 이들은 모두 MyFunc 함수를 통해서 오버라이딩 관계를 형성
class First
{
public:
    void MyFunc(){
        cout << "FirstFunc" << endl;
    }
    
};

class Second:public First
{
public:
    void MyFunc(){
        cout << "SecondFunc" << endl;
    }
};

class Third : public Second
{
public: 
void MyFunc(){
    cout << "ThirdFunc" << endl;
    }
};

int main(void)
{
    
    //Third객체를 생성한 후, Third형, Second형, First형 포인터 변수로 이를 참조하고 있음
    Third * tptr = new Third();
    Second * sptr = tptr;
    First * fptr = sptr;
    
    //각 포인터 형 변수를 이용해서 MyFunc 함수를 호출하고 있음
    fptr -> MyFunc();
    sptr -> MyFunc();
    tptr -> MyFunc();
    delete tptr;
    return 0;
}