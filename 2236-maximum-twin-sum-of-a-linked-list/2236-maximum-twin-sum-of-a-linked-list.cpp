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
    int res = 0;
    ListNode* newHead;
    void helper(ListNode* head) {
        if(!head) return;
        helper(head -> next);

        res = max(res, newHead -> val + head -> val);
        newHead = newHead -> next;
    }
    int pairSum(ListNode* head) {
        newHead = head;
        helper(head);
        return res;
    }
};