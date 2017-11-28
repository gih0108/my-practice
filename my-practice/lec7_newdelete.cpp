# include<iostream>
#include<string.h>

using namespace std;

// 길이정보를 인자로 받아서, 해당 길이의 문자열 저장이 가능한 배열을 생성하고, 
// 그 배열의 주소 값을 반환하는 함수

char * MakeStrAdr(int len)
{
    char * str = new char[len]; // 해당 길이의 문자열 저장이 가능한 배열 생성
    return str; // 그 배열의 주소 값 반환
}

int main(void)
{
    char *str = MakeStrAdr(20); // 해당 길이의 문자열과 길이정보를 인자로 받음
    strcpy(str,"I am so happy~");// 문장을 str이라는 공간에 저장, str 공간에는 20크기의 배열공간이 만들어짐.
    cout << str << endl; //str 문장 출력
    delete []str; // 앞서 할당한 char형 str배열의 소멸
    return 0;
}