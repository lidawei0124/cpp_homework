#include <iostream>
using namespace std;
int main()
{

    struct time
    {
        int y;//year
        int m1;//month
        int d;//day
        int h;//hour
        int m2;//minute
        int s;//second
    };
    time timeofnow;
    cout << "input time of now (y/m/d/h/m/s): " << endl;
    cin >> timeofnow.y >> timeofnow.m1 >> timeofnow.d >> timeofnow.h >> timeofnow.m2 >> timeofnow.s;//输入
    cout << timeofnow.y << '/' << timeofnow.m1 << '/' <<timeofnow.d<<':';//输出
    cout<<timeofnow.h<<':'<< timeofnow.m2 <<':'<< timeofnow.s<<endl;//输出
    return 0;
}