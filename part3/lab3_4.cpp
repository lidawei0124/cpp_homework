#include<iostream>
#include<cmath>
using namespace std;

int fibonacci(int n)
{
    switch (n)
    {
    case 1:
    case 2:
        return 1;
        break;
    default:
        return fibonacci(n - 1) + fibonacci(n - 2);
        break;
    }
}

int main()
{
    int n;
    cout << "input n:" << endl;
    cin >> n;
    cout << fibonacci(n)<<endl;
    return 0;
}