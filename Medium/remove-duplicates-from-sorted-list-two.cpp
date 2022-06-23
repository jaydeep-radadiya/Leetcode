class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        
        unordered_map<int,int> ump;
        ListNode *temp = head;
        while(temp!=NULL){
            ump[temp->val]++;
            temp = temp->next;
        }
        
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode *curr = dummy;
        
        while(curr!=NULL){
            ListNode *temp = curr->next;
            while(temp!=NULL && ump[temp->val]>=2)
                temp = temp->next;
            curr->next = temp;
            curr = curr->next;
        }
        return dummy->next;
    }
};