// find the middle of ll
// breack it down into two ll from middle
// reverse the second half of ll
// merge both of the two ll by reordering

// tc : O(n) sc : O(1)
class Solution {
public:
    ListNode* findMid(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode *head){
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
    
    void reorderList(ListNode* head) {
        ListNode *mid = findMid(head);
        ListNode *second = reverse(mid);
        ListNode *first = head;
        
        while(second->next!=NULL){
            ListNode *temp = first->next;
            first->next = second;
            first = temp;
            temp = second->next;
            second->next = first;
            second = temp;
        }
    }
};