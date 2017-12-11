#include<iostream>
using namespace std;

class Test{
    
    public:
    int a; //instance, 객체 변수 -> 객체가 생성될 때
    static int b;//컴파일 타임, 클래스 변수
    
    public:
    Test() {
        a = 0;
    };//constructor, 변수의 초기화

    static void Show(int n, int m){
        cout << "n = :" << n <<","<< "m = :" << m <<endl;
    }
};

int main(){
    
    Test obj;
    
    Test::Show(1,2);//이렇게 호출해도 충분하다
    
    obj.Show(1,2);//이렇게 출력해도 같은 값 출력, 객체 obj를 만들어준 만큼 저렇게 출력해도 됨.
    return 0;
}

//class내의 static함수는 그것이 private, public, protected상관없이 숨어서 넘어가는 this pointer를
//전달하지 말도록 하는 것. 그렇기 때문에 static member function은 static아닌 멤버 변수나 함수를 호출할 수 없다.
//8라인에서 static한 클래스 변수 b를 선언하면 b는 메모리의 static영역에 자리 잡게 됨/
//Test의 변수 a는 stack영역에 자리잡게 됨.
//나머지 Show 함수 및 기타 코드는 memory의 text영역에 자리잡게 되고 컴파일 시 binding됨

/*output : 
n = :1,m = :2
n = :1,m = :2
*/