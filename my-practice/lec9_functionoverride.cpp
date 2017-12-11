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
};//다형성

int main(void)
{
    
    //Third객체를 생성한 후, Third형, Second형, First형 포인터 변수로 이를 참조하고 있음            +
    Third * tptr = new Third(); 
    Second * sptr = tptr; 
    First * fptr = sptr;
    
    //각 포인터 형 변수를 이용해서 MyFunc 함수를 호출하고 있음
    fptr -> MyFunc();//fptr이 First형 포인터이니, 이 포인터가 가리키는 객체를 대상으로 First 클래스에 정의된
    //MyFunc함수는 무조건 호출할 수 있음
    
    sptr -> MyFunc();//sptr이 Second형 포인터이니, 이 포인터가 가리키는 객체에는 First의 MyFunc 함수와 Second의 MyFunc 함수가 
    //오버라이딩 관계로 존재함, 때문에 오버라이딩을 한 Second의 MyFunc 함수를 호출할 것임
    
    tptr -> MyFunc();//컴파일러는 tptr이 Third형 포인터라는 사실을 기억, 따라서 이 포인터 변수가 참조하는 객체에는 총 세개의
    //MyFunc 함수가 존재하고 이들은 오버라이딩 관계를 갖기 때문에 가장 마지막에 오버라이딩을 한 Third 클래스의 MyFunc함수가 호출되어야 함
    
    delete tptr;
    return 0;
}

/*
FirstFunc
SecondFunc
ThirdFunc
*/