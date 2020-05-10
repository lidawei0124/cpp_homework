#include "sum.h"

void Sum::change(Date day, float v)
{
    sum += value * (day - lastday);//计算累计
    value = v;//更新v
    lastday = day;
}
void Sum::reset(Date day, float v)//结算以后
{
    sum = 0;
    value = v;
    lastday = day;
}
const float Sum::getsum(Date day)
{
    sum += value * (day - lastday);
    lastday = day;
    return sum;
}
