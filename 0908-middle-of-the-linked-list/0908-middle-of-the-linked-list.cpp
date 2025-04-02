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
    ListNode* middleNode(ListNode* head) {
        // ListNode* ptr = head;
        // int count = 0;
        // while(ptr != nullptr){
        //     ptr = ptr -> next;
        //     count++;
        // }
        // ptr = head;

        // count = (count / 2) + 1;

        // for(int i = 0; i < count - 1; i++){
        //     ptr = ptr -> next;
        // }
        // // head = ptr;
        // return ptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        return slow;
    }
};