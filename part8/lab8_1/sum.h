#ifndef SUM_H_
#define SUM_H_
#include "date.h"
//计算余额/负债*天数的累加值，可进一步用于计算利息
class Sum
{
    public:
        Sum(Date day, float v) : lastday(day), value(v) { sum = 0; };//构造函数
        void change(Date day, float v);
        void reset(Date day, float v);//结算以后
        const float getsum(Date day);
    private:
        Date lastday;
        float value;//余额或负债
        float sum;
};

#endif