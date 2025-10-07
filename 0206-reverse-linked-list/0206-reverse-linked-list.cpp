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
    ListNode* newHead = nullptr;
    ListNode* reverse(ListNode* head) {
        if(!head) return nullptr;

        if(!head -> next) {
            newHead = head;
            return head;
        }

        ListNode* temp = reverse(head -> next);
        temp -> next = head;
        head -> next = nullptr;

        return head;
    }
public:
    ListNode* reverseList(ListNode* head) {
        reverse(head);
        return newHead;
    }
};