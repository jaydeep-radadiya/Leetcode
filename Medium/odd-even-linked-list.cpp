// tc : O(n) sc : O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = new ListNode(0);
        ListNode *even = new ListNode(0);
        ListNode *oddhead = odd;
        ListNode *evenhead = even;
        
        ListNode *temp = head;
        while(temp!=NULL){
            odd->next = temp;
            odd = odd->next;
            temp = temp->next;
            if(temp!=NULL){
                even->next = temp;
                even = even->next;
                temp = temp->next;
            }
        }
        even->next = NULL;
        odd->next = evenhead->next;
        return oddhead->next;
    }
};