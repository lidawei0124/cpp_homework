#include "acount.h"

Acount::Acount(Date day,char *id1)//构造函数
{
    id = id1;
    balance = 0;
}
void Acount::record(Date day, float money, string info)//money可以是负数
{
    balance +=money;
    total += money;
    day.show();
    cout <<id<<": "<< money << " " << balance <<"  "<<info<< endl;
}
void Acount::show()
{
    cout << "acount: " << id << " ";
    cout << "balance: " << balance << " ";
}
void Acount::gettotal()
{
    cout << "total: " << total << endl;
}
const float Acount::getbalance()
{
    return balance;
}
