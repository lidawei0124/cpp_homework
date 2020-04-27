#include<iostream>
#include<cmath>
using namespace std;

int Max1(int a,int b)
{
    return a >= b ? a : b;
}
int Max1(int a,int b,int c)
{
    return Max1(Max1(a, b), c);
}
float Max1(float a,float b)
{
    return a >= b ? a : b;
}
float Max1(float a,float b,float c)
{
    float d;
    d = Max1(a, b);
    return Max1(c, d);
}

int main()
{
    int a = 12, b = 13, c = 12;
    float a1 = 12.5, b1 = 13.4, c1 = 13.4;
    cout << "max of 12&13 is:" << Max1(a, b) << endl;
    cout << "max of 12&13&12 is :" << Max1(a, b,c) << endl;
    cout << "max of a1 = 12.5, b1 = 13.4 is:" << Max1(a1, b1) << endl;
    cout << "max of a1 = 12.5, b1 = 13.4, c1 = 13.4 is :" << Max1(a1, b1,c1) << endl;
    return 0;
}

