#include<iostream>
using namespace std;

void F2C(float &F)
{
    F=(F - 32) * 5 / 9;
}

int main()
{
    float F = 0;
    cout << "input F:" << endl;
    cin >> F;
    F2C(F);//convert F to C
    cout << "C:" << F << endl;
    return 0;
}