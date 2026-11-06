class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;

        ListNode* temp = head;
        ListNode* sec = head->next;

        while(sec != NULL) {
            if(temp->val == sec->val) {
                temp->next = sec->next;
                sec = temp->next;
            }
            else {
                temp = sec;
                sec = sec->next;
            }
        }

        return head;
    }
};