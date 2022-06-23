class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++){
            cnt += ump[nums[i]]++; // each new element a there will be more count[a] pairs
        }
        return cnt;
    }
};