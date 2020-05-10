#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main()
{
    deque<int> namebookA,namebookB;
    for (int i = 0; i < 5;i++)
    {
        int name;
        cin >> name;
        namebookA.push_back(name);
    }
    cout << "num book A:" << endl;
    for (int i = 0; i < namebookA.size();i++)
    {
        cout << namebookA.at(i);
        cout << " ";
    }
    cout << endl;
    for (int i = 0;i < 5;i++)
    {
        int name;
        cin >> name;
        namebookB.push_back(name);
    }
     cout << "num book B:" << endl;
    for (int i = 0; i < namebookB.size();i++)
    {
        cout << namebookB.at(i);
        cout << " ";
    }
    cout << endl;
    for (int i = 0; i < namebookB.size();i++)
    {
        namebookA.push_front(namebookB.at(i));
    }

    for (int i = 0; i < namebookA.size();i++)
    {
        cout << namebookA.at(i);
        cout << " ";
    }
    cout << endl;

    return 0;
}