class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(slow!=NULL){
            while(fast!=NULL and slow->val==fast->val){
                fast = fast->next;
            }
            slow->next = fast;
            slow = slow->next;
            if(fast!=NULL)
                fast = fast->next;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        head->next = deleteDuplicates(head->next);
        return head->val == head->next->val ? head->next : head;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head;
        while(curr!=NULL){
            while(curr->next!=NULL and curr->val==curr->next->val){
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head;
        while(curr!=NULL){
            ListNode *temp = curr->next;
            while(temp!=NULL && curr->val==temp->val){
                temp = temp->next;
            }
            curr->next = temp;
            curr = curr->next;
        }
        return head;
    }
};