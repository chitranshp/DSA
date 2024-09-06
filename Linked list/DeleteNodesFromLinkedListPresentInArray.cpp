// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array

// TC - O(n + m) size of linked list + size of vector. 
// SC - O(m) for unordered set

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> valuesToDelete(nums.begin(), nums.end());

        ListNode* currNode = head;
        ListNode* prevNode = nullptr;

        while(currNode != nullptr)
        {
            if(valuesToDelete.find(currNode->val) != valuesToDelete.end() && prevNode == nullptr)
            {
                head = currNode->next;
            }
            else if(valuesToDelete.find(currNode->val) != valuesToDelete.end() && prevNode != nullptr)
            {
                prevNode->next = currNode->next;
            }
            else 
            {
                prevNode = currNode;
            }

            currNode = currNode->next;
        }

        return head;
    }
};
