#include "client.h"

int CLIENT::num=0; //类内static 变量调用要加 类名：：变量 调用
char CLIENT::servername = 'a';
int main()
{
    CLIENT p1;
    p1.name('b');
    cout << p1.getnum() << endl;
    // CLIENT p2(p1);
    // CLIENT::changeservername;
    return 0;
}
