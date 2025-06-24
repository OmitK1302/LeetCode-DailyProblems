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
    ListNode* reverse(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        int cnt = 0;
        while(curr && cnt < k) {
            ListNode* nxt = nxt -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
            cnt++;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || !head) return head;
        ListNode* curr = head;
        int cnt = 1;
        ListNode* start = nullptr;
        ListNode* prev = nullptr;
        ListNode* end = nullptr;
        while(curr != nullptr) {
            if(cnt + 1 == left) {
                prev = curr;
            }
            if(cnt == left) {
                start = curr;
            }
            if(cnt == right) {
                end = curr;
            }

            if(!prev) {
                prev = curr;
            }
            curr = curr -> next;
            cnt++;
        }

        // return reverse(start, right - left + 1);
        ListNode* nxt = end -> next;
        // return nxt;

        if(left == 1) {
            head = reverse(start, right - left + 1);
        }
        else{
            prev -> next = reverse(start, right - left + 1);
        }

        start -> next = nxt;

        return head;
    }
};