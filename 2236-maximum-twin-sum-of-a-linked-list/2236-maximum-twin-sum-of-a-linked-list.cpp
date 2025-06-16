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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        // head->next = curr;
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        int n = 0;
        while(temp) {
            n++;
            temp = temp -> next;
        }

        n = n / 2;
        temp = head;
        for(int i = 0; i < n; i++) {
            temp = temp -> next;
        }

        ListNode* head1 = reverse(temp);
        temp = head;

        int res = 0;
        while(head1) {
            res = max(res, head1 -> val + temp -> val);
            head1 = head1 -> next;
            temp = temp -> next;
        }

        return res;
    }
};