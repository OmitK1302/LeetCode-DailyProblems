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

    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr || head -> next == nullptr){
            return head;
        }
        int len = 0;
        ListNode *ptr = head;
        while(ptr -> next != nullptr){
            ptr = ptr -> next;
            len++;
        }
        len++;
        if(k >= len) k = k % len;
        int toRotate = len - k -1;
        ListNode* newPtr = head;
        for(int i = 0; i < toRotate; i++){
            newPtr = newPtr -> next;
        }

        ptr -> next = head;
        head = newPtr -> next;

        newPtr -> next = nullptr;

        return head;
    }
};