#include<stdio.h>
#include<iostream>

void swap(int * ptr1, int * ptr2); 
void swap(char * ptr1, char * ptr2);//미리 선언  오버라이딩 
void swap(double * ptr1, double * ptr2);
//this line is very important because of call by reference, pointer

int main(void){
    int num1 = 20, num2 = 30;
    swap(&num1,&num2);
    std::cout << num1 <<' '<< num2 << std::endl;
    
    char ch1 = 'A', ch2 = 'Z';
    swap(&ch1,&ch2);
    std::cout << ch1 <<' ' << ch2 << std::endl;
    
    double db1 = 1.111, db2 = 5.555;
    swap(&db1,&db2);
    std::cout << db1 <<' '<< db2 << std::endl;

    return 0;
}

void swap(int * ptr1, int * ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void swap(char * ptr1, char * ptr2){
    char temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void swap(double * ptr1, double * ptr2){
    double temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}