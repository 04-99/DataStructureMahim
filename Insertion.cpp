#include<stdio.h>
#include<iostream>

using namespace std;

void PrintSortedArray(int *a, int n)
{
    for(int k = 0; k < n; ++k){
        cout << a[k] << " ";
    }
}

void InsertionSort(int *a, int n)
{
    int i, j, temp;
    for(i = 1; i < n; ++i)
    {
        temp = a[i];
        for(j = i - 1; j >= 0; --j)
        {
            if(a[j+1] < a[j]){
                a[j+1] = a[j];
            }
            else
                break;

            a[j] = temp;
        }
        //a[j] = temp;
    }
}

int main()
{
    int a[] = {2,4,1,5,7,3};

    int n = sizeof(a) / sizeof(a[0]);

    InsertionSort(a, n);

    /*for(int k = 0; k < n; ++k){
        cout << a[k] << " ";
    }*/

    PrintSortedArray(a, n);

    return 0;
}
