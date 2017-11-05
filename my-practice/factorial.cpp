#include<stdio.h>
#include<iostream>

int factorial(int a); // function already declaration

int main(){
    int a, result;
    
    std::cout << "input:" ;//print "input" strings
    std::cin >> a; // input the number 
    
    if(a>=0){ // this function is factorial, so we can use this function in plus term
        result = factorial(a); //result value about factorial
        std::cout << a <<'!'<<'='<< result << std::endl; // ! and = is character so, we use' ' not " "
    } 
    else{ // this line is expected scope
        std::cout << "ERROR : negative interger" << std::endl; // error message
    }
}

int factorial(int a){ //factorial function
    int i; // local variable
    int result = 1; // initialize result value
    
    for(i=1;i<=a;i++)// about input number 
        result = result * i;// initialize result value because of  i
        
    return result;// return reult that will use in main function
}