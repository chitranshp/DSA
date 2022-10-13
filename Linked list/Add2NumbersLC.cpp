//https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry = 0;
        ListNode *l3 = new ListNode(), *temp;
        temp = l3;
        
        while(l1 || l2 || carry)
        {
            int first = 0;
            int second = 0;
            
            if(l1)
            {
                first = l1->val;
                l1 = l1->next;
            }
                
            
            if(l2)
            {
                second = l2->val;
                l2 = l2->next;
            }
                
            
            temp->next = new ListNode((first + second + carry) % 10);
            temp = temp->next;
            carry = (first + second + carry)/ 10; 
            
        }
        
        return l3->next;
    }
};