// brute force solution 
// tc : O(n^2) sc : O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j]){
                    cnt++;
                }
            }
            if(cnt>(n/2)){
                return nums[i];
            }
        }
        return -1;
    }
};

// tc : O(n*logn) sc : O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return nums[n/2];
    }
};

// tc : O(n) sc : O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> ump;
        
        for(int i=0;i<n;i++)
            ump[nums[i]]++;
        
        for(auto it : ump){
            if(it.second>(n/2)){
                return it.first;
            }
        }
        return -1;
    }
};

// moore's voting algorithm
// tc : O(n) sc : O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int idx_mjr = 0;
        int cnt = 1;
        
        for(int i=1;i<n;i++){
            if(nums[i]==nums[idx_mjr])
                cnt++;
            else
                cnt--;
            
            if(cnt==0){
                idx_mjr = i;
                cnt = 1;
            }
        }
        
        if(count(nums.begin(),nums.end(),nums[idx_mjr])>n/2)
            return nums[idx_mjr];
        else
            return -1;
    }
};