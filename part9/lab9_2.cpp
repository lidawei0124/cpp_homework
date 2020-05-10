#include <iostream>
using namespace std;
#include "node.h"

int main()
{
    int a[10];
    Node<int> n[10];
    cout << "input 10 num:" << endl;
    for (int i = 0; i < 10;i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 9;i++)
    {
        n[i].data=a[i];
        n[i].insertAfter(&n[i + 1]);
    }
    n[9].data = a[9];
    Node<int> *np = &n[0];
    while(np!=NULL)
    {
        cout << np->data << " ";
        np = np->nextNode();
    }
    cout << endl;
    int f;
    cout << "input deletnum x:";
    cin >> f;
    while(np!=NULL)
    {
        if(f==np->data)
        {
            np->deleteAfter();
        }
        np = np->nextNode();
    }
    cout << "result:";
    while(np!=NULL)
    {
        cout << np->data << " ";
        np = np->nextNode();
    }

}
