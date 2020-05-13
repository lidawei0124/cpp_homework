#ifndef DATE_H_
#define DATE_H_

class Date
{
    public:
        Date(int y=1, int m=1, int d=1) : year(y), month(m), day(d){};
        Date(const Date &a)
        {
            year = a.year;
            month = a.month;
            day = a.day;
        }
        int operator-(const Date &a);//重载运算符-，用于计算两个日期的差
        bool operator <(const Date &a);//重载比较运算符
        bool operator >(const Date &a);//重载比较运算符
        void show();//显示
        const int getyear();
        const int getmonth();
        const int getday();
        int gettotalday();
        const void changeyear(int y);
        const void changemonth(int m);
        const void changeday(int d);
        int getmaxday();
        void read();//从键盘修改日期
    private:
        int year;
        int month;
        int day;
};
#endif