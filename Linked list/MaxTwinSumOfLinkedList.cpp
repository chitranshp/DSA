// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

/*
Approach 1:
We will store all the elments of linked list in a stack one by one and in the same loop we will calculate
the length of linked list in a variable say 'n'.

Now using 'n', we will utilize two pointers one pointing to the first element of LL and another one pointing to the 
last element of LL(We will use stack to get the 2nd pointer).
For each pair, we will get the sum and compare it with max value obtained so far. We will do this process untill we have 
processed n/2 elements as we know that 'n' is even.

We kind of used Stack to simulate recursion and the problem could also been solved using that.
TC - O(n)
SC - O(n) for stack. 

Note: We don't need to store the entire linked list node in stack. We can just store the value and pop the stack to go to the previous element.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode *temp1 = head;
        int n = 0, maxval = 0;

        while(temp1 != nullptr)
        {
            st.push(temp1->val);
            temp1 = temp1->next;
            n++;
        }

        temp1 = head;

        for(int i = 0; i < n/2; i++)
        {
            int val = st.top();
            st.pop();
            maxval = max(maxval, temp1->val + val);
            temp1 = temp1->next;
        }

        return maxval;
    }
};

/*
Approach 2:
Instead of using stack, we can first find the middle node of linked list using tortoise and hare method. This will take n/2 iterations.
Then, we can reverse the linkedlist after the middle node till end of the linked list using iterative procedure to save stack space.

Then we can calculate the sum for each pair in a single for loop.
TC - O(n)
SC - O(1) as we are using iterative method to reverse the Linked List.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode *slow = new ListNode(-1, head), *fast = new ListNode(-1, head);

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast->next != nullptr)
                fast = fast->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head) 
    {
        ListNode *prev = nullptr, *curr = head, *nextnode = head;

        while(curr != nullptr) 
        {
            nextnode = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nextnode;
        }

        return prev;
    }

    int pairSum(ListNode* head) 
    {
       int maxval = 0;
       ListNode *node = head;
       ListNode *mid = middleNode(head);
       mid->next = reverseList(mid->next);
       mid = mid->next;

       while(mid != nullptr)
       {
           maxval = max(maxval, mid->val + node->val);
           mid = mid->next;
           node = node->next;
       }

       return maxval;
    }
};

