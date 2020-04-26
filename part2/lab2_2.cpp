#include<iostream>
using namespace std;

int main()
{
	int sum = 0, i = 1;
	for (i = 1; i <= 10; i++)
	{
		sum += i;
	}

	cout << "sum of 1-10 is :" << sum << endl;
	return 0;
}