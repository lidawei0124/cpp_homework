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

class RAM
{
    public:
        RAM(int r)
        {
            ram = r;
            cout << "RAM install" << endl;
        }
       
        void run()
        {
            cout << "RAM runing at:" <<ram<<"GB"<< endl;
        }
        void stop()
        {
            cout << "RAM sotp" << endl;
        }
    private:
        int ram;
};

class CDROM
{
    public:
        CDROM(bool flag)
        {
            cdrom = flag;
            if(cdrom)
            {
                cout << "1 CDROM install" << endl;
            }
            else
            {
                cout << "0 CDROM install" << endl;
            }
        }
        
        void run()
        {
            if(cdrom)
            {
                cout << "1 CDROM running" << endl;
            }
            else
            {
                cout << "0 CDROM runing" << endl;
            }
        }
        void stop()
        {
            if(cdrom)
            {
                cout << "1 CDROM stop" << endl;
            }
            else
            {
                cout << "0 CDROM stop" << endl;
            }
        }
    private:
        bool cdrom;
};

class COMPUTER
{
    public:
        COMPUTER(CPU c, RAM r, CDROM cd);
        ~COMPUTER()
        {
            cout << "PC unstall" << endl;
        }
        void run()
        {
            cout << "power on" << endl;
            cpu.run();
            ram.run();
            cdrom.run();
            cout << "PC is running" << endl;
        }
        void stop()
        {
            cout << "power off" << endl;
            cpu.stop();
            ram.stop();
            cdrom.stop();
            cout << "PC stop" << endl;
        }
    private:
        CPU cpu;
        RAM ram;
        CDROM cdrom;
};
COMPUTER::COMPUTER(CPU c, RAM r, CDROM cd):cpu(c),ram(r),cdrom(cd)
{
    cout << "pc install" << endl;
}

int main()
{
    CPU cpu(p7, 4000, 1.36);
    RAM ram(16);
    CDROM cdrom(1);
    COMPUTER pc(cpu, ram, cdrom);
    pc.run();
    pc.stop();
    return 0;
}