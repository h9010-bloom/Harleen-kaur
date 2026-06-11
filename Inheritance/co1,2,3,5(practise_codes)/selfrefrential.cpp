#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next; // self-refrential pointer
};
int main()
{
    node *n1=new node{10, NULL};//creating three nodes
    node *n2=new node{20, NULL};
    node *n3=new node{30, NULL};

    n1->next = n2;//linking that three nodes
    n2->next = n3;
    n3->next = NULL;

    node *temp = n1;//traversing
    cout<<"Linked list: ";

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;//move to the next node
    }
    return 0;
}