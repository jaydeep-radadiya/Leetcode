// tc : O(nlogn)
class Solution {
public:
    int check(vector<int> &arr,int divisor){
        int n = arr.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += (arr[i]/divisor)+(arr[i]%divisor!=0);
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mx = *max_element(nums.begin(),nums.end());
        
        int left = 1;
        int right = mx;
        while(left<right){
            int mid = left+(right-left)/2;
            
            if(check(nums,mid)<=threshold)
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};