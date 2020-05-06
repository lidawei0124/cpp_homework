#include <iostream>
#include <string>
using namespace std;
class Vehicle
{
    public:
        virtual void run()
        {
            cout << "Vehicle running " << endl;
        }
        virtual void stop()
        {
            cout << "Vehicle stop " << endl;
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
        virtual void run()
        {
            cout << "Bicycle running " << endl;
        }
        virtual void stop()
        {
            cout << "Bicycle stop" << endl;
        }
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
        virtual void run()
        {
            cout << "Motercar running " << endl;
        }
        virtual void stop()
        {
            cout << "Mortercar stop" << endl;
        }
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
        virtual void run()
        {
            cout << "Motercycle running " << endl;
        }
        virtual void stop()
        {
            cout << "Motercycle stop" << endl;
        }
        Motercycle(int s,int w,int h,int sn):Motercar(s,w,sn),Bicycle(s,w,h),Vehicle(s,w)
        //要给最远基类传递参数Vehicle(s,w)，因为motercar和bicycle不能通过虚基类调用Vehicle构造函数，会被忽略
        {

        }
    private:

};
int main()
{
    Motercycle mc(100, 1000, 3, 4);
    Bicycle bc(100, 1000, 2);
    bc.run();
    bc.stop();
    mc.run();
    mc.stop();
    return 0;
}