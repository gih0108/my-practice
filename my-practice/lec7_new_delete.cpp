#include <stdio.h>
#include <iostream>
#include <cstring>
#include <iomanip>

struct student{ 
    char name[20]; 
    int age;
};

int main(){
    struct student *p1 = new struct student[sizeof(struct student)];
    //포인터 변수 p1에 struct student사이즈 만큼의 새로운 공간 동작할당
    //new struct student라고 해줌으로 써 char name[20]과 int age의 공간이 각각 생성
    
    void *ptr;//ptr이라는 포인터 변수 공간 할당, 초기화는 하지않음
    
    strcpy(p1 -> name,  "이지현");//"이지현"이라는 이름을 p1의 name공간에 복사
    p1 -> age = 21;//p1의 age공간에 21 저장
    
    ptr = p1;//포인터 ptr공간에 p1의 정보들을 저장

    std::cout<<"이름:"<<static_cast<struct student*>(ptr)->name <<std::endl;
    //ptr의 타입을 struct student* 타입으로 바꿈
    //ptr에 저장되어있던 name을 출력해주기 위해서 위와 같은 코드를 작성 한 것임
    std::cout<<"나이:"<<static_cast<struct student*>(ptr)->age <<std::endl;
    //ptr의 타입을 struct student* 타입으로 바꿈
    //ptr에 저장되어있던 age을 출력해주기 위해서 위와 같은 코드를 입력하여 struct student의 변수들을 이용할 수 있게 된 것
    
    std::cout << "이름 : " << p1->name << std::endl;
    std::cout << "나이 : " << p1->age << std::endl;
    
    delete []p1;//p1의 모든 배열 공간들을 삭제
    return 0;
}

//그냥 p1->name, age해서 출력해주면 똑같은 답 나오는데 왜 어렵게 static_cast를 이용해서 타입을 바꿔줌?
//아니 왜 애초에 void *ptr을 설정해줬는지 모르겠음. 저렇게 선언해 준 이유가 따로 있는가?
//주석 단게 말이 맞는지 확인 좀.. 

//그럼 주석말고 저 위에 질문들만 해주셈,,,진짜 티에이가 ㅋㅋ