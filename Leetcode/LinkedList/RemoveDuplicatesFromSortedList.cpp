class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr != NULL){
            while(curr->next != NULL and curr->val == curr->next->val){
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }
        return head;
    }
};
