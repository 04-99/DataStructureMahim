#include<stdio.h>
#include<iostream>

using namespace std;

int a[] = {28, 79, 71, 21, 71, 18, 34};

void PrintSortedArray(/*int *a,*/ int n)
{
    for(int k = 0; k < n; ++k){
        cout << a[k] << " ";
    }
}

/*void Swapin(int lo, int hi)
{
    int temp =lo;
    lo = hi;
    hi = temp;

}*/


void QuickSort(/*int *a,*/ int low, int high)
{


    int temp;

    if(low < high)
    {
        int l = low + 1;
        int h = high;


        while(a[l] < a[low])
        {
            l++;
        }
        while(a[h] > a[low])
        {
            h--;
        }
        while(l<h){
            temp = a[l];
            a[l] = a[h];
            a[h] = temp;
            //Swapin(a[l], a[h]);
            while(a[l] < a[low])
            {
                l++;
            }
            while(a[h] > a[low])
            {
                h--;
            }
        }
        temp = a[low];
        a[low] = a[h];
        a[h] = temp;
        //Swapin(a[low], a[h]);

        QuickSort(/*a,*/ low, h-1);
        QuickSort(/*a,*/ h+1, high);
    }

}


int main()
{


    int n = sizeof(a) / sizeof(a[0]);
    int low = 0;
    int high = n-1;

    QuickSort(/*a,*/ low, high);
    PrintSortedArray(/*a,*/ n);

    return 0;

}
