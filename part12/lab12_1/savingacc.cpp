#include "savingacc.h"
#include "error.h"
void Savingacc::deposit(Date day, float money, string info)
{
    record(day,money,info);//显示
    sum.change(day,this->getbalance());//更新累计sum
}
void Savingacc::withdraw(Date day, float money, string info)
{
    if(money>(getbalance()))//如果金额超出信用额度
        throw Accexcept(this, "out of balance");
    record(day,-money,info);//显示
    sum.change(day,this->getbalance());//更新累计sum
}
void Savingacc::settle(Date day)
{
    if(day.getmonth()==1&&day.getday()==1)
    {
        float sum1=sum.getsum(day);
        float in = sum1 * rate / 365;
        record(day, in, "settle");
        sum.reset(day,this->getbalance());
    }
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