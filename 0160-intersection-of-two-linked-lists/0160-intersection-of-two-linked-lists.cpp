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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;

        unordered_map<ListNode*, int>map;

        while(ptr1 != nullptr || ptr2 != nullptr) {
            if(ptr1 != nullptr) {
                if(map[ptr1] == 1) return ptr1;
                map[ptr1] = 1;
                ptr1 = ptr1 -> next;
            }
            if(ptr2 != nullptr) {
                if(map[ptr2] == 1) return ptr2;
                map[ptr2] = 1;
                ptr2 = ptr2 -> next;
            }
        }

        return nullptr;
    }
};