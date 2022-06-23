class Solution {
private:
    ListNode *reverse(ListNode *head){
        if(head==NULL or head->next==NULL)
            return head;
        
        ListNode *p1 = head;
        ListNode *p2 = p1->next;
        ListNode *p3 = p2->next;
        p1->next = NULL;
        p2->next = p1;
        
        while(p3!=NULL){
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
            p2->next = p1;
        }
        head = p2;
        return head;
    }
    
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *p1 = head;
        ListNode *p2 = reverse(slow);
        
        int mx_sum = INT_MIN;
        while(p2!=NULL){
            mx_sum = max(mx_sum,p1->val+p2->val);
            p1 = p1->next;
            p2 = p2->next;
        }
        return mx_sum;
    }
};