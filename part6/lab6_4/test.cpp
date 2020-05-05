#include "acount.h"
#include "date.h"

float Acount::total = 0;
int main()
{
    Date date(2008, 11, 1);
    Acount accounts[] =
        {
            Acount(date, "s375667", 0.015),
            Acount(date, "0232413", 0.015)};
    accounts[0].deposit(Date(2008,11,5),5000,"salary");
    accounts[1].deposit(Date(2008,11,25),10000,"sell stock 0323");

    accounts[0].deposit(Date(2008,12,5),5500,"salary");
    accounts[1].withdraw(Date(2008,12,20),4000,"buy a laptop");

    for(Acount e:accounts)
    {
        e.settle(Date(2009, 1, 1));
        e.show();
    }
    Acount::gettotal();
    return 0;
}