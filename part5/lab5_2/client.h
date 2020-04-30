#ifndef CLIENT_H_
#define CLIENT_H_
#include<iostream>
using namespace std;

class CLIENT
{
        static int num;
        static char servername;
    public:
        static void name(char n);
        static int getnum();
};

#endif