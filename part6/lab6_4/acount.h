#ifndef ACOUNT_H_
#define ACOUNT_H_
#include "date.h"
#include<iostream>
#include<string>
using namespace std;

class Acount
{
    private:
        char *id;//账号
        float balance;//余额
        float rate;//年利率
        float sum;//日余额累计
        Date lastsavedate;//上次结算日期
        static float total;//银行总共存款

    public:
        Acount(Date day,char *id1 = "0000", float rate1 = 0.015);//构造函数
        void show();//显示账户信息
        void update(Date day);//每次存取款，结算以后，更新sum和lastsavedate
        void deposit(Date day, float money,string info);//第几天存款
        void withdraw(Date day, float money,string info);//第几天取款
        void settle(Date day);//第90天结算
        static void gettotal();
};
#endif