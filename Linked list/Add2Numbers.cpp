//https://leetcode.com/problems/add-two-numbers-ii/

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
        int m = 0, n = 0;
        stack<int> s1;
        stack<int> s2;
        stack<int> s3;
        
        while(l1 != NULL)
        {
            s1.push(l1->val);
            l1 = l1->next;
            m++;
        }
        
        while(l2 != NULL)
        {
            s2.push(l2->val);
            l2 = l2->next;
            n++;
        }
        
        int first = 0, second = 0, carry = 0, currsum = 0;
        while(!s1.empty() || !s2.empty() || carry == 1)
        {
            if(!s1.empty())
            {
                first = s1.top();
                s1.pop();
            }
            else
                first = 0;
            
            
            if(!s2.empty())
            {
                second = s2.top();
                s2.pop();
            }
            else
                second = 0;
            
            currsum = first + second + carry;
            carry = currsum / 10;
            currsum = currsum % 10;
            s3.push(currsum);
            //cout<<currsum;
        }
        
        
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        while(!s3.empty())
        {
            ListNode* newNode = new ListNode(s3.top());
            s3.pop();
            temp->next = newNode;
            temp = temp->next;
        }
        
        
        return dummy->next;
            
            
    }
};