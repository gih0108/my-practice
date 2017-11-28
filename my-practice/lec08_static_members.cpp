#include<iostream>

using namespace std;

class math{
    
    private:
    static int sum;
    static int facto;
    static int permu;
    
    //이 부분 살짝 변형. 그래도 값 출력되는데는 전혀 문제 없음.
    public:
    int sum1;
    int facto1;
    int permu1;
    
    math(){ //default constructor임을 주의!
        sum1 = 0;
        facto1 = 0;
        permu1 = 0;
    }
    
    
    /* 원래 public의 math함수 부분
    math(){ 
        sum = 0;
        facto = 0;
        permu = 0;
    }*/
    
    //static member function들임!!
    static int summation(int a);
    static int factorial(int a);
    static int permutation(int a, int b);

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
    
    //임의로 만듦.
    math math1;//math class에 math1이라는 객체
    cout << "default constructor variable : " << math1.sum1 << ","<<math1.facto1<<","<<math1.permu1 << endl;

    return 0;
}



//question : public의 math()함수는 왜 있는거? 저걸 없애도(주석처리 된 곳) 답 출력되는 데는 별 문제 없던데..
//지금은 내가 변수이름이 겹쳐서 1을 붙여서 바꿔서 출력되게 만들었는데 출력됨. 원래변수대로 하면 이미 선언된 변수라고 하면서 오류.
//어쨌든 이 문제의 답을 출력하는데는 별 문제 없어서 보이는데 왜 굳이 만들어준거인지?무슨 용도?

//아직 static에 대한 이해를 제대로 못해서 그런지 class밖에서 static 멤버 변수들에 대해 초기화를 시켜 주었는데
//왜 각 sum, factorial, permutation함수에서는 또 초기화가 되어있는거?
//class밖에서 초기화시킨 멤버변수들을 없애면 에러뜨고, sum, factorial, permutation함수에서 초기화 시킨걸 없애면
//permutation만 값이 0이됨. 결과가 달라짐.왜?
