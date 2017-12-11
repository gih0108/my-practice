#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

/* 멤버변수 : -eno:int   ename:char*    dept:char[10]   score:double
멤버함수 : +empView():void  ==> 출력
[결과화면] 
0    noname   notitle    0 
101  kim      developer  100 
0    lee      notitle    100 
102  noname   sales      50 
*/ /////////////////////////////////////////////////////////////////// 

//설계한다.
//콜라 캔 설계.
//액체와 캔.

class Employees //회사원들을 관리하는 시스템.
{
private:
   int eno;
   char* ename;
   char dept[10];
   double score;
   
public:
   //객체의 이름을 호출.
   Employees();
   Employees(int, char*, char[], double);
   Employees(char*, int);
   Employees(int, char[], double);
   ~Employees();
   void empView();
};

Employees::Employees(char*ename, int score)
{
   this ->ename = ename;
   this->eno = 0;
   strcpy(this->dept, "notitle");
   //string 값을 복사한다.
   this->score = score;
}
Employees::Employees()
{
   this->eno = 0;
   this->ename = "noname";
   strcpy(dept, "notitle");
   this->score = 0;
}
Employees::Employees(int eno, char* ename, char dept[], double score)
{
   this->eno = eno;
   this->ename = ename;
   strcpy(this->dept, dept);
   this->score = score;
}
Employees::Employees(int eno, char dept[], double score)
{
   this->eno = eno;
   this->ename = "noname";
   strcpy(this -> dept, dept);
   this->score = score;
}
void Employees::empView()
{
   cout << eno << "\t" << ename << "\t" << dept << "\t" << score << endl;
}
Employees::~Employees()
{

}
int main(void)
{
   Employees em1; 
   Employees em2(101, "kim", "developer", 100);
   Employees em3("lee", 100); 
   Employees em4(102, "sales", 50);
   em1.empView(); 
   em2.empView(); 
   em3.empView(); 
   em4.empView();
   return 0;
}

//c++은 자신에게 맞는 파라미터 수가 있는 함수를 찾아가 오버로딩하려고 한다
//그런것이 아니라면 가장 마지막에 호출되는 함수를 오버라이딩함

/*output: 
0       noname  notitle 0
101     kim     developer       100
0       lee     notitle 100
102     noname  sales   50
*/