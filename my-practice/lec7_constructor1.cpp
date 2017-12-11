#include <iostream>
using namespace std;

class SimpleClass
{
    private:
        int num1;
        int num2;
        
    public:
        SimpleClass()//구조체와 이름이 동일하고 반환값이 없는 함수가 constructor이다.
        {   
            num1 = 0;
            num2 = 0;
        }
        
    SimpleClass(int n)
    {
        num1 = n;
        num2 = 0;
    }
    SimpleClass(int n1, int n2)
    {
        num1 = n1;
        num2 = n2;
    }
    /*
    SimpleClass(int n1 = 0, int n2 = 0)
    {
        num1 = n1;
        num2 = n2;
    }
    */
    void ShowData() const
    {
        cout << num1<< ' ' << num2 << endl;
    }
};

int main(void)
{
    SimpleClass sc1;//()라고 해주지 않은 이유가 반환형이 있는 함수로 착각할까봐,,
    sc1.ShowData(); 
    
    SimpleClass sc2(100); //parameter반환형에 맞는 함수를 반환 
    sc2.ShowData();
    
    SimpleClass sc3(100, 200); //parameter반환형에 맞는 함수를 반환
    sc3.ShowData();
    
    return 0;
}

/*output:
ce/my-practice (master) $ ./a.out
0 0
100 0
100 200
*/