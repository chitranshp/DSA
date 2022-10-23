//https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

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
    ListNode* deleteMiddle(ListNode* head) 
    {
        ListNode *slow = new ListNode(0, head);
        ListNode *fast = head;
        ListNode *temp;
        
        if(!head)
            return nullptr;
        
        if(!head->next)
        {
            delete head;
            return nullptr;
        }  
            
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        temp = slow->next->next;
        delete slow->next;
        slow->next = temp;
        
        return head;
    }
};
