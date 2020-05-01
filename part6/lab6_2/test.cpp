#include "employee.h"

int main()
{
    Employee e1("linda", "1120", "beijing", "block4");
    Employee e2(e1);
    e2.change_name("david");
    e1.display();
    e2.display();
    return 0;
}