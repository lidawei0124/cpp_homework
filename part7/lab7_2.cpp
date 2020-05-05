#include <iostream>
#include <string>
using namespace std;

class Animal
{
    public:
        int age;
        const int getage()
        {
            return age;
        }
    private:
        //int age;
};
class Dog:public Animal
{
    public:
        void setage(int n)
        {
            age = n;
        }
    private:
};

int main()
{
    Dog dog;
    dog.setage(1);
    cout << dog.getage() << endl;
    return 0;
}