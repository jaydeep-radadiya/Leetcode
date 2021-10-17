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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL)
            return head;
        
        ListNode *p1 = head;
        ListNode *l1 = new ListNode(0);
        ListNode *l2 = new ListNode(0);
        ListNode *h1 = l1;
        ListNode *h2 = l2;
        
        while(p1!=NULL){
            if(p1->val<x){
                l1->next = p1;
                l1 = l1->next;
            }
            else{
                l2->next = p1;
                l2 = l2->next;
            }
            p1 = p1->next;
        }
        l2->next = NULL; // remember this
        l1->next = h2->next;
        return h1->next;
    }
};