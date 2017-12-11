#include<iostream>
#include<cstdlib>
using namespace std;

class BoundCheckIntArray
{
    private:
        int * arr;
        int arrlen;
    
    public:
        BoundCheckIntArray(int len) : arrlen(len)
        {
            arr=new int[len];
        }
        
        int& operator[] (int idx)//반환형이 참조형
        {
            if(idx < 0 || idx >= arrlen)
            {
                cout <<"Array index out of bound exception" <<endl;
                exit(1);
            }
            return arr[idx];//인자로 전달된 인덱스에 해당하는 배열요소를 반환, 반환형이 참조형
            //때문에 배열요소의 참조값이 반환되고, 이 값을 이용해서 배열요소에 저장 된 값의 참조뿐만 아니라 변경도 가능
        }
        
        ~BoundCheckIntArray()
        {
            delete []arr;
        }
};

int main(void)
{
    BoundCheckIntArray arr(5);
    for(int i=0; i <5 ; i++)
        arr[i] = (i+1)*11;//연산자 []오버로딩을 한 것이지만, 배열에 직접 접근하는 느낌을 줌, 실제로 배열처럼 느끼고 사용할 수 잇음
    for(int i=0; i<6; i++)//벗어난 범위의 배열접근 결과의 확인을 위해서 반복의 범위를 0~5로 지정
        cout<<arr[i]<<endl;
    return 0;
}

/*output:
11
22
33
44
55
Array index out of bound exception
*/