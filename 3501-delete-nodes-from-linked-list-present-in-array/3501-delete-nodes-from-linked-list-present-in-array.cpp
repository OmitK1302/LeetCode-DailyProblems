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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, bool>map;
        for(int& num : nums) {
            map[num] = true;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr) {
            if(map[curr -> val]) {
                if(!prev) {
                    curr = curr -> next;
                    head = curr;
                }
                else{
                    prev -> next = curr -> next;
                    curr = prev -> next;
                }
            }
            else{
                prev = curr;
                curr = curr -> next;
            }
        }

        return head;
    }
};