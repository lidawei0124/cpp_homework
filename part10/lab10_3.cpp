#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
int main()
{
    vector<int> a(10);
    int x;
    for (int i = 0; i < 10;i++)
    {
        cin >>a[i];
    }
    for (int i = 0; i < 10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout << endl;
    cout << "input find x:";
    cin >> x;
    auto iter = find(a.begin(), a.end(), x);
    if(iter!=a.end())
        cout << "found" << endl;
    else
        cout << "none" << endl;
    sort(a.begin(), a.end());
    for (int i = 0; i < 10;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}