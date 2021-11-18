// time limit exceed
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=1;i<=n;i++){
            bool present = false;
            for(int j=0;j<n;j++){
                if(nums[j]==i){
                    present = true;
                    break;
                }
            }
            if(present==false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// with extra space
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool> present(n+1,false);
        
        for(int i=0;i<n;i++){
            present[nums[i]] = true;
        }
        
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(present[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// negation of index
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]>0){
                nums[abs(nums[i])-1] *= -1;   
            }
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};