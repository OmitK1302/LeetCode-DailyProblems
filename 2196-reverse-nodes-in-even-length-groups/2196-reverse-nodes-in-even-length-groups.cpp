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
//     ListNode* reverse(ListNode* head, int n) {
//         ListNode* prev = nullptr;
//         ListNode* curr = head;
//         while (n-- && curr) {
//             ListNode* nextTemp = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = nextTemp;
//         }
//         head->next = curr;
//         return prev;
//     }

//     ListNode* reverseEvenLengthGroups(ListNode* head) {
//         ListNode* prev = head;
//         ListNode* curr = head->next;
//         int groupSize = 2;

//         while (curr) {
//             ListNode* groupStart = curr;
//             int count = 0;
//             ListNode* temp = curr;

//             for (int i = 0; i < groupSize && temp; i++) {
//                 count++;
//                 temp = temp->next;
//             }

//             if (count % 2 == 0) {
//                 ListNode* reversedHead = reverse(groupStart, count);
//                 prev->next = reversedHead;

//                 for (int i = 0; i < count; i++) {
//                     prev = prev->next;
//                 }
//                 curr = prev->next;
//             } else {
//                 for (int i = 0; i < count; i++) {
//                     prev = curr;
//                     curr = curr->next;
//                 }
//             }

//             groupSize++;
//         }

//         return head;
//     }


    ListNode* reverse(ListNode* head, int k) {
        int cnt = 0;
        ListNode* curr = head;
        while(curr) {
            cnt++;
            curr = curr -> next;
        }

        bool rev = false;
        if(cnt <= k && cnt % 2 == 0) {
            rev = true;
        }

        if(cnt > k && k % 2 == 0) {
            rev = true;
        }

        curr = head;
        if(rev) {
            ListNode* prev = nullptr;
            cnt = 0;
            while(curr && cnt < k) {
                ListNode* nxt = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = nxt;
                cnt++;
            }

            if(curr) {
                head -> next = reverse(curr, k+1);
            }

            return prev;
        }
        // else{
            curr = head;
            cnt = 0;
            ListNode* prev = nullptr;
            while(curr && cnt < k) {
                prev = curr;
                curr = curr -> next;
                cnt++;
            }

            if(curr) {
                prev -> next = reverse(curr, k+1);
            }
            return head;
        // }
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        return reverse(head, 1);
    }
};