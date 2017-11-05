# include<iostream>

int main(){
    
    int i, div, scores[10];
    char grades[10];
    std::cout << "Input 10 socres:" << std::endl;
    
    for(i = 0; i<10; i++){
        std::cin >> scores[i];
        div = scores[i]/10;
        
        switch(div){
            case 10:
            case 9: grades[i] = 'A';
                break;
            case 8: grades[i] = 'B';
                break;
            case 7 : grades[i] = 'C';
                break;
            case 6 : grades[i] = 'D';
                break;
            default: grades[i] = 'F';
                break;
        }
    }
    
    for(i=0;i<10;i++){ 
    std::cout << '['<< i <<']'<< '(' << scores[i] << '/' << 100 << ')' << grades[i] <<std::endl;
    }
}