// https://leetcode.com/problems/partition-list/description/\

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        ListNode* left = new ListNode(-1), *right = new ListNode(-1);
        ListNode* leftTail = left, *rightTail = right;

        while(temp != nullptr)
        {
            if(temp->val < x)
            {
                // -1 -> next : temp
                leftTail->next = temp;

                // -1 = -1 -> next = temp
                leftTail = leftTail->next;
            }
            else
            {
                rightTail->next = temp;
                rightTail = rightTail->next;
            }

            temp = temp->next;
        }

        // Connecting tail of left with front of right which is right->next. As we use -1 as dummy node
        // If no such element exists which is greater or equal to x. Right will be empty. In that case, right->next will be nullptr
        // If left is empty. leftTail will be equal to left. And leftTail->next = right->next will basically store righthead in left->next(The actual head of modified list) 
        leftTail->next = right->next;

        //Making sure that list is null terminated
        rightTail->next = nullptr;

        return left->next;
    }
};