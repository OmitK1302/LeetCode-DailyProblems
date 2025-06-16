class Solution {
public:
    ListNode* reverse(ListNode* head, int n) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (n-- && curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        head->next = curr;
        return prev;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        int groupSize = 2;

        while (curr) {
            ListNode* groupStart = curr;
            int count = 0;
            ListNode* temp = curr;

            for (int i = 0; i < groupSize && temp; i++) {
                count++;
                temp = temp->next;
            }

            if (count % 2 == 0) {
                ListNode* reversedHead = reverse(groupStart, count);
                prev->next = reversedHead;

                for (int i = 0; i < count; i++) {
                    prev = prev->next;
                }
                curr = prev->next;
            } else {
                for (int i = 0; i < count; i++) {
                    prev = curr;
                    curr = curr->next;
                }
            }

            groupSize++;
        }

        return head;
    }
};
