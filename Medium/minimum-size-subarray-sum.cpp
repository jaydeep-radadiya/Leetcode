// tc : O(nlogn) binary search with sliding window
// binary search on answer
// striver method
class Solution {
public:
    bool blackbox(vector<int> &arr,int n,int target,int k){
        int mx = INT_MIN;
        int sum = 0;
        int i = 0;
        int j = 0;
        
        while(j<n){
            sum += arr[j];
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                mx = max(mx,sum);
                sum -= arr[i];
                i++;
                j++;
            }
        }
        return mx>=target;
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 1;
        int right = n+1;
        bool ans_possible = false;
        while(left<right){
            int mid = left+(right-left)/2;
            if(blackbox(nums,n,target,mid)==true){
                ans_possible = true;
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        if(ans_possible==true) return left;
        else return 0;
    }
};

/*
brute force
run loop from 1 to arr size (min to max window size)
find min window size for which sum >= target
*/