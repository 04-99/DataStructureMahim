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

void push(int mxSTK, int item)
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

int pop(int *arr)
{
    int item;
    if(isEmpty())
    {
        cout << "Underflow" << endl;
    }
    else{
        item = arr[tp];
        tp--;
        return item;
    }
}

int main()
{
    int i, n, item;
    n = sizeof(arr)/sizeof(arr[0]);
    tp = -1;

    for(i = 0; i < n; ++i)
    {
        cin >> item;
        push(n,item);
    }

    for(i = 0;i < n; ++i)
    {
        cout << pop(arr) << " ";
        //cout << "Size of: " << size_F() << endl;
    }

    cout << "Size of: " << size_F() << endl;

    return 0;
}

