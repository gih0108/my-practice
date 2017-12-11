# include<iostream>

int overloadSum(int a, int b, int c)
{
    std::cout << "(i i i) version" << std::endl;
    return (a+b+c);
}

float overloadSum(float a, float b, float c)
{
    std::cout << "(f f f) version" << std::endl;
    return (a +b +c);
}

float overloadSum(int a , float b, float c) // 만약 type형이 int 였으면 compile error가 났을 것. float이 int보다 
//담는 정보가 더 많다.
{
    std::cout << "(i f f) version" << std::endl;
    return (a+b+c);
}

int main(void)
{
    float ans;
    float f1 = 6.4;
    float f2 = 4.2;
    int i1 = 4;
    int i2 = 6;
    
    ans = overloadSum(f1, f2, f2);
    std::cout << ans << std::endl;
    ans = overloadSum(i1, i2, i2);
    std::cout << ans << std::endl;
    ans = overloadSum(i2,(float)i1,f1);//float 빼도 올바른 답은 나옴
    std::cout << ans << std::endl;
    
    return(0);
}

/*output:
(f f f) version
14.8
(i i i) version
16
(i f f) ver
*/