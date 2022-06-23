// tc : O(n) sc : O(n)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> ss;
        ListNode *temp = head;
        
        while(temp!=NULL){
            if(ss.find(temp)==ss.end()) ss.insert(temp);
            else return temp;
            temp = temp->next;
        }
        return NULL;
    }
};

// tc : O(n) sc : O(1)
class Solution {
public:
    ListNode* solve(ListNode *head,ListNode *slow){
        ListNode *entry = head;
        while(entry!=slow){
            slow = slow->next;
            entry = entry->next;
        }
        return slow;
    }
    
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL or head->next==NULL)
            return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                return solve(head,slow);
            }
        }
        return NULL;
    }
};