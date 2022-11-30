// https://leetcode.com/chitranshp/

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
    ListNode* swapPairs(ListNode* head) 
    {
        /*
        if(!head || !head->next)
            return head;

        ListNode *nextPair = new ListNode();
        ListNode *newhead = new ListNode();
        nextPair = head->next->next;
        newhead = head->next;

        head->next->next = head;
        head->next = swapPairs(nextPair);
        
        return newhead;
        */

        ListNode *curr = head, *prev = new ListNode(-1), *newhead = new ListNode();
        newhead = head;

        if(head && head->next)
            newhead = head->next;

        while(curr && curr->next)
        {
            prev->next = curr->next;
            curr->next = curr->next->next;

            prev = prev->next;
            prev->next = curr;
            curr = curr->next;
            prev = prev->next;
        }

        return newhead;
        
    }
};
