#include<iostream>

using namespace std;

class math{
    
    private:
    static int sum;
    static int facto;
    static int permu;
    
    public:
    math(){ //default constructor임을 주의!
        sum = 0;
        facto = 0;
        permu = 0;
    }
    
    //static member function들임!!
    static int summation(int a);
    static int factorial(int a);
    static int permutation(int a, int b);
    
    //void printmath(int _sum, int _facto, int _permu);
    
    
};

int math::sum = 0;//math class의 sum 변수가 0으로 초기화
int math::facto = 1;//math class의 facto 변수가 1으로 초기화
int math::permu = 1;//math class의 permu 변수가 1으로 초기화
//static으로 선언된 멤버 변수들은 class 밖에서 초기화 시켜 줘야 한다. 


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
    //math::math();
    
    return 0;
}