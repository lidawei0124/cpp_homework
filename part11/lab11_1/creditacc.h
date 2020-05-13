#ifndef CREDITACC_H_
#define CREDITACC_H_

#include "sum.h"
#include "acount.h"
class Creditacc:public Acount
{
    public:
        Creditacc(Date day,string id,float rate,float credit,float fee):Acount(day, id),sum(day,0),rate(rate),credit(credit),fee(fee)
        {
            day.show();
            cout << "creditacount \t" << id << " \tcreated" << endl;
        }
        const float getdebt();
        const float getrate();
        const float getcredit();
        const float getfee();
        const float getcreditnow();

        void deposit(Date day, float money, string info);
        void withdraw(Date day, float money, string info);
        void settle(Date day);
        void show();
    private:
        Sum sum;
        float rate;//信用日利息，每月1结算
        float credit;//信用额度
        float fee;//年费，每年1/1结算
};

#endif