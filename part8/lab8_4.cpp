#include<iostream>
using namespace std;
struct info
{
    char* name;
    int id;
    char* city;
};
class People
{
    public:
        People(char* name="",int id=0,char* city="")
        {
            info1.name = name;
            info1.id = id;
            info1.city = city;
        }
        void display()
        {
            cout << info1.name << "  " << info1.id << "  " << info1.city << endl;
        }
        bool operator ==(const People &a)
        {
            return a.info1.id == this->info1.id;
        }
        void operator =(const People &a)
        {
            this->info1 = a.info1;
        }
    private:
        info info1;
};

int main()
{
    People e1("linda",12, "beijing");
    People e3("dave",11, "beijing");
    People e2 = e1;
    cout << (e1 == e2) << endl;
    cout << (e1 == e3) << endl;
    e1.display();
    e2.display();
    e3.display();
    return 0;
}