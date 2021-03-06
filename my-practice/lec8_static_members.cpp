#include<iostream>
#include<string.h>
using namespace std;

class student{
    public:
    int id;
    student(int i = 0); // student함수의 argument가 i로 선언되었고 0으로 초기화 됨
    static void printCount(); // static으로 함수 선언(static function)
    void printID();
    //student class가 공유되는 모든 곳에서 쓰일 수 있는 함수가 됨
    
    private:
    static int count;// static으로 count변수 설정, class함수가 쓰이고 공유되는 모든 곳에 쓰일 수 있는 변수가 됨
};

int student::count = 0;// student class의 static int count가 0으로 초기화
//count가 static변수 이기때문에 student class와 공유되고 있으므로 문제될 것이 없다.
//static 멤버는 무조건 class 정의 밖에서 초기화되어야 한다
//그리고 static 멤버 변수는 딱 한번 초기화 된다

student::student(int i){ // stduent class의 student함수(constructor),argument가 int i로 존재함
    id = i; // id = i의 값으로 초기화됨, 이미 i는 0으로 초기화 되었음(객체 생성시 초기화 안해주면 그대로 0이 출력될 것임)
    count++; // count가 후위증가
}

void student::printCount(){ // student class의 함수 & 기능 
    cout << "count = " << count << endl; // count값을 출력해주는 기능을 함
}

void student::printID(){ //student class의 함수 & 기능
    cout << "id = " << id << endl; // id값을 출력해주는 기능을 함
}

int main(){
    student myID = 21600555; // student 클래스의 object가 myID로 설정됨, 그리고 학번으로 초기화됨
    myID.printCount(); //count = 1이 출력될 것임
    myID.printID(); // 학번이 출력됨. 객체 생성시 초기화 시켰던 값이 그대로 출력됨.
    
    student yourID = 21400333; // 객체 생성, 학번으로 객체 생성 후 초기화
    myID.printCount(); // count = 1로 초기화 되었던 myID의 재초기화 -> count = 2
    //여기서 보여주려고 하는 것은 static 멤버 변수는 한 번만 초기화 된다는 것을 보여주려는 것(다시 0으로 돌아가지 않음)
    yourID.printID();// 학번이 출력됨. 객체 생성시 초기화 시켰던 값이 그대로 출력됨.
    myID.printID();//21600555가 출력
    
    student hisID;//초기화 시켜준 값이 없기 때문에, student(int i = 0)을 부르고 0으로 초기화 됨.
    student herID = 21600555;//객체 생성, 학번으로 객체 생성 후 초기화
    student::printCount();//hisID와 herID가 각각 1번씩 count했으므로 총 count = 4가 됨
    //student의 printCount함수를 통째로 부름..
    
    hisID.printID();// 0이 출력됨, hisID는 객체 생성 시 초기화 값이 없었기 때문에 
    herID.printID();// 학번이 출력됨. 객체 생성시 초기화 시켰던 값이 그대로 출력됨
    
    //student hisID;
    //myID.printCount();
    //student herID;
    //myID.printCount();
    //위 주석처리 된 것 처럼하면 그냥 각각 count가 3,4로 출력됨
}

//question : 내가 id출력하는 함수들이 없길래 임의로 만들었는데, 뭔가 내가 만들었지만 이해가 안감
//이해가 안되는 부분이 초기화 관련된 것임.class 안에서 student(int i = 0);라고 선언되었는데 
//student hisID;왜 이때만 0으로 초기화된 값이 나오는건지,,


 /*
 student herID = 21600555로 되는 이유는 c++ 특성상 side effect로  
서로 맞지않는 형식으로 저렇게 = 을 하면 최대한 그 의미를 찾아가려고 하는 특성이있음.
int 값 21600555는 student 클래스의 멤버 변수중 int인 id로 들어가버림.
그래서 id 호출하면 21600555 값이 나타나는 거고 hisID는 그러한 코드가 없었기 때문에 기본으로 초기화해주는
0이 id로 들어간다 
*/

/*output:
count = 1
id = 21600555
count = 2
id = 21400333
id = 21600555
count = 4
id = 0
id = 21600555
*/
