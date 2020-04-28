#include<iostream>
using namespace std;

enum CPU_rank
{
    p1 = 1,
    p2,
    p3,
    p4,
    p5,
    p6,
    p7
};

class CPU
{
    private:
        CPU_rank rank;
        int frequency;
        float voltage;
    public:
        CPU(CPU_rank r,int f,float v)//构造函数
        {
            rank = r;
            frequency = f;
            voltage = v;
            cout << "CPU installed" << endl;
        }
        CPU():rank(p1),frequency(1000),voltage(1.2)//默认构造函数，初始化列表
        {
            cout << "CPU installed" << endl;
        }
        ~CPU()
        {
            cout << "cpu unstalled" << endl;
        }
        void run()
        {
            cout << "cpu runing at" << endl;
            cout << "rank :" << rank;
            cout << "  frequency：" << frequency<<"MHz";
            cout << "  voltage:" << voltage <<"V"<< endl;
        }
        void stop()
        {
            cout << "cpu sotp" << endl;
        }
};

int main()
{
    CPU cpu1(p7, 4000, 1.36);
    cpu1.run();
    cpu1.stop();
    CPU cpu2;
    cpu2.run();
    cpu2.stop();
    return 0;
}