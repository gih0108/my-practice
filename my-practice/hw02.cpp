#include<iostream>
#include<cstring>
using namespace std;

class Person { //Person이라는 구조체 생성
private: // private으로 만듦으로 하여 이 구조체 안에서 나만 쓸 수 있음
	char name[50]; // name이라는 리스트 생성
	int age; // age를 변수로 함
public: // 구조체 안에서 누구나 쓸 수 있음
	Person() { // Person()이라는 함수 
		strcpy(name, "이지현"); // name이라는 할당 공간에 "이지현" 이라는 문자열을 복사, 덮어씌우기 
		age = 21; // 변수 age에는 정수형에 맞는 숫자가 들어감(나이)
	}//Person 함수 종료
	
	Person(char * myname, int myage) : age(myage) { //:은 상속의 의미
		strcpy(name, myname);//myname을 name에 복사
	}

	void Walk() { // 함수
		cout << "걷는중입니다." << endl;  
	}

	virtual void Study() { //(가상)함수
		cout << "공부안하는 중입니다" << endl;
	}

	void Info() { //함수
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}

	virtual ~Person(); 
};

class Student : public Person { // 구조체 Student안에 구조체 Person이 상속됨
private:
	int grade; //변수선언
	int hour; //변수선언
public:
	Student() : Person() { //Student함수 안의 Person함수
		hour = 10;
		grade = 3;
	} // Student 함수 안에 hour,grade가 각각 설정되었으면서, Person에서 있었던 것들을 모두 가져옴
	Student(char * myname, int myage, int mygrade, int myhour) : Person(myname, myage), grade(mygrade), hour(myhour) {}

	void Study() { //가상함수화 됨
		cout << hour << "시간 째 공부하는 중입니다." << endl; 
	}

	~Student();

};//가상함수 : 포인터 변수가 실제로 가리키는 객체를 참조하여 호출의 대상을 결정함
Student::~Student() {
	cout << "학생 객체 소멸" << endl;
}
Person::~Person() {
	cout << "사람 객체 소멸" << endl;
}

int main()
{
	Person * ptr1 = new Person; //포인터 ptr1에 Person이라는 새로운 객체를 구조체 Person에 생성
	Person * ptr2 = new Student; // 포인터 ptr2에 Student라는 새로운 객체를 구조체 Person에 생성

	ptr1->Info(); 
	ptr1->Study(); //오버라이딩 관계지만 ptr1이 Person에 할당
	ptr2->Study(); //오버라이딩 관계지만 ptr2가 Student에 할당

	delete ptr1; // 삭제
	delete ptr2; // 삭제
}