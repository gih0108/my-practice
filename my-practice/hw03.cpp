#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1024

typedef struct Node //Node라는 구조체를 선언
{
	char value[1024]; // value라는 값에 메모리 공간 1024만큼 할당
	struct Node *prev; // Node라는 구조체 안에 prev라는 포인터 변수 설정,
	//(Node가 가지고 있는 head와 tail에 별도로 들어가는 공간,init함수를 보면 알 수 있음)
	struct Node *next; // Node라는 구조체 안에 next라는 포인터 변수 설정, 메모리 공간이 할당될 것.
	//(Node가 가지고 있는 head와 tail에 별도로 들어가는 공간,init함수를 보면 알 수 있음)
}Node; // Node라는 이름이 이미 정의되어있지만  Node라는 구조체 이름에 새로운 별명인  Node를 붙여줌.

Node *head; // Node의 head라는 공간이 할당됨.
Node *tail; // Node의 tail이라는 공간이 할당됨.
//전역변수로 설정된 포인터 변수들이기 때문에 제일 메인으로 설정되는 공간들이다.

void init() 
{
	head = (Node*)malloc(sizeof(Node)); // head라는 변수에 Node 사이즈만큼 메모리 공간 동적 할당(Node가 가리키는 공간에서)
	tail = (Node*)malloc(sizeof(Node)); // tail이라는 변수에 Node 사이즈만큼 메모리 공간 동적 할당(Node가 가리키는 공간에서)
	head->prev = NULL; // 시작지점의 prev에 아무것도 없음
	head->next = tail; // prev 다음에 tail이라는 변수 할당, tail 포인터가 가리키는 변수가 들어갈 것
	tail->next = NULL; // 마지막지점의 next는 아무것도 없음
	tail->prev = head; // tail의 앞 시점은 head라는 변수 할당, head포인터가 가리키는 변수가 들어갈 것
}

void Insert(char *data) // Insert라는 함수 선언
{
	Node *New = (Node*)malloc(sizeof(Node)); // Node가 가리키는 공간에서 New라는 포인터변수에 Node사이즈만큼 메모리 공간 동적할당
	//앞에 선언된 Node의 head와 tail의 공간이 손상되지 않으면서 Node의 New라는 새로운 공간을 할당해주는 것임.
	strcpy(New->value, data); // data에 들어온 값을 New의 value라는 메모리 공간에 복사
	tail->prev->next = New; // head->next = tail에 New 값을 할당
	New->prev = tail->prev; // head의 공간이 New->prev=NULL에 할당
	New->next = tail; // New라는 공간에 tail이라는 메모리 공간이 새롭게 형성
	tail->prev = New; // head라는 공간에 New라는 메모리 공간 형성
} // init에 사용된 변수와 그 기능을 이용하여 insert라는 함수는 생성(New라는 새로운 공간을 할당하여 전에 선언하였던 메모리 공간을 해치지 않음)

void Print_Reverse() // Print_reverse함수 선언
{				
	Node *Back = tail->prev; // Node가 가리키는 공간에서 Back이라는 포인터 변수에 head라는 메모리 공간 형성
	while (Back != head) { // Back이 head가 될 때까지 계속 실행하는 반복문
		printf("%s\n", Back->value); // Back의 value값을 프린트 해줌
		Back = Back->prev;//ddsds
	}
}


int main()
{
	init();
	char *line[MAX_LEN] = {"Geoffrey", "Yoshua", "Yann", "Cho", "Alex"};
	printf("Original Data:\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", line[i]);
		Insert(line[i]);
	}
	printf("\nReversed Order:\n");
	Print_Reverse();

	return 0;

}