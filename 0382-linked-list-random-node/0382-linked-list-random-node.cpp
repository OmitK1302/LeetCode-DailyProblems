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
    vector<int>vec;
    Solution(ListNode* head) {
        ListNode* ptr = head;
        while(ptr) {
            vec.push_back(ptr -> val);
            ptr = ptr -> next;
        }
    }
    
    int getRandom() {
        // int temp = vec[i];
        // i = (i + 1) % vec.size();
        // return temp; 
        int sz = vec.size();
        int randomVal = rand() % sz;

        return vec[randomVal];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */