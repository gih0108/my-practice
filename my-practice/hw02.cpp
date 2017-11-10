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
	
	Person(char * myname, int myage) : age(myage) { //:은 상속의 의미, 인자 전달 받을 시 이 함수로 초기화 됨
		strcpy(name, myname);//myname을 name에 복사
	}

	void Walk() { // 함수
		cout << "걷는중입니다." << endl;  
	}

	virtual void Study() { //(가상)함수
		cout << "공부안하는 중입니다" << endl;
	}//오버라이딩. 가상함수를 설정함으로써 이 클래스를 상속받은 Student 객체는 Student객체의 Study를 실행


	void Info() { //함수
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}

	virtual ~Person(); //Person 객체 소멸
};

class Student : public Person { // 구조체 Student안에 구조체 Person이 상속됨
private:
	int grade; //변수선언
	int hour; //변수선언
	
public://함수 오버로드. 
	Student() : Person() { //Student함수 안의 Person함수
		hour = 10;
		grade = 3;
	} // Student 함수 안에 hour,grade가 각각 설정되었으면서, Person에서 있었던 것들을 모두 가져옴
	Student(char * myname, int myage, int mygrade, int myhour) : Person(myname, myage), grade(mygrade), hour(myhour) {}

	void Study() { //가상함수화 됨, 오버라이딩. 
		cout << hour << "시간 째 공부하는 중입니다." << endl; 
	}

	~Student(); //Student 객체 소멸

};//가상함수 : 포인터 변수가 실제로 가리키는 객체를 참조하여 호출의 대상을 결정함, 자신이 정말 호출은 매소드를 호출해 줄 수 있음.
// 가상함수를 사용해 주면 자식 클래스가 아닌 자신이 진짜 출력해준 클래스를 찾아가서 함수를 찾는다. parent의 함수를 찾아가서 출력
// 


//소멸시 소멸자 실행. 
Student::~Student() { //  ~은 소멸자, 소멸이 됬는지 안됬는지 보여주는 호출문
	cout << "학생 객체 소멸" << endl;
}
Person::~Person() { //  ~은 소멸자, 소멸이 됬는지 안됬는지 보여주는 호출문

	cout << "사람 객체 소멸" << endl;
}

int main()
{
	Person * ptr1 = new Person; //포인터 ptr1에 Person이라는 새로운 객체를 구조체 Person에 생성
	Person * ptr2 = new Student; //인자전달시 두번째 초기화함수 실행 됨.
	//동적할당(malloc)이나 new가 나오면 무조건 왼쪽부분에 포인터가 나와야 함.

	ptr1->Info(); 
	ptr1->Study(); //오버라이딩 관계지만 ptr1이 Person에 할당,
	//만약 부모클래스의 오버라이딩된 함수가 가상함수가 아니라면, 여기서 부모클래스의 Study 메소드 호출됨. 
	//그러나 가상함수가 되어있으므로 현재 포인터가 가리키고 있는 클래스의 Study 함수 불러옴.

	ptr2->Study(); //오버라이딩 관계지만 ptr2가 Student에 할당

	delete ptr1; // 삭제
	delete ptr2; // 삭제
	
	// int age = 17;
	// char name[] = "Junyoung";
	// char sName[] = "Jihyun";
	// int grd = 100;
	// int hr = 5;
	
	// Person jun = Person(name, age);
	// jun.Info();
	// jun.Study();
	
	// Student std = Student(sName, age, grd, hr);
	// std.Study();

}

//new와 delete는 같이 따라오는 경우, 생성자가 오버로딩, 함수가 같은데 받는 타입이 다름, 소멸자(delete)를 넣으면 어떻게 
//출력결과가 나오는지,,(교수님 단골 문제)