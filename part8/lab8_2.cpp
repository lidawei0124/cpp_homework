#include<iostream>
using namespace std;

class Point
{
    public:
        friend ostream &operator<<(ostream &out, const Point &b);
        Point(int x, int y) : _x(x), _y(y){};
        Point& operator ++()//++A
        {
            this->_x++;
            this->_y++;
            return *this;
        }
        Point operator ++(int)//A++
        {
            Point old = *this;
            ++(*this);
            return old;
        }
        Point& operator --()//--A
        {
            this->_x--;
            this->_y--;
            return *this;
        }
        Point operator --(int)//A++
        {
            Point old = *this;
            --(*this);
            return old;
        }
        
    private:
        int _x;
        int _y;
};
ostream& operator << (ostream& out,const Point &b)//重载
{
    out << "(" << b._x << "," << b._y << ")" << endl;
}
int main()
{
    Point A(10, 9);
    cout << A;
    cout << A++;
    cout << ++A;
    cout << A--;
    cout << --A;
    return 0;
}