#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int val;
        Node* next;
    
    Node(int val)               //Constructor
    {
        this->val = val;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int d) 
{
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}

void print(Node* head) {
    //base case
    if(head == NULL)
        return;

    cout << head->val<< ", ";

    print(head -> next);
}

void printkthnodefromend(struct Node * head, int &k)
{
    if(!head)
        return;

    printkthnodefromend(head->next, k);
    k--;

    if(k == 0)
        cout<<"Kth node from end:"<<head->val;
}

Node* reverseList(Node *head)
{
    if(!head || !head->next)
        return head;

    Node *newHead = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    Node* root = new Node(1);
    head = tail = root;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);

    print(head);
    cout << endl;

    int k = 3;
    printkthnodefromend(head, k);
    return 0;
}