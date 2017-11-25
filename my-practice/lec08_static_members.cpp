#include<iostream>
//#include<string.h>
using namespace std;

class math{
    
    private:
    static int sum;
    static int facto;
    static int permu;
    
    public:
    math(){
        sum = 0;
        facto = 0;
        permu = 0;
    }
    
    static int summation(int a);
    static int factorial(int a);
    static int permutation(int a, int b);
    
};

int math::sum = 0;
int math::facto = 1;
int math::permu = 1;

int math::summation(int a){
    sum = 0;
    for(int i = 0; i<=a; i++)
        sum += i;
    return sum;

}

int math::factorial(int a){
    facto = 1;
    while(a!=0){
        facto  *= a;
        a-=1;
    }
    return facto;
}

int math::permutation(int a, int b){
    permu = 1;
    permu = math::factorial(a)/math::factorial(a-b);
    
    return permu;
}

int main(){
    int result1,result2,result3;
    
    result1 = math::summation(5);
    result2 = math::factorial(4);
    result3 = math::permutation(6,2);
    
    cout<<"sum:"<<result1<<endl;
    cout<<"factorial:"<<result2<<endl;
    cout<<"permutation:"<<result3<<endl;
    
    return 0;
}