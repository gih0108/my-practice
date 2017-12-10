#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
class Test
{
public:
   int a, b;
   static int c;
public:
   void view()
   {
      cout << a << "   " << b << c << endl;
   }
};
int Test::c = 0; // static 변수의 초기화


int main()
{
   Test ob1; ob1.a = 1; ob1.b = 2; ob1.c = 0;
   Test ob2; ob2.a = 5; ob2.b = 6; ob2.c = 5;

   ob1.view();
   ob2.view();
}