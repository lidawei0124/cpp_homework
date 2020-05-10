#include "creditacc.h"

void Creditacc::deposit(Date day, float money, string info)
{
    record(day,money,info);//显示
    if(this->getbalance()<0)//负债了才累计利息
    {
        sum.change(day,this->getbalance());//更新累计sum
    }
    else
    {
        sum.change(day,0);//更新累计sum
    }
}
void Creditacc::withdraw(Date day, float money, string info)
{
    record(day,-money,info);//显示
    if(this->getbalance()<0)//负债了才累计利息
    {
        sum.change(day,this->getbalance());//更新累计sum
    }
    else
    {
        sum.change(day,0);//更新累计sum
    }
}
void Creditacc::settle(Date day)//每月结算日1号，每年1月1日结算年费
{
    float interest;
    interest = sum.getsum(day) * rate;
    record(day, interest, "month interest");
    if(day.getmonth()==1&&day.getday()==1)//1/1日结算年费
    {
        record(day, -fee, "fee");
    }
    if(this->getbalance()<0)//负债了才累计利息
    {
        sum.reset(day,this->getbalance());//更新累计sum
    }
    else
    {
        sum.reset(day,0);//更新累计sum
    }
}
void Creditacc::show()
{
    cout << "credit\t";
    Acount::show();
    cout << "available credit:\t" << getcreditnow() << endl;
}
const float Creditacc::getdebt()//获取余额
{
    return getbalance();
}
const float Creditacc::getrate()
{
    return rate;
}
const float Creditacc::getcredit()
{
    return credit;
}
const float Creditacc::getfee()
{
    return fee;
}
const float Creditacc::getcreditnow()
{
    float creditnow = 0;
    if(getbalance()>=0)
    {
        creditnow = credit;
    }
    else
    {
        creditnow = credit + getbalance();
    }
    return creditnow;
}