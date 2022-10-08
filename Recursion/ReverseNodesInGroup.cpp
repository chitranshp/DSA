//https://leetcode.com/problems/reverse-nodes-in-k-group/

class Solution {
public:
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head || !head->next)
            return head;
        
        ListNode* checknodesleft = head;
        for(int i = 0; i < k; i++)
        {
            if(!checknodesleft)
                return head;
            
            checknodesleft = checknodesleft->next;
        }   
            
        
        ListNode* prev = NULL, *curr = head, *nextnode;
        int count = 0;
        
        while(curr && count < k)
        {
            nextnode = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = nextnode;
            count++;
        }
        
        if(nextnode)
            head->next = reverseKGroup(nextnode, k);
        
        return prev;
    }
        
};