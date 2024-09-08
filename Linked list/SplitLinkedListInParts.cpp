// https://leetcode.com/problems/split-linked-list-in-parts/
// TC - O(n) & SC - O(n)

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode *curr = head;

        // Calculates length of list
        while(curr != nullptr)
        {
            curr = curr->next;
            len++;
        }

        int sizeOfPart = len / k;       // minimum part size
        int extraNodes = len % k;              // extra nodes

        vector<ListNode*> parts(k, nullptr);      // Fills nullptr as default for all places

        int partIndex = 0;
        curr = head;

        // We will traverse all nodes in list only. Remaining empty places are already inserted with nullptr as part of initialization
        while(curr != nullptr)
        {
            ListNode* prev = nullptr;;
            parts[partIndex++] = curr;

            // Insert one extra node per new part. This ensures max difference between any two parts will be 1.
            int currentPartSize = sizeOfPart + ((extraNodes-- > 0) ? 1 : 0);

            for(int i = 0; i < currentPartSize; i++)
            {
                    prev = curr;
                    curr = curr->next;
            }

            prev->next = nullptr;
        }

        return parts;
    }
};
