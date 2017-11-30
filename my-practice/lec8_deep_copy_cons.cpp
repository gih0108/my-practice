#include<iostream>
#include <string.h> //strcpy, strlen 사용위해선 include 해줘야됨 
using namespace std;

class record{ 
    public:
    char* name;//char만큼의 공간 할당
    char* tel;//char만큼의 공간 할당
    record(char*, char*);//record 라는 함수, constructor 
    record(const record&);//참조자 선언
    ~record();//destructor
    void modifyTel(char* _tel);//return값은 없고, 새로운 함수를 만듦.
    void print(void);//return값은 없고, print기능을 하는 함수
};

//shallow copy
record::record(char* _n, char* _tel)//record(char*, char*);이 함수의 기능을 씀.
{
    name = new char[strlen(_n)+1];//name에 _n + null만큼의 길이를 가진 공간 할당
    strcpy(name, _n);//할당된 공간에 _n에 들어온 값 복사
    tel = new char[strlen(_tel)+1];//tel에 _tel + null만큼의 길이를 가진 공간 할당
    strcpy(tel, _tel); //할당된 공간에 _tel에 들어온 값 복사
}

//deep copy
record::record(const record& _record){ // _record라는 새로운 변수를 만들어 참조
    name =new char[strlen(_record.name)+1];//name에 _record가 참조하는 name + null만큼의 길이를 가진 공간 할당
    strcpy(name, _record.name);//할당된 공간 name에 _record의 name에 들어온 값 복사
    tel = new char[strlen(_record.tel)+1];//tel에 _record가 참조하는 tel + null만큼의 길이를 가진 공간 할당
    strcpy(tel, _record.tel);//할당된 공간 tel에 _record의 tel에 들어온 값 복사
    
}

record::~record(){//destructor함수의 기능
    delete name,tel; //따로 할당된 name, tel의 공간들을 없애줌
}

void record::modifyTel(char* _tel){//modifyTel함수의 기능
    delete tel; // 위에서 이미 쓰인 tel의 공간 지워줌, 
    //처음에 record::record(char* _n, char* _tel)이 불려졌는데 그것을 없애줌
    tel = new char[strlen(_tel)+1];//다시 tel이라는 공간에 _tel + null길이 만큼의 공간 할당
    strcpy(tel, _tel);//복사
}

void record::print(void){//print해주는 함수 기능
    cout << name;//name의 값 출력
    cout << ":" << tel << endl; // tel의 값 출력
}

int main(){
    record myRecord("LEE", "3263"); // 선언과 동시에 초기화
    record hisRecord(myRecord); //새로운 객체를 설정해 주고 참조자로 설정해준 deep copy부분을 부름
    record herRecord(hisRecord);
    myRecord.modifyTel("3458");//modify함수부분 실행, tel 공간에는 문자 3458이 들어가 있음
    
    hisRecord.modifyTel("6550");
    myRecord.print();//myRecord를 불렀지만 이미 tel부분은 modify함수로 인해 바뀐 상태임
    hisRecord.print();//hisRecord를 불렀고, myRecord가 _record의 참조자가 됨
    //print되는 값은 print()함수에 맞게 새로운 공간이 각각 할당되고 이미 초기화 되었던 myRecord값이 출력
    
    herRecord.print();
    return 0;
}

//question : 살짝 참조 해주는 부분에서 헷갈림. 예를 들어 const record& _record 여기서보면,  _record라는 참조자를 만들어서 
//record를 참조해 줬다는 건가?

/*
deep copy를 위해서 기존의 shallow copy(껍데기만 복사하는..) 처럼 변수가 차지하는 만큼의 공간만 할당해서
copy해주는 것이 아닌 record라는 새로운 "그릇" 따로 선언해서 그 안에 들어가 있는 값을 복사해서 넘겨주는 것

http://wonjayk.tistory.com/256 
이정도로만 알아두자!
*/