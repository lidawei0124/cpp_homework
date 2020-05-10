#include "savingacc.h"
#include "creditacc.h"
#include<vector>

float Acount::total = 0;
multimap<int, sav> Acount::bankrecordmap;

int main()
{
    Date date(2008, 11, 1);
    Date date1, date2;
    cout << "(o)saving acc(p) credit acc(d) deposit (w)withdraw s(show) q(caxun) c(changeday) n(nextmonth) e(exit)" << endl;
    char cmd;
    vector<Acount*> acc;

    do
    {
        //显示日期和总金额
        date.show();
        cout << "\tTotal:" << Acount::gettotal() << "\tcommand>";
        int index, day;
        float amount,rate,credit,fee;
        Acount *account;
        string desc;
        string accname;
    
        cin >> cmd;
        switch (cmd)
        {
        case 'o':
            cin >> accname;
            cin >> rate;
            account=new Savingacc(date,accname,rate);
            acc.push_back(account);
            break;
        case 'p':
            cin >> accname;
            cin >> rate>>credit>>fee;
            account=new Creditacc(date,accname,rate,credit,fee);
            acc.push_back(account);
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
            for (int i = 0; i < acc.size(); i++)
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

            for (int i = 0; i < acc.size(); i++)
            {
                acc[i]->settle(date);
            }
            break;
        case 'q':
            date1.read();
            date2.read();
            Acount::query(date1, date2);
            break;
        default:
            break;
        }
    } while (cmd != 'e');

    for (int i = 0; i < acc.size(); i++)
        {
            delete acc[i];
        }
    Acount::gettotal();
    return 0;
}