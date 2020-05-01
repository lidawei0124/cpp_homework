#include "reshape.h"
#include "show.h"

int main()
{
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    show(a);
    reshape(a);
    show(a);
    return 0;
}