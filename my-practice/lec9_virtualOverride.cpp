#include <iostream>
using namespace std;

//8행의 MyFunc 함수가 virtual로 선언되었으므로 17,25행의 함수에는 굳이 virtual 선언을 추가하지 않아도 가상함수가 됨.
//그러나 이렇게 virtual선언을 넣어서 함수가 가상함수임을 알리는 것이 좋음
class First
{
public:
    virtual void MyFunc(){
        cout << "FirstFunc" << endl;
    }
    
};

class Second:public First
{
public:
    virtual void MyFunc(){
        cout << "SecondFunc" << endl;
    }
};

class Third : public Second
{
public: 
    virtual void MyFunc(){
        cout << "ThirdFunc" << endl;
        }
};
//함수가 가상함수로 선언되면 해당 함수호출 시, 포인터의 자료형을 기반으로 호출대상을 결정하지 않고,
//포인터 변수가 실제로 가리키는 객체를 참조하여 호출의 대상을 결정함


int main(void)
{
    
    //Third객체를 생성한 후, Third형, Second형, First형 포인터 변수로 이를 참조하고 있음
    Third * tptr = new Third();
    Second * sptr = tptr;
    First * fptr = sptr;
    
    //각 포인터 형 변수를 이용해서 MyFunc 함수를 호출하고 있음
    fptr -> MyFunc();//fptr이 First형 포인터이니, 이 포인터가 가리키는 객체를 대상으로 First 클래스에 정의된
    //MyFunc함수는 무조건 호출할 수 있음
    
    sptr -> MyFunc();//sptr이 Second형 포인터이니, 이 포인터가 가리키는 객체에는 First의 MyFunc 함수와 Second의 MyFunc 함수가 
    //오버라이딩 관계로 존재함, 때문에 오버라이딩을 한 Second의 MyFunc 함수를 호출할 것임
    
    tptr -> MyFunc();//컴파일러는 tptr이 Third형 포인터라는 사실을 기억, 따라서 이 포인터 변수가 참조하는 객체에는 총 세개의
    //MyFunc 함수가 존재하고 이들은 오버라이팅 관계를 갖기 때문에 가장 마지막에 오버라이딩을 한 Third 클래스의 MyFunc함수가 호출되어야 함
    
    delete tptr;
    return 0;
}

/*output : 
ThirdFunc
ThirdFunc
ThirdFunc
*/
