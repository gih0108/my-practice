#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

namespace CAR_CONST
{
    enum
    {
        ID_LEN = 20, MAX_SPD=200, FUEL_STEP=2,
        ACC_STEP=10, BRK_STEP=10
    };
}

class Car //class 선언
{
    private: //이어서 등장하는 변수와 함수는 private에 해당하는 범위 내에서(클래스 내에서만) 접근이 가능
        //private으로 선언된 변수들
        char gamerID[CAR_CONST::ID_LEN];
        int fuelGauge;
        int curSpeed;
    
    public: //이어서 등장하는 변수와 함수는 public에 해당하는 범위 내에서(어디서든) 접근이 가능
        //public으로 선언된 함수들 -> main에서 쓰여도 문제되지 않음
        void InitMembers(char * ID, int fuel);//클래스 안에 선언된 변수의 초기화를 목적으로 정의된 함수
        void ShowCarState();
        void Accel();
        void Break();
        
};

//변수가 모두 private으로 선언되어 main함수에서 접근이 불가능, 하지만 이 함수는 동일 클래스 내에 정의된 함수이므로 접근 가능
//또한, 이 함수는 public으로 선언되어서 main함수에서 호출이 가능함
//따라서 main함수에서는 이 함수의 호출을 통해서 클래스 안에 선언된 변수를 초기화할 수 있음(변수 자체는 접근 못하지만)
void Car::InitMembers(char * ID, int fuel)
{ 
    strcpy(gamerID,ID);
    fuelGauge = fuel;
    curSpeed = 0;
}
//fuelGauge,curSpeed변수를 쓸 수 있는 이유가 private으로 선언되었지만, 변수들을 포함하고 있는 InitMembers함수가 
//class Car에 같이 있었기 때문임, 즉 동일 클래스내에서 정의된 변수와 함수이기때문에 가능함

void Car::ShowCarState() //각 값들을 프린트해서 보여주는 함수
{
    cout << "소유자ID:" <<gamerID<<endl;//gamerID를 출력
    cout << "연료량:" <<fuelGauge << "%" << endl;//fuelGauge를 출력
    cout << "현재속도:" << curSpeed << "km/s" << endl << endl;//curSpeed를 출력
}

void Car::Accel()//Car class의 Accel함수
{
    if(fuelGauge<=0)// 만약 연료 게이지가 0이거나 0보다 작으면(음수)
    
        return;// 반환
    else// 0이상이면(양수)
        fuelGauge-=CAR_CONST::FUEL_STEP;//연료게이지=연료게이지-2
        
    if((curSpeed+CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)//만약 0+10의 값이 200보다 크면
    {
        curSpeed=CAR_CONST::MAX_SPD;//차속도=200
        return;//반환
    }
    curSpeed+=CAR_CONST::ACC_STEP;//위 조건 실행 후 차속도=차속도+10
}

void Car::Break()//Car class의 Break함수
{
    if(curSpeed<CAR_CONST::BRK_STEP)//만약 차속도가 20보다 작으면
    {
        curSpeed=0;//차속도=0
        return;//반환
    }
    curSpeed-=CAR_CONST::BRK_STEP;//위 조건 실행 후 차속도=차속도-10
}

int main(void)
{
    Car run99;
    //초기화를 목적으로 함수호출, 이 함수는 ID정보와 연료의 게이지 정보를 전달받아 초기화됨. 
    //단, 변수 curSpeed는 무조건 0으로 초기화 되도록 정의
    run99.InitMembers("21600555",100);//이렇게 클래스 안에 선언된 변수를 초기화할 수 있음
    
    //이렇게 함수의 호출이 가능한 이유가 모두 public으로 선언되었기 때문임
    run99.Accel();
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();
    return 0;
}