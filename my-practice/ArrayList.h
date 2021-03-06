#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE	1//'참'을 표한하기 위한 매크로 정의
#define FALSE	0//'거짓'을 표현하지 위한 매크로 정의

/*** ArrayList�� ���� ****/
#define LIST_LEN	100
typedef int LData;//LData에대한 typedef선언, 리스트에 int형 데이터의 저장을 위한 선언


typedef struct __ArrayList//배열기반 리스트를 정의한 구조체
{
	LData arr[LIST_LEN];//리스트의 저장소인 배열
	int numOfData;//저장된 데이터의 수
	int curPosition;//데이터 참조위치를 기록
} ArrayList;


/*** ArrayList�� ���õ� ������ ****/
typedef ArrayList List;//List는 배열 기반 리스트임

void ListInit(List * plist);//초기화
void LInsert(List * plist, LData data);//데이터의 저장

int LFirst(List * plist, LData * pdata);//첫 데이터 참조
int LNext(List * plist, LData * pdata);//두 번째 이후 데이터 참조

LData LRemove(List * plist);//참조한 데이터 삭제
int LCount(List * plist);//저장된 데이터의 수 반환

#endif

//데이터의 저장공간이 배열로 선언되었고 저장된 데이터의 수를 기록하기 위한 멤버도 존재
//참조의 위치를 기록하기 위한, LFirst와 LNext, 그리고 LRemove 함수를 위한 멤버도 존재
//리스트에 다양한 종류의 데이터를 저장할 수 있게하기 위한 typedef 선언도 존재