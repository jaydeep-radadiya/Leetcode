// brute force
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]>2LL*nums[j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// based on modified binary search
class Solution {
public:
    int merge(vector<int> &nums,int left,int mid,int right){
        int cnt = 0;
        int j = mid+1;
        for(int i=left;i<=mid;i++){
            while(j<=right && nums[i]>2LL*nums[j]){
                j++;
            }
            cnt += (j-(mid+1));
        }

        j = mid+1;
        int i = left;
        vector<int> temp;
        while(i<=mid && j<=right){
            if(nums[i]<=nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        } 
        while(i<=mid) temp.push_back(nums[i++]);
        while(j<=right) temp.push_back(nums[j++]);

        for(int i=left;i<=right;i++){
            nums[i] = temp[i-left];
        }
        return cnt;
    }

    int mergesort(vector<int> &nums,int left,int right){
        if(left>=right) return 0;
        int mid = left+(right-left)/2;
        int inv = mergesort(nums,left,mid);
        inv += mergesort(nums,mid+1,right);
        inv += merge(nums,left,mid,right);
        return inv;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergesort(nums,0,n-1);
    }
};