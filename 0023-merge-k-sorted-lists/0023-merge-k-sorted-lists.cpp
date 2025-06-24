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
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        if(!l2) return l1;
        if(!l1) return l2;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        while(temp1 && temp2) {
            if(temp1 -> val < temp2 -> val) {
                if(head) {
                    curr -> next = temp1;
                    curr = temp1;
                }
                else{
                    head = temp1;
                    curr = temp1;
                }
                temp1 = temp1 -> next;
            }
            else{
                if(head) {
                    curr -> next = temp2;
                    curr = temp2;
                }
                else{
                    head = temp2;
                    curr = temp2;
                }
                temp2 = temp2 -> next;
            }
        }

        if(temp1) {
            curr -> next = temp1;
            // return head;
        }

        if(temp2) {
            curr -> next = temp2;
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        ListNode* head = lists[0];
        for(int i = 1; i < lists.size(); i++) {
            head = mergeList(head, lists[i]);
        }

        return head;
    }
};