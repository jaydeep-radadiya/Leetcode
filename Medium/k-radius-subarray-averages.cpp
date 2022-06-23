class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        
        for(int i=k;i<n-k;i++){
            int sum = 0;
            for(int j=i-k;j<=i+k;j++)
                sum += nums[j];
            ans[i] = (sum)/(2*k+1);
        }
        return ans;
    }
};

// based on sliding window
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        vector<int> temp;
        long long sum = 0;
        
        int i = 0;
        int j = 0;
        while(j<n){
            sum += nums[j];
            if(j-i+1<2*k+1){
                j++;
            }
            else if(j-i+1==2*k+1){
                int val = (sum)/(2*k+1);
                temp.push_back(val);
                sum -= nums[i];
                i++;
                j++;
            }
        }
        
        for(int i=k;i<n-k;i++){
            ans[i] = temp[i-k];   
        }
        return ans;
    }
};

// without temp array
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        long long sum = 0;
        int x = k;
        
        int i = 0;
        int j = 0;
        while(j<n){
            sum += nums[j];
            if(j-i+1<2*k+1){
                j++;
            }
            else if(j-i+1==2*k+1){
                ans[x++] = (sum)/(2*k+1);
                sum -= nums[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};