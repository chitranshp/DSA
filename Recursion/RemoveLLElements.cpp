// https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode *temp = head;
        
        if(temp == nullptr)
            return nullptr;
        
        //Check for all the node's to the right of the current node
        temp->next = removeElements(temp->next, val);
        //For the current node
        return (temp->val == val)? temp->next:temp;
    }
};


/*
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode *temp = head;
        
        if(temp == nullptr)
            return nullptr;
        
        if(temp->val == val)
        {
            temp = temp->next;
            temp = removeElements(temp, val);
        }
        else
        {
            temp->next = removeElements(temp->next, val);
        }
          
        return temp;
            
    }
};
*/
