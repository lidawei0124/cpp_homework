#include "acount.h"

int main()
{
    Acount sa0("2131",0.015);
    Acount sa1("1111",0.015);
    sa0.deposit(5, 5000);
    sa1.deposit(25, 10000);
    sa0.deposit(45, 5500);
    sa1.withdraw(60, 4000);
    sa0.settle(90);
    sa1.settle(90);
    sa0.show();
    sa1.show();
    return 0;
}