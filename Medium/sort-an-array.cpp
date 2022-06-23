class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums;
    }
};

// using heap property
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> maxh;
        
        for(int i=0;i<n;i++){
            maxh.push(nums[i]);    
        }
        for(int i=n-1;i>=0;i--){
            nums[i] = maxh.top();
            maxh.pop();
        }
        return nums;
    }
};