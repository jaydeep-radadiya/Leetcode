class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *temp = head;
        while(temp!=NULL){
            temp = temp->next;
            len++;
        }
        
        if(len==n){
            head = head->next;
            return head;
        }
        
        ListNode *ptr = head;
        n = len-n-1;
        while(n--){
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
        return head;
    }
};