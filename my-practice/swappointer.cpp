#include<iostream>
using namespace std;

void SwapPointer(int *(&pref1), int *(&pref2)) // 함수가 포인터 pref1과 pref2이라는 변수를 참조
{
    int *ptr = pref1;// pref1는 포인터 ptr에 할당
    pref1 = pref2;// pref2는 pref1에 할당, 값이 바뀜
    pref2 = ptr;// ptr 값은 pref2에 할당
}

int main(void)
{
    int num1 = 5; // num1변수에 5 할당
    int *ptr1=&num1; // num1의 주소 값이 포인터 ptr1이라는 공간에 할당
    
    int num2 = 10; // num2변수에 10 할당
    int *ptr2=&num2; // num2의 주고 값이 포인터 ptr2라는 공간에 할당
    
    cout << *ptr1 <<endl; // 포인터 ptr1출력
    cout << *ptr2 << endl; // 포인터 ptr2 출력
    
    SwapPointer(ptr1,ptr2); // swappointer 함수 작동,ptr1과 ptr2를 변수로 받음
    // 여기서 *ptr1, *ptr2로 바뀌면 num1, num2를 가리키게 되므로 참조자 pref1, pref2가 읽지 못하게 됨. 그래서 값이 바뀌지는 않음
    
    cout << *ptr1 << endl; // 포인터 ptr1이 출력
    cout << *ptr2 << endl; // 포인터 ptr2가 출력
    return 0;
}