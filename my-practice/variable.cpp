#include<iostream>

void func1();
int gl;

int main(){
    int lo = 1, gl = 1;
    func1();
    std::cout << "Initial value of global:" << gl << std::endl;
    std::cout << "Initial value of local:" << lo << std::endl;
}

void func1(){
    int lo = 2; // if out of function, that is delete
}

