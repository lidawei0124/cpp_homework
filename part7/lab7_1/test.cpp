#include "savingacc.h"
#include "creditacc.h"

float Acount::total = 0;
int main()
{
    Date date(2008, 11, 1);
    Savingacc sa1(date, "s3755217", 0.015);
    Savingacc sa2(date, "02342342", 0.015);
    Creditacc ca(date, "C5392394", 0.0005, 10000, 50);
    //11月账单
    sa1.deposit(Date(2008, 11, 5), 5000, "salary0");
    ca.withdraw(Date(2008, 11, 15), 2000, "buy a cell");
    sa2.deposit(Date(2008, 11, 25), 10000, "sell stock 0323");
    //结算信用卡
    ca.settle(Date(2008, 12, 1));
    //12月账单
    ca.deposit(Date(2008, 12, 1), 2016, "repay the credit");
    sa1.deposit(Date(2008, 12, 5), 5500, "salary");
    //年初结算
    sa1.settle(Date(2009, 1, 1));
    sa2.settle(Date(2009, 1, 1));
    ca.settle(Date(2009, 1, 1));

    sa1.show();
    sa2.show();
    ca.show();
    Acount::gettotal();
    return 0;
}