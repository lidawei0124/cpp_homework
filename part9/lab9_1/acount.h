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
        static float total;//银行总共存款

    public:
        Acount(Date day,char *id1);//构造函数
        void record(Date day, float money, string info);//存取钱,利息，money可以是负
        const float getbalance();
        static float gettotal();
        virtual void show();//显示账户信息
        virtual void deposit(Date day, float money, string info) = 0;
        virtual void withdraw(Date day, float money, string info) = 0;
        virtual void settle(Date day) = 0;
};

#endif