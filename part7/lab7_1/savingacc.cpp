#include "savingacc.h"

void Savingacc::deposit(Date day, float money, string info)
{
    record(day,money,info);//显示
    sum.change(day,this->getbalance());//更新累计sum
}
void Savingacc::withdraw(Date day, float money, string info)
{
    record(day,-money,info);//显示
    sum.change(day,this->getbalance());//更新累计sum
}
void Savingacc::settle(Date day)
{
    float sum1=sum.getsum(day);
    float in = sum1 * rate / 365;
    record(day, in, "settle");
    sum.reset(day,this->getbalance());
}
void Savingacc::show()
{
    cout << "saving";
    Acount::show();
    cout << endl;
}

const float Savingacc::getrate()
{
    return rate;
}