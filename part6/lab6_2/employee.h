#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
struct info
{
    char* name;
    char* address;
    char* code;
    char* city;
};
class Employee
{
    public:
        Employee(char* a="",char* b="",char* c="",char* d="");
        void change_name(char* name);
        void display();
    private:
        info info1;
};
#endif