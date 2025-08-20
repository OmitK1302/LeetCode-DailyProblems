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

//  #include<bits/stdc++.h>
class Solution {
public:
    ListNode* llReverse(ListNode* head) {
        ListNode* ptr = head;
        ListNode* prev = nullptr;

        while(ptr) {
            ListNode* nxt = ptr -> next;
            ptr -> next = prev;
            prev = ptr;
            ptr = nxt;
        }

        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        head = llReverse(head);


        stack<int>st;
        ListNode* ptr = head;
        vector<int>res;
        while(ptr) {
            while(!st.empty() && st.top() <= ptr -> val) {
                st.pop();
            }

            if(st.empty()) {
                res.push_back(0);
                st.push(ptr -> val);
            }
            else{
                res.push_back(st.top());
                st.push(ptr -> val);
            }

            ptr = ptr -> next;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};