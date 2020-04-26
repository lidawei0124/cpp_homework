#include<iostream>
using namespace std;
int main()
{
	int sum = 0, i = 1;
	do
	{
		cout << i << endl;
		sum += i;
		i++;
	} while (i <= 10);
	cout << "sum of 1-10 is :" << sum << endl;
	return 0;
}