#include < iostream >
 #include < string.h >
using namespace std;
#define NAME_LEN 10
#define MAX   25
class Node
{
private : 
 char name[NAME_LEN];
 Node* next;
public : 
 Node(char *name ="\0" , Node *pnext = NULL ) : next(pnext) 
 {
  strcpy( this->name , name ) ; 
 }
 char* GetName()   { return name;    }
 Node* GetNext()   { return next;    }
 void SetNext(Node* next) { this->next = next;   } 
 void SetName(char* name) { strcpy(this->name, name); }
};
class LinkedList
{
private : 
 Node *head;
 int   count;
 
public : 
 LinkedList(Node *pHead = NULL , int nCount = 0  ) : head(pHead)  , count(nCount) {}
 Node *GetHead()    { return head; }
 void SetHead(Node* temp) { head = temp; }
 int   GetCount()   { return count; }
 
 void InsertNode(char *data) ;
 void Dispaly();
 void Search(char *data);
};
void LinkedList::InsertNode(char *data)
{
 Node *pNewNode = new Node(data, NULL ) ;
 if(count >= MAX)
 {
  cout << MAX << "개 이상은 입력할 수 없습니다. " << endl; return;
 }
 
 if( this->GetHead() == NULL ) SetHead( pNewNode) ;
 else
 {
  Node* cur = GetHead();
  while( cur->GetNext() != NULL ) 
  {
   cur = cur->GetNext();
  }
  cur->SetNext( pNewNode ) ;
 }
 count++;
}
void LinkedList::Dispaly()
{
 Node *imp = GetHead();
 if( imp == NULL ) 
 {
  cout << "입력된 자료가 없어 출력 불가" << endl;
  return ;
 }
 for(int i = 1 ; i <= GetCount() ; i++ ) 
 {
  cout << i << "번째자료 -> " << imp->GetName() << endl;
  imp =  imp->GetNext() ; 
 }
}
void LinkedList::Search(char *data)
{
 Node *cur = GetHead();
 for(int i=0 ; i < GetCount() ; i++)
 {
  if( strcmp( cur->GetName() , data ) == 0 ) 
  {
   cout << i+1 << "번째 위치 : " << cur->GetName() << endl;
   return ; 
  }
  cur = cur->GetNext();
 }
 cout << "데이터가 없습니다 " << endl ; 
}

void Menu()
{
 const char *MenuString[]={"1.추가","2.검색","3.출력","4.종료" , NULL };
 for(int i=0; MenuString[i]; i++)
 {
  cout <<  MenuString[i] << endl;
 }
 cout << "선택-> " ;
}
void add(LinkedList &list)
{
 char name[NAME_LEN];
 cout << "데이터 입력 : ";
 cin >> name;
 list.InsertNode( name ) ;
 cout << "입력 완료 " << endl ; 
}
void search(LinkedList &list)
{
 char name[NAME_LEN];
 cout << "찾으실 데이터 입력 : ";
 cin >> name;
 list.Search( name ) ; 
}
void disp(LinkedList &list)
{
 list.Dispaly();
}
void main()
{
 int    cho;
 LinkedList  list;
 while(1)
 {
  system("cls");
  Menu();
  cin >>  cho ;
  switch(cho)
  {
  case 1 : add(list);  break;
  case 2 : search(list); break;
  case 3 : disp(list);  break;
  case 4 : return;
  }
  cout << endl ; 
  system("pause");
 }
}