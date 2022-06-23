class Solution {
private:
    vector<int> arr;
    
public:
    Solution(ListNode* head) {
        while(head!=NULL){
            arr.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        int n = arr.size();
        int idx = rand()%n;
        return arr[idx];
    }
};