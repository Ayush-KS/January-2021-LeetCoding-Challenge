// Remove Duplicates from Sorted List II

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode* temp = head;
        while(temp && temp -> val == head -> val)
            temp = temp -> next;
        if(temp == head -> next) {
            head -> next = deleteDuplicates(temp);
            return head;
        }
        return deleteDuplicates(temp);
    }
};