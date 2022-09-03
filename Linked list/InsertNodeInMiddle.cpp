//https://practice.geeksforgeeks.org/problems/insert-in-middle-of-linked-list/1?page=2&category[]=Linked%20List&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    struct Node *next;
    
    Node(int x) 
    {
        data = x;
        next = NULL;
    }
};

void display(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout<<endl;
}

//Function to insert a node in the middle of the linked list.
Node* insertInMiddle(Node* head, int x)
{
	// Code here
	struct Node *mid = new Node(x);
	struct Node *slow = head, *fast = head;
	
	if(!head)
	    return mid;
	
	while(fast->next && fast->next->next)
	{
	        fast = fast->next->next;
	        slow = slow->next;
	}
	
	mid->next = slow->next;
	slow->next = mid;
	return head;
	
}

int main()
{
    int T, n, x;
    cin>>T;
    while(T--)
    {
        cin>> n >> x;
        
        struct Node *head = new Node(x);
        struct Node *tail = head;
        
        for (int i=0; i<n-1; i++)
        {
            cin>>x;
            tail->next = new Node(x);
            tail = tail->next;
        }
        
        cin>> x;
        head = insertInMiddle(head, x);
        display(head);
    }
    return 0;
}

/* Sample Input
5
242 748 114 441 751
909
*/