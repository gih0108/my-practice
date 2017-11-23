#include <stdio.h>
#include <iostream>
#include <cstring>
#include <iomanip>

struct student{ 
    char *name; 
    int age;
};

int main(){
    
   struct student s;
   s.age=10;
   strcpy(s.name,"kim1");
   s.name = "kim";
   
   std::cout<<s.name<<std::endl;
}