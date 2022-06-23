/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reverse(ListNode *head){
        // remember this
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
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return true;
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        while(fast!=NULL and fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        ListNode *p1 = head;
        ListNode *p2 = reverse(slow);
        
        while(p1!=NULL){
            if(p1->val!=p2->val){
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};