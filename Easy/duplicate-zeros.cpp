// tc : O(n^2) sc : O(1)
class Solution {
public:
    void duplicateZeros(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                for(int j=n-1;j>i;j--){
                    nums[j] = nums[j-1];
                }
                i++;
            }
        }
    }
};

// tc : O(n) cs : O(1)
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int cnt = count(arr.begin(),arr.end(),0);
        
        int j = cnt+n;
        for(int i=n-1;i>=0;i--){
            if(--j<n)
                arr[j] = arr[i];
            if(arr[i]==0 && --j<n)
                arr[j] = 0;
        }
    }
};