#include<iostream>
#include"client.h"
using namespace std;

int Client::ClientNum = 0;
char Client::ServerName = 'a';

int main()
{
    Client c1;
    c1.ChangeServerName('b');
    cout << c1.getClientNum() << endl;
    return 0;
}
