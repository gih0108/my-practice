# include<iostream>
int func();

int global;

main(){
    int local = 1, local_in_main;
    
    std::cout << "global in main:" << global << std::endl;
    std::cout << "local in main:" << local << std::endl;
    
    int func();// not read in environment, error
}

int func(){
    int global = 99, local = 2, local_in_main = 3;
    
    std::cout << "global in func:" << global << std::endl;
    std::cout << "local in func:" << local << std::endl;
    std::cout << "local_in_main in func:" << local_in_main << std::endl;
    
}
// error for unknown variable : not visible here