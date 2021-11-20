// first method
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for(int ele : nums){
            ans = ans^ele;
        }
        return ans;
    }
};

// second method
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> ump;
        
        for(int i=0;i<n;i++){
            ump[nums[i]]++;    
        }
        
        for(auto it=ump.begin();it!=ump.end();it++){
            if(it->second==1){
                return it->first;
            }
        }
        return -1;
    }
};

// third method binary search
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-2;
        
        while(left<=right){
            int mid = left+(right-left)/2;
            
            // if mid is left side of that val then this condition should be satisfy
            if(nums[mid]==nums[mid^1])
                left = mid+1; // left part is valid
            else
                right = mid-1;
        }
        return nums[left];
    }
};

// using unordered set
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_set<int> ss;
        
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            ss.insert(nums[i]);
        }
        return 2*accumulate(ss.begin(),ss.end(),0)-sum;
    }
};

// brute force solution
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(nums[j]==nums[i]){
                    cnt++;
                }
            }
            if(cnt==1){
                return nums[i];
            }
        }
        return -1;
    }
};

// linear search
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;){
            if(nums[i]==nums[i-1])
                i = i+2;
            else
                return nums[i-1];
        }
        return nums[n-1];
    }
};