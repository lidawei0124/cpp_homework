#ifndef ACOUNT_H_
#define ACOUNT_H_

#include<iostream>
using namespace std;

class Acount
{
    private:
        char *id;//账号
        float balance;//余额
        float rate;//年利率
        float sum;//日余额累计
        int lastsavedate;//上次结算日期
    public:
        Acount(char *id1 = "0000", float rate1 = 0.015);//构造函数
        void show();//显示账户信息
        void update(int day);//每次存取款，结算以后，更新sum和lastsavedate
        void deposit(int day, float money);//第几天存款
        void withdraw(int day, float money);//第几天取款
        void settle(int day);//第90天结算

};
#endif