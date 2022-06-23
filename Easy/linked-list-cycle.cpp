class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> ss;
        while(head!=NULL){
            if(ss.find(head)==ss.end()){
                ss.insert(head);
            }
            else{
                return true;
            }
            head = head->next;
        }
        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};