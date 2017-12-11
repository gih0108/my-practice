#include<iostream>
using namespace std;

class Temporary
{
    private:
        int num;
    public:
        Temporary(int n) : num(n)
        {
            cout <<"create obj: " << num << endl;
        }

        
        ~Temporary()
        {
            cout << "destroy obj: " << num << endl;
        }
        
        void ShowTempInfo()
        {
            cout << "My num is " << num <<endl;
        }
};

int main(void)
{
    Temporary(100);//임시객체 생성, 이 문장에 의해서 100으로 초기화된 Temporary 임시객체가 생성됨
    cout << "**********after make!" <<endl<<endl;
    
    Temporary(200).ShowTempInfo();//임시객체를 생성하고 이어서 이 객체를 대상으로 ShowTempInfo()함수를 호출하고 있음.
    //객체가 생성 및 반환되려면 생성 및 반환된 위치에 객체를 참조할 수 있는 참조 값이 반환되기 때문에 이러한 문장을 구성할 수 있음
    cout << "**********after make!" <<endl<<endl;
    
    const Temporary &ref=Temporary(300);//임시객체 생성, 단 앞에서 생성한 다른 두 객체와 달리 여기서는 참조자 ref로 임시객체를 참조함
    cout << "**********end of main!" <<endl<<endl;
    return 0;
    
}

//임시객체는 다음 행으로 넘어가면 바로 소멸, 그러나 참조자에 참조되는 임시객체는 바로 소멸 안됨

/*output: 
create obj: 100
destroy obj: 100
**********after make!

create obj: 200
My num is 200
destroy obj: 200
**********after make!

create obj: 300
**********end of main!

destroy obj: 300
*/

