# include<iostream>
# include<cstring>
# include<string.h>

int main(void){

    char *str1 = "ABC 123";
    char *str2 = "DEF 456";
    char str3[50];
    
    std::cout << strlen(str1) << std::endl;
    std::cout << strlen(str2) << std::endl;
    strcpy(str3, str1);
    strcat(str3, str2);
    std::cout << str3 << std::endl;
    
    if(strcmp(str1,str2) == 0)
        std::cout << "string is same" << std::endl;
    else
        std::cout << "string is not same" << std::endl;
    return 0;
}