// tc : O(nlogn)
// two pointer method
class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int cnt = 0;
        int left = 0;
        int right = n-1;
        
        while(left<=right){
            if(arr[left]+arr[right]<=limit){
                cnt++;
                left++;
                right--;
            }
            else{
                cnt++;
                right--;
            }
        }
        return cnt;
    }
};