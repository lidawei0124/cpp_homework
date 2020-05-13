#include "savingacc.h"
#include "creditacc.h"
#include<vector>
#include<sstream>
#include<fstream>
float Acount::total = 0;
multimap<int, sav> Acount::bankrecordmap;

class Controller
{
    public:
        Date date;//日期
        vector<Acount*> acc;//账户
        bool endflag;//结束标志
        Controller(Date a,bool flag):date(a),endflag(flag)//构造函数
        {
            vector<Acount*> acc;
            cout << "(o)saving acc(p) credit acc(d) deposit (w)withdraw s(show) q(caxun) c(changeday) n(nextmonth) e(exit)" << endl;
        }
        void runline(string cmdline)//运行一行参数
        {
            istringstream str(cmdline);
            int index, day,y1,m1,d1,y2,m2,d2;
            float amount,rate,credit,fee;
            Acount *account;
            string desc;
            string accname;
            char cmd;
            str >> cmd;
            switch (cmd)
            {
            case 'o':
                str >> accname;
                str >> rate;
                account=new Savingacc(date,accname,rate);
                acc.push_back(account);
                break;
            case 'p':
                str >> accname;
                str >> rate>>credit>>fee;
                account=new Creditacc(date,accname,rate,credit,fee);
                acc.push_back(account);
                break;
            case 'd':
                str >> index >> amount;
                getline(str, desc);
                acc[index]->deposit(date, amount, desc);
                break;
            case 'w':
                str >> index >> amount;
                getline(str, desc);
                acc[index]->withdraw(date, amount, desc);
                break;
            case 's':
                for (int i = 0; i < acc.size(); i++)
                {
                    acc[i]->show();
                }
                break;
            case 'c':
                str >> day;
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
                str >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
                Acount::query(y1,m1,d1,y2,m2,d2);
                break;
            case 'e':
                endflag = true;
                cout << "over" << endl;
                break;
            default:
                break;
            }
            //显示日期和总金额
            date.show();
            cout << " Total:" << Acount::gettotal() <<"\t"<< "command:";
        }
};




int main()
{
    Date date(2008, 11, 1);
    Controller cmd(date, false);//新建一个控制器对象
    string cmdline;
    cout << "read? y/n/q:";
    char c;
    cin >> c;
    if(c=='y')
    {
        ifstream infile("save.txt");
        if(infile)
        {
            while(getline(infile,cmdline))
            {
                cmd.runline(cmdline);
            }
        }
        infile.close();
    }
    else if(c=='q')//清理文件
    {
        ofstream outfile;
        outfile.open("save.txt",ios_base::trunc);
        outfile.close();
    }
    cout << "read over" << endl;
    cout << "(o)saving acc(p) credit acc(d) deposit (w)withdraw s(show) q(caxun) c(changeday) n(nextmonth) e(exit)" << endl;
    ostringstream cmdbuf;//命令以字符串输出流缓存到buf中
    cmd.endflag = false;
    while(cmd.endflag==false&&getline(cin,cmdline))//遇到e以后 endflag 变为true 不满足条件跳出
    {

        cmdbuf << cmdline;//把命令缓存到buf中
        cmdbuf << endl;
        cmd.runline(cmdline);
    }
    cout << "save? y/n:";
    cin >> c;
    if(c=='y')
    {
        ofstream outfile;
        outfile.open("save.txt",ios_base::app);
        if(outfile)
        {
            string buf = cmdbuf.str();
            outfile << buf << endl;
        }
        outfile.close();
    }

    Acount::gettotal();
    for (int i = 0; i < cmd.acc.size(); i++)
    {
        delete cmd.acc[i];
    }
    return 0;
}