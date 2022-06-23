/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode temp = headA;
        int a = 0;
        while(temp!=null){
            temp = temp.next;
            a++;
        }
        
        temp = headB;
        int b = 0;
        while(temp!=null){
            temp = temp.next;
            b++;
        }
        
        int diff = Math.abs(b-a);
        if(a>b){
            while(diff>0){
                headA = headA.next;
                diff = diff-1;
            }
        }
        else{
            while(diff>0){
                headB = headB.next;
                diff = diff-1;
            }
        }
        
        while(headA!=headB){
            headA = headA.next;
            headB = headB.next;
        }
        
        if(headA==null && headB==null)
            return null;
        else
            return headA;
    }
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ans;
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        
        if(headA==NULL or headB==NULL)
            return ans;
        
        while(p1!=p2){
            if(p1==NULL or p2==NULL){
                if(p1==NULL)
                    p1 = headB;
                else
                    p2 = headA;
            }
            else{
                p1 = p1->next;
                p2 = p2->next;   
            }
        }
        
        if(p1!=NULL and p2!=NULL)
            return p1;
        else
            return ans;
    }
};