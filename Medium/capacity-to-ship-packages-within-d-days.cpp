// binary search on answer
// this problem also available in gfg
class Solution {
private:
    bool is_valid(vector<int> &arr,int n,int mid,int days){
        int sum = 0;
        int cnt = 1;
        for(int i=0;i<n;i++){
            if(sum+arr[i]>mid){
                sum = 0;
                cnt++;
            }
            sum += arr[i];
        }
        if(cnt<=days) return true;
        else return false;
    }
    
public:
    int shipWithinDays(vector<int>& arr, int days) {
        int n = arr.size();
        int left = *max_element(arr.begin(),arr.end());
        int right = accumulate(arr.begin(),arr.end(),0);
        int res = left;
        
        while(left<=right){
            int mid = left+(right-left)/2;
            
            // minimise the maximum weight capacity of boat
            if(is_valid(arr,n,mid,days)){
                res = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return res;
    }
};