# include<iostream>

int main(){
    int i;
    int num1[5] = {100,90,80,70,60};
    int num2[5];
    

    for(i=0;i<5;i++)
        num2[i] = num1[i];
    for(i=0;i<5;i++)
        std::cout << num2[i] << std::endl;
        
    /*num2 = num1;
    for(i=0;i<5;i++)
        std::cout << num2[i] << std::endl;*/
}