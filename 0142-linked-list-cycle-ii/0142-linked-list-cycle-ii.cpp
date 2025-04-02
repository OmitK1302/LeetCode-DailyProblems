/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        // if(head == nullptr) return false;
        // ListNode* slow = head;
        // ListNode* fast = head;

        // // if(slow -> next == nullptr) return false;
        // // if(fast -> next -> next  == nullptr) return false;

        // // slow = slow -> next;
        // // fast = fast -> next -> next;

        // while(fast != nullptr && fast -> next != nullptr){
        //     slow = slow -> next;
        //     fast = fast -> next -> next;
        //     if(slow == fast) return true;
        // }

        // return false;
    

        unordered_map<ListNode*, int>listMap;

        ListNode* ptr = head;
        while(ptr != nullptr){
            if(listMap[ptr] == 1){
                return ptr;
            }
            listMap[ptr] = 1;
            ptr = ptr -> next;
        }

        return nullptr; 
    }
};