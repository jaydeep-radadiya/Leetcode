// first method
class Solution {
public:
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
    
    int getVal(ListNode *head){
        ListNode *temp = head;
        int p = 1;
        int sum = 0;
        while(temp!=NULL){
            sum += (p*temp->val);
            p = 2*p;
            temp = temp->next;
        }
        return sum;
    }
    
    int getDecimalValue(ListNode* head) {
        head = reverse(head);
        return getVal(head);
    }
};

// second method
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int sz = 0;
        ListNode *temp = head;
        while(temp!=NULL){
            sz++;
            temp = temp->next;
        }
        
        int sum = 0;
        temp = head;
        while(temp!=NULL){
            sum += temp->val*pow(2,--sz);
            temp = temp->next;
        }
        return sum;
    }
};

// third method
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if(head==NULL) return 0;
        
        int sum = head->val;
        ListNode *temp = head->next;
        while(temp!=NULL){
            sum = sum*2+temp->val;
            temp = temp->next;
        }
        return sum;
    }
};