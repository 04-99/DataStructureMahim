#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<cstdlib>

/*using std::cout;
using std::cin;
using std::endl;*/
using namespace std;

typedef struct Node{
    int x;
    struct Node* nxt;
}nodes;

nodes* head;
nodes* last;
int cnt;

bool isEmpty()
{
    if(head == NULL && last == NULL)
    {
        return true;
    }
    else
        return false;
}

int Size()
{
    return cnt;
}

void enqueue(int n)
{
    nodes* tmp = (nodes*)malloc(sizeof(nodes));/*right process*/

    tmp->x = n;
    tmp->nxt = NULL;

    if(isEmpty()){
        head = last = tmp;
        cnt++;
        return;
    }

    last->nxt = tmp;
    last = tmp;

    cnt++;
}

void deQueue()
{
    nodes* tmp = head;
    if(head == NULL){
        cnt--;
        return;
    }
    if(head == last){
        head = last = NULL;
    }
    else{
        head = head->nxt;
    }
    free(tmp);
    cnt--;
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

int main()
{
    head = NULL;
    last = NULL;
    cnt = 0;
    cout<< "How many numbers? ";
    int x2, n, j, k, l = 0, a = 1;
    char ch;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cout << "Enter number: ";
        cin >> x2;
        enqueue(x2);
        Print();
    }

    while(a){
        cout << "Which operation do u wanna perform? ";
        cin >> ch;
        switch(ch){
        case 'd':
            deQueue();
            break;
        case 'e':
            cout << "Which value do you wanna put? ";
            cin >> k;
            enqueue(k);
            l--;
            break;
        case 'P':
            Print();
            break;
        case 'B':
            a = 0;
            break;
        case 'S':
            cout<< "Size is: " << Size() << endl;
            break;
        case 'E':
            if(isEmpty()){
                cout << "Stack is Empty" << endl;
            }
            else
                cout << "Not Empty" << endl;
            break;
        }
        if(a == 0)
            break;
    }
    return 0;
}

