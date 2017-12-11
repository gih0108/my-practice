#include <stdio.h>
#include "ArrayList.h"
#include "ArrayList.c" //함수 구현한 c 파일도 include 시켜줘야 함



int main(void)
{
    List list;//리스트의 생성
    int data;
    ListInit(&list);//리스트의 초기화
    //ListInit은 관련된 변수들의 초기화가 선행되어야 하기 때문에 이것을 담당하는 함수이다
    
    //리스트에 11을 각각 1회씩 저장
    LInsert(&list, 11);
    LInsert(&list, 11);
    //리스트에 22을 각각 1회씩 저장
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);//리스트에 33을 저장
    //Insert함수를 호출하면서 리트스의 주소 값을 첫 번째 인자로, 그리고 리스트에 담을 데이터를 두번 째 인자로 전달하고 있음
    
    printf("현재 데이터의 수 : %d\n" , LCount(&list));
    
    if(LFirst(&list, &data))//첫 번째 데이터를 변수 data에 저장
    {
        printf("%d ",data);
        
        while(LNext(&list, &data))//두 번째 이후의 데이터를 변수 data에 저장
            printf("%d ",data);
    }//LNext함수를 호출할 때마다 다음에 저장된 데이터를 얻을 수 있음.
    //리스트 내에서 데이터의 참조위치를 기록하기 때문에 가능, 이를 목적으로 LFirst 함수 호출
    printf("\n\n");
    
    if(LFirst(&list, &data))
    {
        if(data == 22)
            LRemove(&list);//위의 LFirst 함수를 통해 참조한 데이터 삭제!
            
        while(LNext(&list, &data))
        {
            if(data == 22)
                LRemove(&list);//위의 LNext 함수를 통해 참조한 데이터 삭제!
        }
    }
    
    printf("현재 데이터의 수 : %d\n" ,LCount(&list));
    
    if(LFirst(&list, &data))
    {
        printf("%d ",data);
        
        while(LNext(&list,&data))
            printf("%d ",data);
    }
    printf("\n\n");
    return 0;
    
}

/*output : 
11 11 22 22 33 

현재 데이터의 수 : 3
11 11 33 
*/