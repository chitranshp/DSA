// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

/*
TC - O(n)
SC - O(1)
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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode *fast = new ListNode(-1, head), *slow = head;
        ListNode *fromBeg = head;

        for(int i = 0; i < k; i++)
            fast = fast->next;

        fromBeg = fast;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        swap(slow->val, fromBeg->val);

        return head;
    }
};