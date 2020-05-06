#include "savingacc.h"
#include "creditacc.h"

float Acount::total = 0;
int main()
{
    Date date(2008, 11, 1);
    Savingacc sa1(date, "sa1", 0.015);
    Savingacc sa2(date, "sa2", 0.015);
    Creditacc ca(date, "ca", 0.0005, 10000, 50);
    Acount *acc[] = {&sa1, &sa2, &ca};
    cout << "(d) deposit (w)withdraw s(show) c(changeday) n(nextmonth) e(exit)" << endl;
    char cmd;
    do
    {
        //显示日期和总金额
        date.show();
        cout << "\tTotal:" << Acount::gettotal() << "\tcommand>";
        int index, day;
        double amount;
        string desc;
        cin >> cmd;
        switch (cmd)
        {
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
            for(Acount* &a:acc)
            {
                a->show();
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

            for(Acount* &a:acc)
            {
                a->settle(date);
            }
            break;
        
        default:
            break;
        }
    } while (cmd != 'e');
    
    Acount::gettotal();
    return 0;
}