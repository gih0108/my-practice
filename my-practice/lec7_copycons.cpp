#include <iostream> 
#include <stdlib.h> 
using std::cin;  
using std::cout;  
using std::endl;

class BankAccount 
{ 
private: 
   int year;
   char* name; 
   int money; 
   static float rate;//static으로 선언해준 rate 변수, class 내에서 자유롭게 쓸 수 있음
public: 
   BankAccount(int, char*, int, float);//BankAccount함수의 파라미터 선언, 순서대로 값을 받을 것임
   ~BankAccount();//소멸자 함수 실행 
   static void changeRate(float);//static으로 선언된 ChangeRate 함수
   void printView() const;// printView함수의 상수화, 상수로 취급함, return 값은 없음
}; 

float BankAccount::rate = 0.02f;  //클래스 BankAccount안에 있는 float 자료형 rate를 초기화 
BankAccount::BankAccount(int y,char* n,int m,float r) :year(y),name(n),money(m)//멤버 이니셜라이저
//BankAccount클래스의 BankAccount
{ 
   rate=r; //static으로 선언되었으므로 이와 같이 선언해줌, 이니셜라이즈 형태로 선언해줘도 무관하나 좋지 않음
} 
BankAccount::~BankAccount()//클래스의 소멸자를 부름
{ 
} 

void BankAccount::changeRate(float r) 
{ //유효성 검사 
   if(r < 0.02 || r > 0.12) 
   { 
      cout<<"금리입력오류!!\n"; 
      exit(0); 
   } 
   rate=r; 
} 

void BankAccount::printView() const 
{ 
   cout.width(7);   
   cout<<year; 
   cout.width(7);   
   cout<<name; 
   cout.width(7);   
   cout<<money; 
   cout.width(7);   
   cout<<rate; 
   cout << endl;
} //간격조절해주는 기능

int main() 
{
   cout << "***입금당시의 금리***" << endl; 
   BankAccount* ba1 = new BankAccount(1993, "kim", 1000, 0.07f);
   ba1->printView(); 
   BankAccount* ba2 = new BankAccount(1998, "lee", 1000, 0.12f); 
   ba2->printView(); 
   BankAccount* ba3 = new BankAccount(2005, "park", 1000, 0.05f);
   ba2->printView(); 
   cout << endl;
   cout << "***2005년 현재의 금리***" << endl; 
   ba1->printView(); 
   ba2->printView(); 
   ba3->printView(); 
   cout << endl;
   cout << "***0.04로 변동된 금리***" << endl; 
   //BankAccount::rate=0.4f; or  ba1->rate=0.04f; <--privat멤버에는 접근불가 
   //BankAccount::changeRate(0.04f); ba1->printView(); ba2->printView(); ba3->printView(); cout<<endl;
   delete ba1; 
   delete ba2; 
   delete ba3;
   //동적할당 해줬으면 마지막에 포인터 변수를 써서 그 메모리 공간을 소멸시켜줘야 함
}

/*output:
***입금당시의 금리***
   1993    kim   1000   0.07
   1998    lee   1000   0.12
   1998    lee   1000   0.05

***2005년 현재의 금리***
   1993    kim   1000   0.05
   1998    lee   1000   0.05
   2005   park   1000   0.05

***0.04로 변동된 금리***
*/