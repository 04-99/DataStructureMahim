#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<cstdlib>

using namespace std;

typedef struct Node{
    int x;
    struct Node* nxt;
}nodes;

nodes* head;
int cnt;

bool isEmpty()
{
    if(head == NULL)
    {
        return true;
    }
    else
        return false;
}

void push(int n)
{
    nodes* tmp = (nodes*)malloc(sizeof(nodes));
    tmp->x = n;
    tmp->nxt = head;
    head = tmp;
    cnt++;
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

void pop()
{
    nodes* tmp;
    if(isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    tmp = head;
    head = tmp->nxt;
    free(tmp);
    cnt--;
}

int Size()
{
    return cnt;
}

int main()
{
    cnt = 0;
    head = NULL;
    cout<< "How many numbers? ";
    int x2, n, j, k, l = 0, a = 1;
    char ch;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cout << "Enter number: ";
        cin >> x2;
        push(x2);
        Print();
    }

    while(a){

        cout << "Which operation do u wanna perform? ";
        cin >> ch;
        switch(ch){
        case 't':
            cout << "Which value do you wanna put? ";
            cin >> k;
            push(k);
            l--;
            break;
        case 'p':
            pop();
            break;
        case 'P':
            Print();
            break;
        case 'B':
            a = 0;
            break;
        case 'E':
            if(isEmpty()){
                cout << "Stack is Empty" << endl;
            }
            else
                cout << "Not Empty" << endl;
            break;
        case 'S':
            cout<< "Size is: " << Size() << endl;
            break;// if break isn't given don't worry It's default in case of last "case"....
        }

        if(a == 0)
            break;
    }
    return 0;
}

