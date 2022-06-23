class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or head->next==NULL or k==0)
            return head;
        
        int len = 0;
        ListNode *tail = head;
        while(++len && tail->next!=NULL){
            tail = tail->next;
        }
        
        k = k%len; // 6%3
        if(k==0) return head;
        k = (len-k)-1;
        
        ListNode *temp = head;
        while(k--){
            temp = temp->next;
        }
        ListNode *newHead = temp->next;
        temp->next = NULL;
        tail->next = head;
        return newHead;
    }
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or head->next==NULL or k==0)
            return head;
        
        int len = 0;
        ListNode *temp = head;
        while(++len && temp->next!=NULL){
            temp = temp->next;
        }
        
        temp->next = head;
        ListNode *curr = head;
        for(int i=1;i<len-(k%len);i++){
            curr = curr->next;
        }
        ListNode *newHead = curr->next;
        curr->next = NULL;
        return newHead;
    }
};