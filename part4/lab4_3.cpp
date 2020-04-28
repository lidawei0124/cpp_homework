#include<iostream>
#include<string>
using namespace std;

class DATE
{
    public:
        DATE(int y,int m,int d)
        {
            year = y;
            month = m;
            day = d;
        }
        DATE()
        {
            year = 0;
            month = 0;
            day = 0;
        }
        DATE(const DATE &d)
        {
            year = d.year;
            month = d.month;
            day=d.day;
        }
        void show()
        {
            cout<<year<<"/"<<month<<"/"<<day;
        }
    private:
        int year;
        int month;
        int day;
};
class PEOPLE
{
    public:
        PEOPLE(int n):birthday(0,0,0)
        {
            number = n;
            sex = 0;
            id = "";
        }
        PEOPLE(const PEOPLE &p):birthday(p.birthday)
        {
            number = p.number;
            sex = p.sex;
            id = p.id;
        }
        void out()
        {
            cout << "[" << number << "]";
        }
        void info()
        {
            int y, m, d;
            cout << "input info of ";
            out();
            cout<<": " << endl;
            cout<< "input sex: male(0),female(1):" << endl;
            cin >> sex;
            cout << "input year month day (birthday):" << endl;
            cin >> y >> m>> d;
            DATE date(y, m, d);
            birthday=date;
            cout << "input id" << endl;
            cin >> id;
        }
        void show()
        {
            cout << "number:" << number << endl;
            cout << "sex: male(0),female(1):" << sex << endl;
            cout << "birthday:";
            birthday.show();
            cout << endl;
            cout << "id:" << id << endl;
        }
    private:
        int number;
        bool sex;
        DATE birthday;
        string id;
};

class GROUP
{
    public:
        GROUP(PEOPLE pp1,PEOPLE pp2):p1(pp1),p2(pp2)
        {
            cout << "your group hired 4 people:" << endl;
            p1.out();
            p2.out();
            cout << endl;
        }
        void info()
        {
            cout << "input your group members info:" << endl;
            p1.info();
            p2.info();
        }
        void show()
        {
            cout << "your group members info:" << endl;
            p1.show();
            p2.show();
        }
    private:
        PEOPLE p1;
        PEOPLE p2;
};

int main()
{
    PEOPLE p1(113), p2(116), p3(4), p4(999);
    GROUP workgroup(p1, p2);
    workgroup.info();
    workgroup.show();
    GROUP g1(workgroup);
    g1.show();
    p3.info();
    p4.info();
    GROUP g2(p3, p4);
    g2.show();
    return 0;
}