#include <iostream>
#include <stdlib.h>
#include <cstring>

int main(int argc, char** argv)
{
    char buff[1000];//넉넉하게 배열 공간 할당
    
    std::cout << "Enter the expression. " << std::endl;
    
    std::cin.getline(buff, 1000); //예를 들어 111+444를 입력받음
    
    //std::cout << (int)buff[0] << std::endl; 
    // 111+444
    //int oprnd_1 = (buff[0]-'0')*100 + (buff[1]-'0')*10 + (buff[2]-'0');
    //int oprnd_2 = (buff[4]-'0')*100 + (buff[5]-'0')*10 + (buff[6]-'0'); 
    
    char buff_1[100];//buff와는 또 다른 배열 공간 설정
    char buff_2[100];//buff와는 또 다른 배열 공간 설정
    
    strncpy(buff_1, buff, 3);//buff에서 입력 받은 char중 3 char까지 buff_1에 복사
    strncpy(buff_2, buff+4, 3);//buff+4부터 3 char까지 buff_2에 복사
    
    int oprnd_1 = atoi(buff_1);//새로운 변수에 buff_1에 초기화
    int oprnd_2 = atoi(buff_2);//새로운 변수에 buff_2에 초기화
    
    switch(buff[3])//배열 공간에서 4번째 공간을 읽었을 때
    {
        case '+'://그 공간에 +가 있으면
        std::cout << oprnd_1 + oprnd_2 << std::endl;
        break;
        
        case '-'://그 공간에 -가 있으면
        std::cout << oprnd_1 - oprnd_2 << std::endl;
        break;
        
        case '*'://그 공간에 *가 있으면
        std::cout << oprnd_1 * oprnd_2 << std::endl;
        break;
        
        case '/'://그 공간에 /가 있으면
        if(oprnd_2==0){ //나누기는 변수 하나가 0이면 에러가 뜨게 만듦
            std::cout<<"Error"<<std::endl;
        }
        else{
            std::cout << oprnd_1 / oprnd_2 << std::endl;
            
        }
        break;
        
        default:
        break;
        
    } 
    return 0;
    
}