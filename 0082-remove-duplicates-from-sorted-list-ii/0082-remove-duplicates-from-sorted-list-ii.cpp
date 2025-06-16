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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr && curr -> next) {
            int currVal = curr -> val;
            ListNode* temp = curr -> next;
            while(temp && temp -> val == currVal) {
                temp = temp -> next;
            }

            if(curr -> next == temp) {
                prev = curr;
                curr = curr -> next;
            }
            else{
                if(!prev) {
                    head = temp;
                    curr = temp;
                }
                else{
                    prev -> next = temp;
                    curr = temp;
                }
            }
        }

        return head;
    }
};