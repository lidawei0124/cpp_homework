#ifndef CREDITACC_H_
#define CREDITACC_H_

#include "sum.h"
#include "acount.h"
class Creditacc:public Acount
{
    public:
        Creditacc(Date day,char *id,float rate,float credit,float fee):Acount(day, id),sum(day,0),rate(rate),credit(credit),fee(fee)
        {
            day.show();
            cout << "creditacount " << id << " created" << endl;
        }
        void deposit(Date day, float money, string info);
        void withdraw(Date day, float money, string info);
        void settle(Date day);
        void show();
        const float getdebt();
        const float getrate();
        const float getcredit();
        const float getfee();
        const float getcreditnow();
    private:
        Sum sum;
        float rate;//信用日利息，每月1结算
        float credit;//信用额度
        float fee;//年费，每年1/1结算
};

#endif