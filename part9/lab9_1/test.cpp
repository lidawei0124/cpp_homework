#include "savingacc.h"
#include "creditacc.h"

#include "array.h"
float Acount::total = 0;
int main()
{
    Date date(2008, 11, 1);
    // Savingacc sa1(date, "sa1", 0.015);
    // Savingacc sa2(date, "sa2", 0.015);
    // Creditacc ca(date, "ca", 0.0005, 10000, 50);
    // Acount *acc[] = {&sa1, &sa2, &ca};
    cout << "(o)saving acc(p) credit acc(d) deposit (w)withdraw s(show) c(changeday) n(nextmonth) e(exit)" << endl;
    char cmd;
    Array<Acount*> acc(0);
    int accindex = 0;
    do
    {
        //显示日期和总金额
        date.show();
        cout << "\tTotal:" << Acount::gettotal() << "\tcommand>";
        int index, day;
        float amount,rate,credit,fee;
        Acount *account;
        string desc;
        char accname[10];
        cin >> cmd;
        switch (cmd)
        {
        case 'o':
            cin >> accname;
            cin >> rate;
            account=new Savingacc(date,accname,rate);
            acc.resize(acc.getSize() + 1);
            acc[acc.getSize() - 1] = account;
            //acc[accindex++]=sa1;
            break;
        case 'p':
            cin >> accname;
            cin >> rate>>credit>>fee;
            account=new Creditacc(date,accname,rate,credit,fee);
            acc.resize(acc.getSize() + 1);
            acc[acc.getSize() - 1] = account;
            break;
        case 'd':
            cin >> index >> amount;
            getline(cin, desc);
            acc[index]->deposit(date, amount, desc);
            break;
        case 'w':
            cin >> index >> amount;
            getline(cin, desc);
            acc[index]->withdraw(date, amount, desc);
            break;
        case 's':
            for (int i = 0; i < acc.getSize(); i++)
            {
                acc[i]->show();
            }
            break;
        case 'c':
            cin >> day;
            if(day<date.getday())
            {
                cout << "you cant set day backward" << endl;
            }
            else if(day>date.getmaxday())
            {
                cout << "out of range" << endl;
            }
            else
            {
                date.changeday(day);
            }
            date.show();
            break;
        case 'n'://next month 1th
            if(date.getmonth()==12)
            {
                date.changeyear(date.getyear() + 1);
                date.changemonth(1);
                date.changeday(1);
            }
            else
            {
                date.changemonth(date.getmonth()+1);
                date.changeday(1);
            }
            date.show();

            for (int i = 0; i < acc.getSize(); i++)
            {
                acc[i]->settle(date);
            }
            break;
        
        default:
            break;
        }
    } while (cmd != 'e');

    for (int i = 0; i < acc.getSize(); i++)
        {
            delete acc[i];
        }
    Acount::gettotal();
    return 0;
}