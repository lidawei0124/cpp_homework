#ifndef ERROR_H_
#define ERROR_H_
#include<stdexcept>
#include "acount.h"
#include<string>
using namespace std;

class Accexcept:public runtime_error
{
    private:
        Acount* acc;
    public:
        Accexcept(Acount* a, string txt) :runtime_error(txt), acc(a){};
        Acount* getacc()
        {
            return acc;
        }
};
#endif