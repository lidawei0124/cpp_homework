#include <iostream>
#include <string>
using namespace std;
class Vehicle
{
    public:
        void run()
        {
            cout << "running " << endl;
        }
        void stop()
        {
            cout << "stop" << endl;
        }
        const int getmaxspeed()
        {
            return maxspeed;
        }
        const int getweight()
        {
            return weight;
        }
        Vehicle(int s=0,int w=0):maxspeed(s),weight(w)
        {
            
        }
    private:
        int maxspeed;
        int weight;
};

class Bicycle:virtual public Vehicle
{
    public:
        const int getheight()
        {
            return height;
        }
        Bicycle(int s, int w,int h) : Vehicle(s, w), height(h)
        {

        }

    private:
        int height;
};
class Motercar:virtual public Vehicle
{
    public:
        const int getseatnum()
        {
            return seatnum;
        }
        Motercar(int s,int w,int sn):Vehicle(s,w),seatnum(sn)
        {

        }
    private:
        int seatnum;
};
class Motercycle:public Motercar,public Bicycle
{
    public:
        Motercycle(int s,int w,int h,int sn):Motercar(s,w,sn),Bicycle(s,w,h),Vehicle(s,w)
        //要给最远基类传递参数Vehicle(s,w)，因为motercar和bicycle不能通过虚基类调用Vehicle构造函数，会被忽略
        {

        }
    private:

};
int main()
{
    Motercycle mc(100, 1000, 3, 4);
    mc.run();
    mc.stop();
    return 0;
}