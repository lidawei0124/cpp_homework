#include"client.h"

void CLIENT::name(char n)
{
    CLIENT::servername = n;
    CLIENT::num++;
}

int CLIENT::getnum()
{
    return CLIENT::num;
}