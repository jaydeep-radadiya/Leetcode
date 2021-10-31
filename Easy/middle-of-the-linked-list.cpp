class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *temp = head;
        int sz = 0;
        while(temp!=NULL){
            sz++;
            temp = temp->next;
        }
        
        temp = head;
        int half = sz/2;
        while(half--){
            temp = temp->next;
        }
        return temp;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};