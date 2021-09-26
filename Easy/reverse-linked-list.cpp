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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        
        ListNode *p1,*p2,*p3;
        p1 = head;
        p2 = p1->next;
        p3 = p2->next;
        
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
};

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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        auto ans = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return ans;
    }
};