// fraz solution
// tc : O(n) sc : O(n/k)
class Solution {
public:
    void reverse(ListNode *start,ListNode *end){
        if(start==NULL or start->next==NULL) return;
        
        ListNode *p1 = start;
        ListNode *p2 = p1->next;
        ListNode *p3 = p2->next;
        p1->next = NULL;
        p2->next = p1;
        
        // think about this condition
        while(p2!=end){
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
            p2->next = p1;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL or head->next==NULL or k==1)
            return head;
        
        ListNode *start = head;
        ListNode *end = head;
        int move = k-1;

        while(move--){
            end = end->next;
            if(end==NULL) return head;
        }
        ListNode *newhead = reverseKGroup(end->next,k);
        reverse(start,end);
        start->next = newhead;
        return end;
    }
};

// fraz sc : O(1) tc : O(n)
class Solution {
public:
    void reverse(ListNode *start,ListNode *end){
        if(start==NULL or start->next==NULL) return;
        
        ListNode *p1 = start;
        ListNode *p2 = p1->next;
        ListNode *p3 = p2->next;
        p1->next = NULL;
        p2->next = p1;
        
        // think about this condition
        while(p2!=end){
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
            p2->next = p1;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL or head->next==NULL or k==1)
            return head;
        
        ListNode *dummy = new ListNode(-1);
        ListNode *beforeStart = dummy;
        dummy->next = head;
        ListNode *end = head;
        int i = 0;
        
        while(end!=NULL){
            i++;
            if(i%k==0){
                ListNode *nextOfEnd = end->next;
                ListNode *start = beforeStart->next;
                reverse(start,end);
                beforeStart->next = end;
                start->next = nextOfEnd;
                beforeStart = start;
                end = nextOfEnd;
            }
            else{
                end = end->next;
            }
        }
        return dummy->next;
    }
};

// striver solution
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL or k==1)
            return head;
        
        ListNode *pre, *curr, *nxt;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        pre = curr = nxt = dummy;
        
        // cnt the size of ll
        int cnt = 0;
        curr = head;
        while(curr!=NULL){
            cnt++;
            curr = curr->next;
        }
        
        while(cnt>=k){
            // set the curr & nxt for group
            curr = pre->next;
            nxt = curr->next;
            // reverse the k-1 edges
            for(int i=1;i<k;i++){
                curr->next = nxt->next;
                nxt->next = pre->next;
                pre->next = nxt;
                nxt = curr->next;
            }
            pre = curr;
            cnt -= k;
        }
        return dummy->next;
    }
};