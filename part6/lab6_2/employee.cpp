#include "employee.h"
#include<iostream>
using namespace std;

Employee::Employee(char* a,char* b,char* c,char* d)
{
    info1.name = a;
    info1.code = b;
    info1.city = c;
    info1.address = d;
}
void Employee::change_name(char* name)
{
    info1.name = name;
}
void Employee::display()
{
    cout << info1.name << "::" << info1.code << "::" << info1.city << "::" << info1.address << endl;
}