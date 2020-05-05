#include "acount.h"

Acount::Acount(Date day,char *id1,float rate1)//构造函数
{
    id = id1;
    rate = rate1;
    sum = 0;
    balance = 0;
    lastsavedate = day;
    day.show();
    cout << "acount " << id << " created" << endl;
}
void Acount::show()
{
    cout << "acount: " << id << " ";
    cout << "balance: " << balance << " ";
    cout << "rate: " << rate << endl;
}
void Acount::update(Date day)
{

    sum += balance * (day - lastsavedate);//更新日余额累计sum
    lastsavedate = day;//更新存款变动记录lastsavedate
}
void Acount::deposit(Date day,float money,string info)
{
    update(day);//更新sum和lastsavedate
    balance += money;
    day.show();
    cout <<id<<":"<< balance << "+" << money <<info<< endl;
    total += money;
}
void Acount::withdraw(Date day,float money,string info)
{
    update(day);//更新sum和lastsavedate
    balance -= money;
    day.show();
    cout <<id<<":"<< balance << "-" << money <<info<< endl;
    total -= money;
}
void Acount::settle(Date day)
{
    update(day);//更新sum和lastsavedate
    float tem = sum * rate / 365;//年利
    balance += tem;//年利存入余额
    sum = 0;//重置日余额累计
    total += tem;//年利存入total
}
void Acount::gettotal()
{
    cout << "total: " << total << endl;
}
