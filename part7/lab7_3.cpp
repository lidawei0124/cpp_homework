#include <iostream>
#include <string>
using namespace std;

class Baseclass
{
    public:
        const int getnumber()
        {
            return num;
        }
        Baseclass(int n=0):num(n)
        {
            cout << "baseclass created" << endl;
        }
        Baseclass(Baseclass &a)
        {
            num = a.getnumber();
            cout << "baseclass copyed" << endl;
        }
        ~Baseclass()
        {
            cout << "baseclass uncreated" << endl;
        }
        
    private:
        int num;
};
class Derivedclass:public Baseclass
{
    public:
        Derivedclass(int n):Baseclass(n)
        {
            cout << "derivedclass created" << endl;
        }
        Derivedclass(Derivedclass &a):Baseclass(a)
        {
            cout << "derivedclass copyed" << endl;
        }
        ~Derivedclass()
        {
            cout << "derivedclass uncreated" << endl;
        }
    private:
};

int main()
{
    Derivedclass dc(5);
    cout << dc.getnumber() << endl;
    Derivedclass dd(dc);
    cout << dd.getnumber() << endl;
    return 0;
}