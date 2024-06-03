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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head -> next == nullptr && n == 1){
            head = nullptr;
            return head;
        }
        int count = 0;
        ListNode* ptr = head;
        while(ptr != nullptr){
            ptr = ptr -> next;
            count++;
        }
        if(n == count){
            head = head -> next;
            return head;
        }
        ptr = head;
        for(int i = 0; i < (count - n -1); i++){
            ptr = ptr -> next;
        }

        if(ptr -> next == nullptr){
            ptr = nullptr;
            return head;
        }
        ptr -> next = ptr -> next -> next;

        return head;
    }
};