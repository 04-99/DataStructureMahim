#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct Node{
    int x;
    struct Node* nxt;
}nodes;

nodes* head;

void Insertion(int n)
{
    nodes* tmp = (nodes*)malloc(sizeof(nodes));
    tmp->x = n;
    tmp->nxt = head;

    head = tmp;
}

void Print()
{
    nodes* tmp = head;
    cout << "List is: ";
    while(tmp != NULL)
    {
        cout << tmp->x << " ";
        tmp = tmp->nxt;
    }
    cout << endl;

}

void Delete(int n)
{
    nodes* tmp1 = head;
    
    if(n == 0 || n < 0){
        cout << "Wrong input" << endl;
    }
    
    if(n == 1)
    {
        head = tmp1->nxt;
        free(tmp1);
        return;
    }

    for(int i = 1; i <= n-2; ++i)
    {
        tmp1 = tmp1->nxt;
    }

    nodes* tmp2 = tmp1->nxt;
    tmp1->nxt = tmp2->nxt;
    free(tmp2);
}

int main()
{
    head = NULL;
    cout<< "How many numbers? ";
    int x, n, j, m, k, l = 0, a = 1;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cout << "Enter number: ";
        cin >> x;
        Insertion(x);
        Print();
    }



    while(a){

        cout << "Which operation do u wanna perform? ";
        cin >> m;
        switch(m){
        if(m < 5 && m >0){
        case 1:
            cout << "Which Box do you wanna empty? ";
            cin >> j;
            Delete(j);
            l++;
            break;
        case 2:
            cout << "Which value do you wanna put? ";
            cin >> k;
            Insertion(k);
            l--;
            break;
        case 3:
            /*for(int i = 0; i < n - l; ++i)
            {*/
                Print();
            /*}*/
            break;
        case 4:
            a = 0;
            break;
        }

        if(a == 0)
            break;

        }
    }
    return 0;
}
