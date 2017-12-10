#include <iostream> 
#include <stdlib.h> 
using std::cin;  using std::cout;  using std::endl; 
class BankAccount 
{ 
private: 
   int year;
   char* name; 
   int money; 
   static float rate; 
public: 
   BankAccount(int, char*, int, float); 
   ~BankAccount(); 
   static void changeRate(float);
   void printView() const; 
}; 
float BankAccount::rate = 0.02f;  //초기화 
BankAccount::BankAccount(int y,char* n,int m,float r) :year(y),name(n),money(m) 
{ 
   rate=r; 
} 
BankAccount::~BankAccount() 
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
   cout<<year; cout.width(7);   
   cout<<name; cout.width(7);   
   cout<<money; cout.width(7);   
   cout<<rate; cout << endl;
} int main() 
{
   cout << "***입금당시의 금리***" << endl; 
   BankAccount* ba1 = new BankAccount(1993, "kim", 1000, 0.07f); ba1->printView(); 
   BankAccount* ba2 = new BankAccount(1998, "lee", 1000, 0.12f); ba2->printView(); 
   BankAccount* ba3 = new BankAccount(2005, "park", 1000, 0.05f); ba2->printView(); 
   cout << endl;
   cout << "***2005년 현재의 금리***" << endl; 
   ba1->printView(); ba2->printView(); ba3->printView(); 
   cout << endl;
   cout << "***0.04로 변동된 금리***" << endl; //BankAccount::rate=0.4f;   //or  ba1->rate=0.04f;   <--privat멤버에는 접근불가 BankAccount::changeRate(0.04f); ba1->printView(); ba2->printView(); ba3->printView(); cout<<endl;
   delete ba1; delete ba2; delete ba3;
}