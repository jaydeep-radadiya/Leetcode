// carry must be either 0 or 1 because the largest possible 
// sum of two digits (including the carry) is 9 + 9 + 1 = 19

// tc : O(max(m,n)) sc : O(max(m,n))
// space complexity bcoz we create new linkedlist
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *curr = ans;
        int sum = 0;
        int c = 0;
        
        while(l1!=NULL || l2!=NULL){
            sum = c;
            if(l1!=NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            c = sum/10;
            sum = sum%10;
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        if(c>0){ // add the carry
            curr->next = new ListNode(c);
        }
        return ans->next;
    }
};