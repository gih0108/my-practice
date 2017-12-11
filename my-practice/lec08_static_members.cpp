#include<iostream>

using namespace std;

class math{
    
    public:
    static int sum;
    static int facto;
    static int permu;
    
    /*이 부분 살짝 변형. 그래도 결과 값 출력되는데는 전혀 문제 없음.
    public:
    int sum1;
    int facto1;
    int permu1;
    
    math(){ //default constructor임을 주의!
        sum1 = 0;
        facto1 = 0;
        permu1 = 0;
    }*/
    
    
    //원래 public의 math함수 부분
    math(){ 
        sum = 0;
        facto = 0;
        permu = 0;
    }
    
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
    //cout<<"sum"<< endl;
    //cout<<sum<< endl;
    for(int i = 0; i<=a; i++)
        sum += i;
    //cout<<sum<< endl;
    return sum;

}

int math::factorial(int a){
    facto = 1;
    //cout<<"facto"<< endl;
    //cout<<facto<< endl;
    while(a!=0){
        facto  *= a;
        a-=1;
    }
    //cout<<facto<< endl;
    return facto;
    
}

int math::permutation(int a, int b){
    permu = 1;
    //cout<<"permu"<< endl;
    //cout<<permu<< endl;
    permu = math::factorial(a)/math::factorial(a-b);
    //cout<<permu<< endl;
    return permu;
}
//factorial함수가 permutation함수에서 쓰이기 때문에 static변수로 선언된 변수들은 모두 초기화 과정이 필요하다

int main(){
    int result1,result2,result3;
    
    result1 = math::summation(5);
    result2 = math::factorial(4);
    result3 = math::permutation(6,2);
    
    cout<<"sum:"<<result1<<endl;
    cout<<"factorial:"<<result2<<endl;
    cout<<"permutation:"<<result3<<endl;

    /*임의로 만듦.
    math math1;//math class에 math1이라는 객체
    cout << "default constructor variable : " << math1.sum1 << ","<<math1.facto1<<","<<math1.permu1 << endl;
    */

    return 0;
}



//question : public의 math()함수는 왜 있는거? 저걸 없애도(주석처리 된 곳) 답 출력되는 데는 별 문제 없던데..
//지금은 내가 변수이름이 겹쳐서 1을 붙여서 바꿔서 출력되게 만들었는데 출력됨. 원래 변수대로 하면 이미 선언된 변수라고 하면서 오류.
//어쨌든 이 문제의 답을 출력하는데는 별 문제 없어서 보이는데 왜 굳이 만들어준거인지?여기서는 무슨 용도?
//원래는 main함수에서 배열 생성 시 필요한 생성자를 추가하는 것으로 알고 있음


/*
math()이 있는 이유는 생성자로써 private의 static int 변수를 초기화 해주는것  
없애도 문제가 되지 않는 것은 line 39~ 41에서  static 변수를 한번 더 초기화 해주기 때문에 그냥 돌아가는 것임

결국 코드가 보여주고자 하는 것은 static 변수를 초기화 하기 위해서는 코드 외부에서
int math::sum = 0; 같은 형태로 해야되는 것을 알려주고자 함 
*/



//class밖에서 static 멤버 변수들에 대해 초기화를 시켜 주었는데
//왜 각 sum, factorial, permutation함수에서는 또 초기화가 되어있는거?
//class밖에서 초기화시킨 멤버변수들을 없애면 에러뜨고, sum, factorial, permutation함수에서 초기화 시킨걸 없애면
//permutation만 값이 0이됨. 결과가 달라짐.왜?


/*static 변수의 특징은 같은 클래스 내에서 변수값이 공유가 되고 다른 함수에서 수정한 값이 그대로 남는다는
특징을 갖고있다.
함수의 기능을 해주는 코드에서 각 변수들을 또 초기화를 해준 이유는 
앞에서 말했듯이 static 변수 특성 상 값이 남기 때문에 함수를 두 번 불러쓰게 되면 ,
ex) facto(4) 결과가 15가 나왔는데 이 15가 facto 값에 남으면서 다음에 permu 계산할때 
필요한 facto 값 1대신 15가 들어가게 됨 
내가 원치않는 이전의 연산 결과 값이 입력 값으로 들어가게 되기때문에 매번 함수를 불러낼 때마다
변수들의 초기화 과정이 필요함.

line 117 질문 : 앞에서 말헀듯이 함수내의 초기화를 지워버리면 이전 결과값으로 연산을 하기 떄문에
17280 / 414720 이라는 연산을 하게됨. 결과는 0.xxxx 겠지만 int 이므로 결과가 0이 출력될 것임

따라서 코드에서 보여주고자 하는 것은 static 변수의 특성과 초기화를 통해 원래 원하던 값으로
어떻게 출력하는지를 보여주는 것
*/

/*output : 
sum:15
factorial:24
permutation:30
*/