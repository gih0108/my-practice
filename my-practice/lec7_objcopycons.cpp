#include<iostream>
using namespace std;

class SoSimple
{
    private:
        int num;
    public:
        SoSimple(int n) : num(n)
        { }
        
        SoSimple(const SoSimple& copy) : num(copy.num)
        //복사 생성자의 호출시기를 알기 위해서 복사 생성자를 별도로 설정, 디폴트 복사 생성자와의 유일한 차이점은
        //아래의 문자열 출력에 있음
        {
            cout << "Called SoSimple(const SoSimple& copy)" << endl;
        }
        
        void ShowData()
        {
            cout << "num: " << num << endl;
        }
};

//초기화의 대상은 obj각체가 아닌, ob객체, 그리고 ob객체는 obj객체로 초기화됨
void SimpleFunObj(SoSimple ob)//매개변수 ob의 복사 생성자 호출, 인자로 obj가 전달될 것임
//ob객체에는 SoSimple관련된 것들이 모두 들어올 것임
{
    ob.ShowData();
}

int main(void)
{
    SoSimple obj(7);
    cout << "함수호출 전" << endl;
    
    SimpleFunObj(obj);//함수 SimpleFunObj을 호출하면서 객체 obj를 인자로 전달하고 있음. 
    //25행에 선언된 매개변수 ob의 복사 생성자가 호출되면서, 인자로 obj가 전달됨.
    
    cout << "함수호출 후" << endl;
    return 0;
}