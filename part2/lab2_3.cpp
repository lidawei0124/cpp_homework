#include<iostream>
using namespace std;
#define PI 3.1415926;

int main()
{
    int shapetype = 4,r=0,a=0,b=0,l=0;
    float area = 0;
    while((shapetype!=1)&&(shapetype!=2)&&(shapetype!=3))
    {
        cout <<"choose shape: 圆(1)，长方形（2），正方形(3): "<< endl;
        cin >> shapetype;
    }
    switch (shapetype)
    {
    case 1:
        /* 圆 */
        cout << "input radius: " << endl;
        cin >> r;
        area =r * r * PI;
        break;
    case 2:
        /* 长方形 */
        cout << "input a & b: " << endl;
        cin >> a>>b;
        cout << a << b;
        area = a * b;
        break;
    case 3:
        /* 正方形 */
        cout << "input length: " << endl;
        cin >> l;
        area = l*l;
        break;
    default:
        break;
    }
    cout << "area: " << area << endl;
    return 0;
}