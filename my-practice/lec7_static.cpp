#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class Test//Test로 클래스 선언
{
public:
   int a, b;
   static int c;//static으로 선언된 c변수
public:
   void view()//함수를 만들어주고 함수의 기능을 그냥 클래스 안에서 선언해줌
   {
      cout << a << "   " << b << c << endl;
   }
};

int Test::c = 0; // static 변수의 초기화


int main()
{
   Test ob1; 
   ob1.a = 1; 
   ob1.b = 2; 
   ob1.c = 0;
   Test ob2; 
   ob2.a = 5; 
   ob2.b = 6; 
   ob2.c = 5;

   ob1.view();
   ob2.view();
}

/*output:
1   25
5   65
*/