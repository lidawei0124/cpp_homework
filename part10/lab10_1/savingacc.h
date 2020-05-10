#ifndef SAVINGACC_H_
#define SAVINGACC_H_
#include "acount.h"
#include "sum.h"
class Savingacc:public Acount
{
    public:
        Savingacc(Date day, string id1, float rate) : Acount(day, id1),sum(day,0),rate(rate)
        {
            day.show();
            cout << "savingacount " << id1 << " created" << endl;
        }
        const float getrate();

        void deposit(Date day, float money, string info);
        void withdraw(Date day, float money, string info);
        void settle(Date day);
        void show();
    private:
        Sum sum;
        float rate;
};
#endif