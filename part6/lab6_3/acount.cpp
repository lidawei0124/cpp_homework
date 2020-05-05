#include "acount.h"

Acount::Acount(char *id1,float rate1)//构造函数
{
    id = id1;
    rate = rate1;
    sum = 0;
    lastsavedate = 1;
    cout << "acount " << id << " created" << endl;
}
void Acount::show()
{
    cout << "acount: " << id << " ";
    cout << "balance: " << balance << " ";
    cout << "rate: " << rate << endl;
}
void Acount::update(int day)
{
    sum += balance * (day - lastsavedate);//更新日余额累计sum
    lastsavedate = day;//更新存款变动记录lastsavedate
}
void Acount::deposit(int day,float money)
{
    update(day);//更新sum和lastsavedate
    balance += money;
    cout <<id<<":"<< balance << "+" << money << endl;
}
void Acount::withdraw(int day,float money)
{
    update(day);//更新sum和lastsavedate
    balance -= money;
    cout <<id<<":"<< balance << "-" << money << endl;
}
void Acount::settle(int day)
{
    update(day);//更新sum和lastsavedate
    balance += sum * rate/365;//年利率存入余额
    sum = 0;//重置日余额累计
}
