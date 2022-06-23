// gfg's test case not strong as leetcode

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        
        while(head!=NULL and head->val==val)
            head = head->next;
        
        ListNode *curr = head;
        ListNode *prev = head;
        while(curr!=NULL){
            if(curr->val==val){
                ListNode *temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete temp;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        head->next = removeElements(head->next,val);
        return head->val==val ? head->next : head;
    }
};