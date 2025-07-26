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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !(head -> next)) return head;

        ListNode* ptr = head -> next;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        while(ptr) {

            if(ptr1 -> val > ptr -> val) {
                ListNode* temp = ptr -> next;
                ptr2 -> next = temp;
                ptr -> next = ptr1;
                head = ptr;
                ptr1 = head;
                ptr = temp;
                continue;
            }

            while(ptr1 -> next != ptr && ptr1 -> next -> val <= ptr -> val) {
                ptr1 = ptr1 -> next;
            }
            if(ptr1 -> next != ptr) {
                ListNode* temp = ptr -> next;
                ptr2 -> next = temp;
                ptr -> next = ptr1 -> next;
                ptr1 -> next = ptr;
                ptr = temp;

            }
            else{
                ptr2 = ptr;
                ptr = ptr -> next;
            }

            ptr1 = head;
        }

        return head;
    }
};