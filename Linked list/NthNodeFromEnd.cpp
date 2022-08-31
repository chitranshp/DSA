//https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1?page=1&sortBy=submissions

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);


int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}


int getNthFromLast(Node *head, int n)
{
       struct Node *slow = head, *fast = head;
       if(head == NULL)
           return -1;
       while(--n > 0 && fast != NULL)
       {
           fast = fast->next;
       }
       
       if(fast == NULL)
           return -1;
        
       while(fast->next != NULL)
       {
           slow = slow->next;
           fast = fast->next;
       }
       return slow->data;
}


