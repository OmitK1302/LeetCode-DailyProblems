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
    ListNode* reverseList(ListNode* head) {
        ListNode *ptr , *ptr1 , *ptr2 ;
        ptr = nullptr;
        ptr1 = head;
        if(head== nullptr || head -> next ==nullptr){
            return head;
        }

        ptr2 = head -> next;
        while(ptr1 != nullptr){
            ptr1 -> next = ptr;
            ptr = ptr1;
            ptr1 =ptr2;
            if(ptr2== nullptr){
                break;
            }
            ptr2 = ptr2 -> next;
        }
        head= ptr;
        return head;
    }

    void display(ListNode* head) {
        while(head != nullptr){
            cout<<head -> val<<" ";
            head = head -> next;
        }
    }

    bool isPalindrome(ListNode* head) {
        // ListNode* revhead = reverseList(head);

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* revHead = reverseList(slow -> next);
        

        // cout<<head->val<<" "<<head->next->val<<" "<<head -> next->next->val<<" "<head -> next->next->next->val;

        ListNode* ptr = head;
        // display(revHead);
        while(revHead != nullptr) {
            if(revHead -> val != ptr -> val) {
                return false;
            }

            revHead = revHead -> next;
            ptr = ptr -> next;
        }

        return true;
    }
};