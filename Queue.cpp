#include<stdio.h>
#include<iostream>

using namespace std;
int arr[10];
int tp;

bool isEmpty()
{
    if(tp == -1)
    {
        return true;
    }
    else
        return false;
}

void EnQueue(int mxSTK, int item)
{
    if(tp == mxSTK)
        cout << "Overflow" << endl;
    else
    {
        tp++;
        arr[tp] = item;
    }
}

int size_F()
{
    return (tp+1);
}

int deQueue()
{
    int tmp;
    tmp = arr[0];

    for(int i = 0; i < tp; ++i)
    {
        arr[i] = arr[i+1];
    }
    tp--;
    return tmp;
}

int main()
{
    int i, n, item;
    n = sizeof(arr)/sizeof(arr[0]);
    tp = -1;

    for(i = 0; i < n; ++i)
    {
        cin >> item;
        EnQueue(n,item);
    }

    for(i = 0; i < n; ++i)
    {
        cout << deQueue() << " ";
        //cout << "Size of: " << size_F() << endl;
    }

    cout << "Size of: " << size_F() << endl;

    return 0;
}

