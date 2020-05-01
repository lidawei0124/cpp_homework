#include "reshape.h"

void reshape(int (*a)[3])
{
    int tem;
    for (int i = 0; i < 3;i++)
    {
        for (int j = 0; j < 3;j++)
        {
            if(i>j)
            {
                tem = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = tem;
            }
        }
    }
}