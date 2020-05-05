#include<iostream>
#include "date.h"
using namespace std;

bool isLeapYear(int year)//判断闰年
{
	return ((year%4==0 && year%100!=0) || year%400==0);
}
int getdays(int y,int m)//获得y年m月1日相对y年1月1日天数
{
    int result = 0;
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(isLeapYear(y))
    {
        month[2]++;//闰年2 月 29天
    }
    for(int i = 0;i < m-1;i++)
	{
		result += month[i];
	}
    return result;
}
int totalday(int y,int m,int d)//计算日期相对与元年的差距
{
    int total;
    total = 365 * (y - 1)+(y-1)/4-(y-1)/100+(y-1)/400+getdays(y,m)+d;
    //total=f(y/1/1,1/1/1)+f(y/m/1,y/1/1)+f(y/m/d,y/m/1)
}
int Date::operator-(const Date &a)//重载运算符-，用于计算两个日期的差
{
    int total1, total2;
    total1 = totalday(this->year, this->month, this->day);
    total2 = totalday(a.year, a.month, a.day);
    return (total1 - total2);
}
void Date::show()
{
    cout << year << "/" << month << "/" << day << endl;
}