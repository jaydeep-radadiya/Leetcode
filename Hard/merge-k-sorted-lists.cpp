class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        int n = lists.size();
        
        for(int i=0;i<n;i++){
            ListNode *temp = lists[i];
            while(temp!=NULL){
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }
        
        sort(arr.begin(),arr.end());
        ListNode *res = new ListNode(-1);
        ListNode *temp = res;
        
        for(int ele : arr){
            ListNode *newnode = new ListNode(ele);
            temp->next = newnode;
            temp = temp->next;
        }
        return res->next;
    }
};

class comp {
public:
    bool operator()(ListNode *a,ListNode *b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp> minh;
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
                minh.push(lists[i]);
            }
        }
        
        while(minh.size()>0){
            ListNode *ptr = minh.top();
            minh.pop();
            temp->next = ptr;
            temp = temp->next;
            if(ptr->next!=NULL){
                minh.push(ptr->next);
            }
        }
        return dummy->next;
    }
};