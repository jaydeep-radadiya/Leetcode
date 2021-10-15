// first method
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        
        return ans;
    }
};

// second method
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> ump;
        
        for(int i=0;i<n;i++){
            if(ump.find(target-nums[i])!=ump.end()){
                ans.push_back(ump[target-nums[i]]);
                ans.push_back(i);
            }
            ump[nums[i]] = i;
        }
        
        return ans;
    }
};

// third method
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        
        int left = 0;
        int right = n-1;
        while(left<right){
            int v1 = arr[left].first;
            int v2 = arr[right].first;
            
            if(v1+v2==target){
                return {arr[left].second,arr[right].second};
            }
            else if(v1+v2>target){
                right--;
            }
            else if(v1+v2<target){
                left++;
            }
        }
        
        return {-1,-1};
    }
};