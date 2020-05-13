#ifndef ACOUNT_H_
#define ACOUNT_H_
#include "date.h"
#include<iostream>
#include<string>
#include<map>
using namespace std;


class sav//记录存取记录
{
    public:
        Date date;
        string id;
        float money;
        string desc;
        sav(Date d, string i, float m, string de) : date(d), id(i), money(m), desc(de){};
        const void show()
        {
            date.show();
            cout << id << "\t" << money << "\t" << desc << "\t" << endl;
        }
};
class Acount
{
    private:
        string id;//账号
        float balance;//余额
        static float total;//银行总共存款
        static multimap<int, sav> bankrecordmap;//静态 银行记录成员
    public:
        Acount(Date day,string id1);//构造函数
        void record(Date day, float money, string info);//存取钱,利息，money可以是负
        const float getbalance();
        static float gettotal();
        virtual void show();//显示账户信息
        virtual void deposit(Date day, float money, string info) = 0;
        virtual void withdraw(Date day, float money, string info) = 0;
        virtual void settle(Date day) = 0;
        static void saverecord(Date day,string id,float money, string info);//存档
        static void query(int y1,int m1,int d1,int y2,int m2,int d2);//查询
};

#endif