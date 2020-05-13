#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;
class CException
{
    public:
        void reason()
        {
            cout << "Error type:CException" << endl;
        }
};
void fun1()
{
    throw CException();
}
int main()
{
    try
    {
        fun1();
    }
    catch(CException &e)
    {
        e.reason();
    }
    
    return 0;
}