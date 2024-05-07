// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/

/*
TC - O(N)
SC - O(N) Recursion stack
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
    void helper(ListNode* ptr, int& carry) {
        if(ptr == nullptr) {
            return;
        }

        helper(ptr->next, carry);
        int val = ptr->val * 2 + carry;
        ptr->val = val % 10;
        carry = val / 10;
        return;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = head;
        int carry = 0;
        helper(temp, carry);
        if(carry != 0) {
            ListNode* newHead = new ListNode(carry, head);\
            return newHead;
        }
        return head;
    }
};

/*
TC - O(n)
SC - O(n)
*/

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
       if(head->val > 4) {
        head = new ListNode(0, head);
       }

       for(ListNode* temp = head; temp != nullptr; temp = temp->next) {
        temp->val = (temp-> val * 2) % 10;
        if(temp->next != nullptr && temp->next->val > 4) {
            temp->val++;
        }
       }

        return head;

    }
};
