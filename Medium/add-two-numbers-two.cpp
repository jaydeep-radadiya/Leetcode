// solved by reversing the list
// follow up : can you do without reversing the input list
class Solution {
public:
    ListNode* reverseList(ListNode *head){
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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        ListNode *ans = new ListNode(0);
        ListNode *curr = ans;
        int c = 0;
        
        while(l1!=NULL or l2!=NULL){
            int sum = c;
            if(l1!=NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            c = sum/10;
        }
        if(c>0){
            curr->next = new ListNode(c);
        }
        return reverseList(ans->next);
    }
};

// without reversing the input list
class Solution {
public:
    ListNode* reverseList(ListNode *head){
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
    
    void fillList(ListNode *t,stack<int> &st){
        while(t!=NULL){
            st.push(t->val);
            t = t->next;
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        fillList(l1,st1);
        stack<int> st2;
        fillList(l2,st2);
        
        int n1 = st1.size();
        int n2 = st2.size();
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        int c = 0;
        
        while(n1>0 || n2>0){
            int sum = c;
            if(n1>0){
                sum += st1.top();
                st1.pop();
                n1--;
            }
            if(n2>0){
                sum += st2.top();
                st2.pop();
                n2--;
            }
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            c = sum/10;
        }
        if(c>0){
            curr->next = new ListNode(c);
        }
        return reverseList(ans->next);
    }
};

// without reversing output list
class Solution {
public:
    void fillList(ListNode *t,stack<int> &st){
        while(t!=NULL){
            st.push(t->val);
            t = t->next;
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        fillList(l1,st1);
        stack<int> st2;
        fillList(l2,st2);
        
        int n1 = st1.size();
        int n2 = st2.size();
        ListNode* ans = NULL;
        int c = 0;
        
        while(n1>0 || n2>0){
            int sum = c;
            if(n1>0){
                sum += st1.top();
                st1.pop();
                n1--;
            }
            if(n2>0){
                sum += st2.top();
                st2.pop();
                n2--;
            }
            ListNode *temp = new ListNode(sum%10);
            temp->next = ans;
            ans = temp;
            c = sum/10;
        }
        if(c>0){
            ListNode *temp = new ListNode(c);
            temp->next = ans;
            ans = temp;
        }
        return ans;
    }
};