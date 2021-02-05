#include<stdio.h>
#include<iostream>

using namespace std;

void PrintSortedArray(int *a, int n)
{
    for(int k = 0; k < n; ++k){
        cout << a[k] << " ";
    }
}

MergeIt(int *a, int low, int mid, int high)
{
    int l = mid - low + 1;
    int h = high - mid ;

    int L[l + 1], R[h + 1];// why add 1 here not up there

    for(int i = 0; i < l; ++i)
    {
        L[i] = a[low + i];
    }

    for(int j = 0; j < h; ++j)
    {
        R[j] = a[mid+1 + j];
    }

    L[l] = 9999;
    R[h] = 10000;

    int i = 0, j = 0;

    for(int k = low; k < high+1; ++k)
    {
        if(L[i] < R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }
}

MergeSort(int *a, int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);

        MergeIt(a, low, mid, high);
    }
}

int main()
{
    int a[] = {2,4,1,3, 2000, 1000,5};
    int n = sizeof(a) / sizeof(a[0]);

    int low = 0;
    int high = n - 1;

    MergeSort(a, low, high);

    PrintSortedArray(a, n);

    return 0;

}
