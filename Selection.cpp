#include<stdio.h>
#include<iostream>

using namespace std;

void PrintSortedArray(int *a, int n)
{
    for(int k = 0; k < n; ++k){
        cout << a[k] << " ";
    }
}

int findingMin(int *a, int n, int k)
{
    int Min = a[k];
    int loc = k;

    for(int i = k; i < n; ++i)
    {
        if(Min > a[i])
        {
            Min = a[i];
            loc = i;
        }
    }

    return loc;
}

void Swappin(int *a, int n)
{
    int k, loc;
    int temp;


    for(k = 0; k < n - 1; ++k)
    {
        int loc = findingMin(a, n , k);
        temp = a[k];
        a[k] = a[loc];
        a[loc] = temp;
    }
}


/*void SelectionSort()
{

}*/

int main()
{
    int a[] = {2,4,1,5,7,3};

    int n = sizeof(a) / sizeof(a[0]);

    Swappin(a, n);
    PrintSortedArray(a, n);

    return 0;
}

