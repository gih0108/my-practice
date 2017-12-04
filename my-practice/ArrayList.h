#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE	1//'참'을 표한하기 위한 매크로 정의
#define FALSE	0//'거짓'을 표현하지 위한 매크로 정의

/*** ArrayList�� ���� ****/
#define LIST_LEN	100
typedef int LData;//LData에대한 typedef선언


typedef struct __ArrayList//배열기반 리스트를 정의한 구조체
{
	LData arr[LIST_LEN];//리스트의 저장소인 배열
	int numOfData;//저장된 데이터의 수
	int curPosition;//데이터 참조위치를 기록
} ArrayList;


/*** ArrayList�� ���õ� ������ ****/
typedef ArrayList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

#endif