#ifndef DATE_H_
#define DATE_H_

class Date
{
    public:
        Date(int y=1, int m=1, int d=1) : year(y), month(m), day(d){};
        int operator-(const Date &a);//重载运算符-，用于计算两个日期的差
        void show();//显示
        const int getyear();
        const int getmonth();
        const int getday();
    private:
        int year;
        int month;
        int day;
};
#endif