#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

char * MakeStrAdr(int len)
{
    char * str1 = (char*)malloc(sizeof(char)*len);
    char * str2 = (char*)malloc(sizeof(char)*len);
    return str1;
    return str2;
}

int main(void)
{
    char *str1 = MakeStrAdr(20);
    char *str2 = MakeStrAdr(20);
    strcpy(str1, "I am so happy~");
    strcpy(str2, "I am so hungry~");
    cout << str1 << endl;
    cout << str2 << endl;
    free(str1);

    free(str2);
    return 0;
    
}