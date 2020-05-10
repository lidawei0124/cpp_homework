#include "acount.h"
#include "date.h"
using namespace std;
Acount::Acount(Date day,string id1)//构造函数
{
    
    id = id1;
    balance = 0;
}
void Acount::record(Date day, float money, string info)//money可以是负数
{
    balance +=money;
    total += money;
    day.show();
    cout <<id<<": "<< money << "\t" << balance <<"\t"<<info<< endl;
    saverecord(day, id, money, info);//存档
}
void Acount::show()
{
    cout << "acount: " << id << "\t";
    cout << "balance: " << balance << "\t";
}
float Acount::gettotal()
{
    return total;
}
const float Acount::getbalance()
{
    return balance;
}
void Acount::saverecord(Date day,string id, float money, string info)//存档
{
    sav rec(day,id,money,info);
    // int totalday;
    const int totalday = day.gettotalday();
    bankrecordmap.insert(make_pair(totalday, rec));//把sav 和日期 映射到静态全局bank记录里面
}
void Acount::query(Date a,Date b)//查询
{
    // int c, d;
    const int c = a.gettotalday();
    const int d = b.gettotalday();
    multimap<int, sav>::iterator iter;//定义映射迭代器
    for (iter = bankrecordmap.lower_bound(c); iter != bankrecordmap.upper_bound(d); iter++)
    {
        iter->second.show();
    }
}